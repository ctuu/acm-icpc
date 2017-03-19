#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
std::vector<int> heap;
int sfind(int i);
int main()
{
    int n, m, num;
    std::cin >> n >> m;
    heap.resize(n);
    for (auto &i : heap)
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
            std::cin >> j;
            if ((sfind(i) + 1) / 2 == (sfind(j) + 1) / 2)
                flag = 1;
            std::cin >> word >> word;
        }
        else
        {
            std::cin >> word;
            if (word == "a")
            {
                std::cin >> word >> word >> j;
                if ((sfind(i) - 1) / 2 == sfind(j))
                    flag = 1;
            }
            else
            {
                std::cin >> word;
                if (word == "root")
                {
                    if (sfind(i) == heap[0])
                        flag = 1;
                }
                else
                {
                    std::cin >> word >> j;
                    if (sfind(i) == (sfind(j) + 1) / 2)
                        flag = 1;
                }
            }
        }
        if (flag)
            std::cout << "T" << std::endl;
        else
            std::cout << "F" << std::endl;
    }
    return 0;
}
int sfind(int i)
{
    return find(heap.begin(), heap.end(), i) - heap.begin();
}