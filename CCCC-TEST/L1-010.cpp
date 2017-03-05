#include <iostream>
#include <algorithm>
int main()
{
    int num[3];
    int i;
    for (auto& s : num)
        std::cin >> s;
    std::sort(num, num + 3);
    std::cout << num[0] << "->" << num[1] << "->" << num[2];
    return 0;
}