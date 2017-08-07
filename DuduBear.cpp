#include <bits/stdc++.h>
#define B 1005
#define N 105
using namespace std;

struct no
{
    int s, c;
    no() = default;
    no(int a, int b)
    {
        this->s = a;
        this->c = b;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int b, n;
    cin >> b >> n;
    vector<no> va;
    for (int i = 0; i < n; ++i)
    {
        int s, c;
        cin >> s >> c;
        va.push_back(no(s, c));
    }
    array<int, V + 1> dp;
    array<array<int, B>, N> p;
    for (auto &i : p)
        i.fill(0);
    dp.fill(0);
    int ct = va.size();
    for (int i = 0; i < ct; ++i)
        for (int j = v; j >= va[i].c; --j)
        {
            if (dp[j] > dp[j - va[i].c] + va[i].s)
                p[i][j] = 0;
            if (dp[j] < dp[j - va[i].c] + va[i].s)
            {
                dp[j] = dp[j - va[i].c] + va[i].s;
                p[i][j] = 1;
            }
            else
                p[i][j] = 2;
        }
    // dp[j] = max(dp[j], dp[j - va[i].c] + va[i].s);
    cout << dp[v] << endl;
    return 0;
}