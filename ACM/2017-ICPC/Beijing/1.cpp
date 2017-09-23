#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    array<int, 102> p;
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; ++i)
            cin >> p[i];
        int q;
        cin >> q;
        for (int i = 0; i < q; ++i)
        {
            int tmp;
            cin >> tmp;
            p[tmp] = -1;
        }
        int aa = 0, ab = 1;
        for (int i = 0; i < n - m; ++i)
        {
            if (p[i] == -1)
                continue;
            int b, tmp = INF, tot = i + m;
            for (int j = i + 1; j < tot && tot <= n; ++j)
            {
                if (p[j] == -1)
                    ++tot;
                else if (p[j] < tmp)
                {
                    tmp = p[j];
                    b = j;
                }
            }
            if (n>= tot && p[i] + p[b] < p[aa] + p[ab])
            {
                aa = i;
                ab = b;
            }
        }
            cout << aa << " " << ab << endl;
    }
    return 0;
}