#include <bits/stdc++.h>
using namespace std;
int fa[5002] = {0};
int find(int x);
void merge(int x, int y);
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
            merge(a, b);
        }
        int re[5002] = {0};
        for (int i = 1; i <= n; ++i)
        {
            ++re[find(i)];
            //cout << i << "to" << fa[i] << endl;
        }
        bool fl = 1;
        for (int i = 1; i <= n; ++i)
        {
            // cout << i << ":" << re[i] << endl;
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

int find(int x)
{
    int a = x;
    while (fa[a] != a)
        a = fa[a];
    
    int i = x, te;
    while (i != a)
    {
        te = fa[i];
        fa[i] = a;
        i = te;
    }
    return a;
}

void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx != fy)
       fa[fx] = fy;
    return;
}