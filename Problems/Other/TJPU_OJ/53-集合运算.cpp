#include <iostream>
#include <set>
int main()
{
    int i, j, size;
    std::set<int> s1, s2, s3;
    std::cin >> i;
    while (i--)
    {
        std::cin >> j;
        s1.insert(j);
    }
    std::cin >> i;
    while (i--)
    {
        std::cin >> j;
        s2.insert(j);
    }
    for (auto i : s1)
        if (s2.count(i))
            std::cout << i << " ";
    std::cout << std::endl;
    for (auto i : s1)
        s3.insert(i);
    for (auto i : s2)
        s3.insert(i);
    for (auto i : s3)
        std::cout << i << " ";
    std::cout << std::endl;
    for (auto i : s1)
        if (!s2.count(i))
            std::cout << i << " ";
    return 0;
}