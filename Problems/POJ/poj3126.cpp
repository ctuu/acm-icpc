#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define N 9999
bool pr[2 * N];
void prpr()
{
    long long i, j;
    for (i = 2; i < N; ++i)
        if (pr[i] == 1)
            continue;
        else
            for (j = 2 * i; j < 2 * N; j += i)
                pr[j] = 1;
}
struct Ele
{
    int n, w;
    Ele() {}
    Ele(int n, int w) : n(n), w(w) {}
};
int cd(int i, int j, int s)
{
    switch (i)
    {
    case 0:
        return s % 1000 + j * 1000;
        break;
    case 1:
        return s / 1000 * 1000 + s % 100 + j * 100;
    case 2:
        return s / 100 * 100 + s % 10 + j * 10;
    case 3:
        return s / 10 * 10 + j;
    }
    return 4;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    prpr();
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int vis[10000];
        for(int i = 0; i < 10000; ++i)
            vis[i] = 0;
        queue<Ele> qu;
        qu.push(Ele(a, 0));
        int ans = -1;
        while (!qu.empty())
        {
            Ele tmp = qu.front();
            qu.pop();
            if (tmp.n == b)
            {
                ans = tmp.w;
                break;
            }
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 10; ++j)
                {
                    int s = cd(i, j, tmp.n);
                    if (s < 1000)
                        continue;
                    if (!pr[s] && !vis[s])
                    {
                        vis[s] = 1;
                        qu.push(Ele(s, tmp.w + 1));
                    }
                }
        }
        if (ans != -1)
            cout << ans << endl;
        else
            cout << "Impossible" << endl;
    }
    return 0;
}