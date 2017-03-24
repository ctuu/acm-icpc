#include <iostream>
#include <algorithm>
#include <array>
#include <queue>
#include <set>
struct human
{
    int f = -1;
    int m = -1;
    int sex = 0;
};
int main()
{
    int n;
    std::cin >> n;
    std::array<human, 100020> fami;
    while (n--)
    {
        int id, a, b;
        char c;
        std::cin >> id >> c >> a >> b;
        if (c == 'M')
            fami[id].sex = 1;
        else
            fami[id].sex = 0;
        fami[id].f = a;
        fami[a].sex = 1;
        fami[id].m = b;
        fami[b].sex = 0;
    }
    std::cin >> n;
    while (n--)
    {
        std::array<int, 100020> level;
        level.fill(0);
        int a, b;
        std::cin >> a >> b;
        std::queue<int> bfs;
        std::set<int> s;
        bfs.push(a);
        bfs.push(b);
        bool flag = 0;
        if (fami[a].sex == fami[b].sex)
        {
            std::cout << "Never Mind" << std::endl;
            continue;
        }
        while (!bfs.empty())
        {
            int te = bfs.front();
            bfs.pop();
            int sizes = s.size();
            s.insert(te);
            if (s.size() == sizes)
            {
                std::cout << "No" << std::endl;
                flag = 1;
                break;
            }
            if (level[te] < 4)
            {
                int i, j;
                i = fami[te].f;
                if (i > -1)
                {
                    level[i] = level[te] + 1;
                    bfs.push(i);
                }
                j = fami[te].m;
                if (j > -1)
                {
                level[j] = level[te] + 1;
                bfs.push(j);
                }
            }
        }
        if (flag == 0)
            std::cout << "Yes" << std::endl;
    }
    return 0;
}

