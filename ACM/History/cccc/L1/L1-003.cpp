#include <iostream>
#include <string>
int main()
{
    int i;
    int group[10] = {0};
    std::string num;
    std::cin >> num;
    for (auto c : num)
        ++group[c - '0'];
    for (i = 0; i < 10; ++i)
        if (group[i])
            std::cout << i << ":" << group[i] << std::endl;
    return 0;
}