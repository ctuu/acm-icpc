#include <iostream>
#include <string>
#include <cctype>
int main()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;
    if (s1.size() != s2.size())
        std::cout << "1";
    else if (s1 == s2)
        std::cout << "2";
    else
    {
        for (auto &c : s1)
            c = toupper(c);
        for (auto &c : s2)
            c = toupper(c);
        if (s1 == s2)
            std::cout << "3";
        else
            std::cout << "4";
    }
    return 0;
}