#include <iostream>
#include <algorithm>
#include <queue>
#include <array>
std::array<int, 40> pre, ino;
int find(int be, int sran);
struct tree
{
    int be;
    int en;
    int sran;
};
int main()
{
    int n, i, mid;
    std::cin >> n;
    for (i = 0; i < n; ++i)
        std::cin >> ino[i];
    for (i = 0; i < n; ++i)
        std::cin >> pre[i];
    std::queue<tree> tr;
    i = 1;
    tree fte, ste;
    fte.be = 0;
    fte.en = n - 1;
    fte.sran = 0;
    tr.push(fte);
    do
    {
        fte = tr.front();
        if (i == 0)
            std::cout << " ";
        else
            i = 0;
        mid = find(fte.en, fte.sran);
        std::cout << ino[mid];
        if (mid  < fte.en)
        {
            ste.be = mid + 1;
            ste.en = fte.en;
            ste.sran = fte.sran + mid - fte.be + 1;
            if (ste.be <= ste.en)
                tr.push(ste);
        }
        if (fte.be < mid)
        {
            ste.be = fte.be;
            ste.en = mid - 1;
            ste.sran = fte.sran + 1;
            if (ste.be <= ste.en)
                tr.push(ste);
        }
        tr.pop();
    }
    while (!tr.empty());
    return 0;
}
int find(int en, int sran)
{
    int i;
    for (i = en; i >= 0; --i)
        if (ino[i] == pre[sran])
            return i;
    return -1;
}