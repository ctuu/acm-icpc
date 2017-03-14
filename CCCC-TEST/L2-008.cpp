#include <iostream>
#include <string>
#include <array>
#define sch '#'
#define min(a,b) ((a<b)?a:b)
int main()
{
    std::string word;
    std::cin >> word;
    for (auto i = word.begin(); i <= word.end(); i += 2)
        word.insert(i, sch);
    return 0;
}