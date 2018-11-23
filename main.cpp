
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "easy-encryption/encrypt.h"

std::string ExtractString(std::string source, std::string start, std::string end)
{
	std::size_t startIndex = source.find(start);

	if (startIndex == std::string::npos)
	{
		return "";
	}

	startIndex += start.length();
	std::string::size_type endIndex = source.find(end, startIndex);

	return source.substr(startIndex, endIndex - startIndex);
}

bool replace(std::string& str, const std::string& from, const std::string& to)
{
	size_t start_pos = str.find(from);
	if (start_pos == std::string::npos)
		return false;
	str.replace(start_pos, from.length(), to);
	return true;
}

std::string str_random(int lenght, int mode = 3)
{
	srand(GetTickCount());
	Sleep(10);

	std::string str;

	if (mode == 1 || mode == 2 || mode == 3)
	{
		if (mode == 1) // NUMBER ONLY
			str = "0123456789";
		if (mode == 2) // LETTER ONLY
			str = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		if (mode == 3) // NUMBER & LETTER
			str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	}
	else
		str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	std::string newstr;
	int pos;
	while (newstr.size() != lenght)
	{
		pos = ((rand() % (str.size() - 1)));
		newstr += str.substr(pos, 1);
	}

	return newstr;
}

int main()
{
	printf("HooHoo\nWith easy-encryption\n");

	int mode_rdm_pass = 3;
	int size_rdm_pass = 12;
	std::string file_in = "";
	std::string file_out = "";

	// SELECT
	printf("\nMODE '1' : Number\nMODE '2' : Letter\nMODE '3' : Number & Letter\nSelect MODE RANDOM PASS: ");
	std::cin >> mode_rdm_pass;
	printf("Size RANDOM PASS: ");
	std::cin >> size_rdm_pass;
	printf("Path Ffile_in input: ");
	std::cin >> file_in;
	printf("Path Ffile_in output: ");
	std::cin >> file_out;

	std::ofstream Ffile_out(file_out, std::ios::app);
	std::ifstream Ffile_in(file_in);

	if (!Ffile_out.is_open())
	{
		printf("ERROR FILE open %s\n", file_out.c_str());
		getchar();
		return 2;
	}

	if (Ffile_in.is_open())
	{
		std::string line;
		std::string part_line;
		while (getline(Ffile_in, line))
		{
			part_line = ExtractString(line, "\"", "\"");
			if (part_line != "")
			{
				std::string rdm_pass = str_random(size_rdm_pass, mode_rdm_pass);
				std::string new_str = "decrypt(\"" + encrypt(part_line, rdm_pass) +"\", \"" + rdm_pass + "\")";
				replace(line, "\"" + part_line + "\"", new_str);
				line += " // STRING(" + part_line + ") PASS(" + rdm_pass + ")";
			}
			Ffile_out << line << "\n";
		}
		Ffile_out.close();
		Ffile_in.close();
	}

	printf("\nSuccess\n");

	getchar();
	return 0;
}