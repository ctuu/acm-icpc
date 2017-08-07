#include <iostream>
#include <array>
#include <vector>
#define N 105
#define M 105
#define K 105
#define S 105
#define INF 0x3f3f3f3f
using namespace std;
struct no
{
    int a, b;
    no() = default;
    no(int ta, int tb)
    {
        this->a = ta;
        this->b = tb;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, s;
    while (cin >> n >> m >> k >> s)
    {
        vector<no> va;
        for (int i = 0; i < k; ++i)
        {
            int a, b;
            cin >> a >> b;
            va.push_back(no(a, b));
        }
        array<array<int, S>, M> dp;
        for (auto &i : dp)
            i.fill(0);
        int ct = va.size();
        int minm = INF;
        for (int i = 0; i < ct; ++i)
            for (int j = va[i].b; j <= m; ++j)
                for (int l = 0; l < s; ++l)
                {
                    dp[j][l] = max(dp[j][l], dp[j - va[i].b][l - 1] + va[i].a);
                    if (dp[j][l] >= n)
                        minm = min(minm, j);
                }
        if (minm == INF)
            cout << -1 << endl;
        else
            cout << m - minm << endl;
    }
    return 0;
}