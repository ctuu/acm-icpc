#include <bits/stdc++.h>
using namespace std;
int fa[5005] = {0};
int find(int x);
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        for (int i = 0; i <= n; ++i)
            fa[i] = i;
        for (int i = 0; i < m; ++i)
        {
            int a, b;
            cin >> a >> b;
            a = find(a);
            b = find(b);
            if (a != b)
                fa[b] = a;
        }

        array<int, 5005> re;
        re.fill(0);
        for (int i = 1; i <= n; ++i)
            ++re[find(i)];

        bool fl = 1;
        for (int i = 1; i <= n; ++i)
            if (re[find(i)] % 3 != 0)
                fl = 0;

        if (fl)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}

int find(int x)
{
    int a = x;
    while (fa[a] != a)
        a = fa[a];
    
    int i = x, temp;
    while (fa[i] != a)
    {
        temp = fa[i];
        fa[i] = a;
        i = temp;
    }
    return a;
}