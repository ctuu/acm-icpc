#include <iostream>
#include <array>
#include <algorithm>
void dnc(auto it);
int main()
{
    std::array<int, 30> ino, pos;
    int n, i;
    std::cin >> n;
    for (i = 0; i < n; ++i)
        std::cin >> ino[i];
    for (i = 0; i < n; ++i)
        std::cin >> pos[i];
    return 0;
}