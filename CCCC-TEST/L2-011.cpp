#include <iostream>
#include <algorithm>
#include <queue>
#include <array>
std::array<int, 40> pre, ino;
int find(int be, int ran);
struct tree
{
    int be;
    int en;
    int ran;
};
int main()
{
    int n, i, mid, a, b;
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
    fte.ran = 0;
    tr.push(fte);
    do
    {
        fte = tr.front();
        if (i == 0)
            std::cout << " ";
        else
            i = 0;
        mid = find(fte.en, fte.ran);
        std::cout << ino[mid];
        if (fte.be < mid)
        {
            ste.be = fte.be;
            ste.en = mid - 1;
            ste.ran = n - (fte.ran - (mid - fte.en + 1));
            if (ste.be <= ste.en)
                tr.push(ste);
        }
        if (mid  < fte.en)
        {
            ste.be = mid + 1;
            ste.en = fte.en;
            ste.ran = fte.ran + 1;
            if (ste.be <= ste.en)
                tr.push(ste);
        }
        tr.pop();
    }
    while (!tr.empty());
    return 0;
}
int find(int en, int ran)
{
    int i, j;
    do
        for (i = 0; i <= en; ++i)
            if (ino[i] == pre[ran])
                return i;
    while (ran--);
    return -1;
}