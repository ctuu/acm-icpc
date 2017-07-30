#include <bits/stdc++.h>
#define N 10000
#define M 10000
using namespace std;
struct pa {
    int fi;
    double se;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    array<pa, M + 1> sc;
    array<double, N + 1> dp;
    while (cin >> n >> m && n && m)
    {
        array<vector<int>, N> oc;
        for (int i = 0; i < m; ++i)
            cin >> sc[i].first >> sc[i].second;
        sort(sc.begin,sc.begin() + m, [](auto a, auto b){return a.second < b.second });
        for (int i = 0; i < m; ++i)
            for (int j = n; j >= sc[i].first; --j)
            {
                if (dp[j] < dp[j - sc[i].first] + sc[i].second)
                {
                    dp[j] = dp[j - sc[i].first] + sc[i].second;
                    oc[j] = oc[j - sc[i].first];
                    oc[j].push_back(i);
                }
            }
        double ans = 1;
        for (auto i = oc[n].cbegin(); i < oc[n].cend(); ++i)
            ans *= (1 - sc[*i].second);
        ans = (1 - ans);
        ans *= 100;
        cout.precision(1);
        cout << fixed << ans << "%" << endl;
    }
    return 0;
}