#include <iostream>
#include <string>
int main()
{
    bool ch[128] = {0};
    std::string s1, s2;
    getline(std::cin, s1);
    getline(std::cin, s2);
    for (auto i : s2)
        ch[i] = 1;
    for (auto j : s1)
        if (ch[j] == 0)
            std::cout << j;
    return 0;
}