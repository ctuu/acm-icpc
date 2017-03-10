#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
std::vector<int> ino, pos;
struct tree
{
    std::vector<int>::iterator ita;
    std::vector<int>::iterator itb;
    std::vector<int>::iterator itc;
};
int main()
{
    int n, i, j, a, b;
    std::cin >> n;
    for (i = 0; i < n; ++i)
    {
        std::cin >> j;
        pos.push_back(j);
    }
    for (i = 0; i < n; ++i)
    {
        std::cin >> j;
        ino.push_back(j);
    };
    std::queue<tree> tr;
    tree fte, ste;
    fte.ita = ino.begin();
    fte.itb = std::find(ino.begin(), ino.begin() + n, * (pos.begin() + j - 1));
    fte.itc = ino.begin() + n - 1;
    tr.push(fte);
    i = 5;
    while (i--)
    {
        ste = tr.front();
        std::cout << *ste.itb << " " << std::endl;
        if (ste.ita != ste.itb)
        {
            fte.ita = ste.ita;
            j = ste.itb - ino.begin() - 1;
            fte.itb = std::find(ste.ita, ste.itb, *(pos.begin() + j));
            std::cout << j << " Fir " << *(pos.begin() + j) << " ! ";
            fte.itc = ste.itb - 1;
            std::cout << "Fte: ita =  " << fte.ita - ino.begin();
            std::cout << " itb =  " << fte.itb - ino.begin();
            std::cout << " itc =  " << fte.itc - ino.begin() << std::endl;
            tr.push(fte);
        }
        if (ste.ita != ste.itb)
        {
            fte.ita = ste.itb;
            j = ste.itc - ino.begin() - 1;
            fte.itb = std::find(ste.itb, ste.itc, *(pos.begin() + j));
            std::cout << " Sec " << *(pos.begin() + j) << " ! ";
            fte.itc = ste.itc - 1;
            std::cout << "Fte: ita =  " << fte.ita - ino.begin();
            std::cout << " itb =  " << fte.itb - ino.begin();
            std::cout << " itc =  " << fte.itc - ino.begin() << std::endl;
            tr.push(fte);
        }
        tr.pop();
    }
    return 0;
}