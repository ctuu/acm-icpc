#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
std::vector <int> heap;
int sfind(int i);
int main()
{
    int n, m, num;
    std::cin >> n >> m;
    heap.resize(n);
    for (auto& i : heap)
        std::cin >> i;
    std::make_heap(heap.begin(), heap.end(), std::greater<int>());
    while (m--)
    {
        bool flag = 0;
        int i, j;
        std::string word;
        std::cin >> i >> word;
        if (word == "and")
        {
            std::cout << "1";
            std::cin >> j;
            if (sfind(i) / 2 == sfind(j) / 2)
                flag = 1;
        }
        if (flag)
            std::cout << "T" << std::endl;
        else
            std::cout << "F" << std::endl;
        // std::cout << sfind(i);
    }
    return 0;
}
int sfind(int i)
{
    return find(heap.begin(), heap.end(), i) - heap.begin();
}