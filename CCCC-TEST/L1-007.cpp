#include <iostream>
#include <string>
#include <vector>
int main()
{
    int i;
    std::vector<std::string> gr{"ling", "yi", "er", "san", "si", "wu", "liu", "qi","ba","jiu"};
    std::string num;
    std::cin >> num;
    i = num.size() - 1;
    for (auto s:num)
    {
        if (s == '-')
        {
            std::cout << "fu ";
            --i;
            continue;
        }

        std::cout << gr[s-48];
        if (i--)
            std::cout << " ";
    }
    return 0;
}