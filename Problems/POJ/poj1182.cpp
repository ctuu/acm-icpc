// #include <algorithm>
// #include <iostream>
#include<cstdio>
using namespace std;
const int N = 5e4 + 7;

int f[N], c[N], n;
//define 0 as equal 1 as hunter 2 as be eatn

int find(int x)
{
    if (f[x] == x)
        return x;
    int t = find(f[x]);
    c[x] = (c[x] + c[f[x]]) % 3;
    return f[x]=t;
}

int jud(int d, int x, int y)
{
    if (x > n || y > n)
        return 1;
    int fx = find(x);
    int fy = find(y);
    if (fx == fy)
    {
        if (d == 1)
        {
            if (c[x] == c[y])
                return 0;
            return 1;
        }
        if ((c[x] - c[y] + 3) % 3 == 1)
            return 0;
        return 1;
    }
    else
    {
        f[fx] = fy;
        if (d == 1)
        {
            if (c[x] == 1)
                c[fx] = (c[y] + 2) % 3;
            else if (!c[x])
                c[fx] = c[y];
            else
                c[fx] = (c[y] + 1) % 3;
        }

        else
        {
            if (c[x] == 1)
                c[fx] = c[y];
            else if (!c[x])
                c[fx] = (c[y] + 1) % 3;
            else if (c[x] == 2)
                c[fx] = (c[y] + 2) % 3;
        }
    }
    return 0;
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    for (int i = 0; i < N; ++i)
    {
        f[i] = i;
        c[i] = 0;
    }
    int k, ans = 0;
    scanf("%d %d", &n, &k);
    // cin >> n >> k;
    int d, x, y;
    for (int i = 0; i < k; ++i)
    {
        // cin >> d >> x >> y;
        scanf("%d %d %d", &d, &x, &y);
        ans += jud(d, x, y);
        // if (jud(d, x, y))
        // {
        //     ans++;
        //     cout << f[x] <<" " << f[y] << endl;
        //     cout << c[x] <<" " << c[y] << endl;
        //     cout << "! " << d << " " << x << " " << y << endl;
        // }
    }
    // cout << ans << endl;
    printf("%d", ans);
    return 0;
}
