#include <iostream>
#include <algorithm>
#include <queue>
#include <array>
std::array<int, 40> pos, ino;
int find(int be, int ran);
struct tree
{
    int be;
    int en;
    int ran;
};
int main()
{
    int n, i, mid;
    std::cin >> n;
    for (i = 0; i < n; ++i)
        std::cin >> pos[i];
    for (i = 0; i < n; ++i)
        std::cin >> ino[i];
    std::queue<tree> tr;
    i = 1;
    tree fte, ste;
    fte.be = 0;
    fte.en = n - 1;
    fte.ran = n - 1;
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
            ste.ran = fte.ran - (fte.en - mid + 1);
            if (ste.be <= ste.en)
                tr.push(ste);
        }
        if (mid  < fte.en)
        {
            ste.be = mid + 1;
            ste.en = fte.en;
            ste.ran = fte.ran - 1;
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
    int i;
    for (i = 0; i <= en; ++i)
        if (ino[i] == pos[ran])
            return i;
    return -1;
}