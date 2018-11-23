# HooHoo
Encode all strings (between double quotes) in file with easy-encryption (https://github.com/philipperemy/easy-encryption)

#### BEFORE
```cpp
// ALL STRINGS

std::string mysecretstring = "I don't know what to write in this file.";
std::string Heyerdahl = "Progress is man's ability to complicate simplicity.";
std::string Twain = "Good friends, good books and a sleepy conscience: this is the ideal life.";
std::string Enninful = "I take random inspiration from everywhere.";
std::string Dawkins = "Natural selection is anything but random.";
```
#### AFTER
```cpp
// ALL STRINGS
std::string mysecretstring = decrypt("Q6vrzQHcjbMk A3 6vRd4w1 bU2nBRmejf5 9 YnBuVei8Mf9 rs95==", "9o5hyZO0gKl4"); // STRING(I don't know what to write in this file.) PASS(9o5hyZO0gKl4)
std::string Heyerdahl = decrypt("SVDCmRmaiCX 9aGnzKijPCX W DwzuZPkrMT MvqzQElhfwcWaLs6vqehwMl9 HwBvYj", "9o5hyZO0gKl4"); // STRING(Progress is man's ability to complicate simplicity.) PASS(9o5hyZO0gKl4)
std::string Twain = decrypt("Gs7 L3fZaSIm1NPdx3f0 xvlx7H Ys8bGb2vO3zWu8r5Xrhx4izYYsJbWxIm1NL0AJfC9bIAx7jdu8v1XnYqO7TWY3f59rlmAH==", "0B9PXBPN9Gxb"); // STRING(Good friends, good books and a sleepy conscience: this is the ideal life.) PASS(0B9PXBPN9Gxb)
std::string Enninful = decrypt("5rm3OAtuEUJYoWCy2wBy8ANcnwuk4klE8vB3pWUwykVaV JLqB3o31UD", "nKWd1Paj7naR"); // STRING(I take random inspiration from everywhere.) PASS(nKWd1Paj7naR)
std::string Dawkins = decrypt("YsQp2nKObLOo42ILMtSWbag6f3XGMm6BdPuegsnGMOWwIQW7gs2V0i5=", "fglAZBbHajn0"); // STRING(Natural selection is anything but random.) PASS(fglAZBbHajn0)
```
