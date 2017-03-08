#include <iostream>
#include <cmath>
#include <array>
struct node
{
    int k;
    int next;
};
int main()
{
    int beg, n, i, j, lano, sbeg = -1;
    std::array <int, 1200> num = {-1};
    std::cin >> beg >> n;
    std::array<node, 100020> list;
    std::array<node, 100020> slt;
    for (i = 0; i < n; ++ i)
    {
        std::cin >> j >> list[j].k >> list[j].next;
        num[abs(list[i].k)] = 1;
    }
    for (i = beg; i != -1; lano = i,  i = list[i].next)
    {
        if (num[abs(list[i].k)])
        {
            list[lano].next = list[i].next;
            if (sbeg == -1)
            {
                slt[i].k = list[i].k;
                slt[i].next = -1;
                sbeg = i;
            }
            else
            {
                for (j = sbeg; slt[j].next != -1; j = slt[j].next);
                slt[j].next = i;
                slt[i].k = list[i].k;
                slt[i].next = -1;
            }
        }
    }
    for (i = beg; i != -1; i = list[i].next)
        std::cout << i << " " << list[i].k << " " << list[i].next << std::endl;
    for (i = sbeg; i != -1; i = slt[i].next)
        std::cout << i << " " << slt[i].k << " " << slt[i].next << std::endl;
    return 0;
}