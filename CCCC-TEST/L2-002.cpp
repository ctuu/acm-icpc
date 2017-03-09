#include <iostream>
#include <array>
#include <iomanip>
struct node
{
    int key;
    int next;
};
int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int beg, n, i, j, lano, sbeg = -1, sla = -1;
    std::array <int, 12000> num = {0};
    std::array<node, 100020> list;
    std::array<node, 100020> slt;
    std::cin >> beg >> n;
    for (i = 0; i < n; ++i)
    {
        std::cin >> j;
        std::cin >> list[j].key >> list[j].next;
    }
    for (i = beg; i != -1; lano = i,  i = list[i].next)
    {
        if (num[abs(list[i].key)] == 1)
        {
            list[lano].next = list[i].next;
            if (sbeg == -1)
                sbeg = i;
            else
                slt[sla].next = i;
            slt[i].key = list[i].key;
            slt[i].next = -1;
            sla = i;
            i = lano;
        }
        else
            num[abs(list[i].key)] = 1;
    }
    for (i = beg; i != -1; i = list[i].next)
    {
        std::cout << std::setw(5) << std::setfill('0') << i << " " << list[i].key << " ";
        if (list[i].next != -1)
            std::cout << std::setw(5) << std::setfill('0') << list[i].next << std::endl;
        else
            std::cout << "-1" << std::endl;
    }
    for (i = sbeg; i != -1; i = slt[i].next)
    {
        std::cout << std::setw(5) << std::setfill('0') << i << " " << slt[i].key << " ";
        if (slt[i].next != -1)
            std::cout << std::setw(5) << std::setfill('0') << slt[i].next << std::endl;
        else
            std::cout << "-1" << std::endl;
    }
    return 0;
}