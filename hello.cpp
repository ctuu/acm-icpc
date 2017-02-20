#include <iostream>
#include <array>
int main()
{
    std::array<int, 10> num;
    for (auto &r:num)
        std::cin >> r;
    for (auto &r:num)
    std::cout << r << " ";
    return 0;
}