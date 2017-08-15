#include <iostream>
#include <algorithm>
#include <array>
#include <set>
#include <vector>
using namespace std;
int GCD(int a, int b)
{
    if (b)
        while ((a %= b) && (b %= a))
            ;
    return a + b;
}
int main()
{
    array<int, 501> free;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    free.fill(1);
    int n;
    for (int n = 1; n <= 500; ++n)
        for (int j = 2; j < 23; ++j)
            if (n % (j * j) == 0)
                free[n] = 0;
    array<set<int>, 501> li;
    array<array<int, 501>, 501> an;
    for (int n = 1; n <= 500; ++n)
        if (free[n])
        {
            li[n].insert(n);
            for (int i = 1; i <= n; ++i)
            {
                if (!free[i])
                    continue;
                if (GCD(n, i) == 1)
                    li[n].insert(i);
            }
        }
    for (int i = 1; i <= 30; ++i)
    {
        cout << i << ": ";
        for (auto j : li[i])
            cout << j << " ";
        cout << endl;
    }
    return 0;
}