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
    int t;
    cin >> t;
    for (int it = 1; it <= t; ++it)
    {
        int b, n;
        cin >> b >> n;
        vector<no> va;
        for (int i = 0; i < n; ++i)
        {
            int s, c;
            cin >> s >> c;
            va.push_back(no(s, c));
        }
        array<int, B> dp;
        array<array<bool, B>, N> p;
        for (auto &i : p)
            i.fill(false);
        dp.fill(0);
        for (int i = 0; i < n; ++i)
            for (int j = b; j >= va[i].c; --j)
                if (dp[j] < dp[j - va[i].c] + va[i].s)
                {
                    dp[j] = dp[j - va[i].c] + va[i].s;
                    p[i][j] = true;
                }
        vector<int> li;
        int cost = 0;
        for (int i = n - 1, j = b; i >= 0; --i)
            if (p[i][j])
            {
                li.push_back(i + 1);
                cost += va[i].c;
                j -= va[i].c;
            }
        sort(li.begin(), li.end());
        cout << "Case #" << it << ":" << endl;
        cout << dp[b] << " " << cost << endl;
        int ct = li.size();
        for (int i = 0; i < ct; ++i)
        {
            if (i)
                cout << " ";
            cout << li[i];
        }
        if (ct)
            cout << endl;
    }
    return 0;
}