#include <bits/stdc++.h>
using namespace std;
int fa[5002] = {0};
void find(int x);
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        int re[5002] = {0};
        for (int i = 0; i < n; ++i)
            fa[i] = i;
        for (int i = 0; i < m; ++i)
        {
            int a, b;
            cin >> a >> b;
            fa[a] = b;
        }
        for (int i = 0; i < m; ++i)
        {
            find(i);
            ++re[fa[i]];
        }
        bool fl = 1;
        for (int i = 0; i < n; ++i)
        {
            cout << i << ":" << re[i] << endl;
            if (re[i] > 0 && re[i] % 3 != 0)
                fl = 0;
        }
        if (fl)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

void find(int x)
{
    int a = x;
    while (fa[a] != a)
        a = fa[a];
    int i = x, j;
    while (i != a)
    {
        j = fa[i];
        fa[i] = a;
        i = j;
    }
    return;
}