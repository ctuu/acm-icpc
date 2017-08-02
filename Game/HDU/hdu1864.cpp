#include <bits/stdc++.h>
#define ML 1000
#define N 35
#define MM 600
#define MU 100
#include <cstdio>
using namespace std;

array<int, ML * MU * N> dp;
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    double q;
    int n;
    while (~scanf("%lf %d", &q, &n) && n)
    {
        vector<int> va;
        for (int i = 0; i < n; ++i)
        {
            int m, sum = 0;
            bool vail = 1;
            cin >> m;
            double pra = 0, prb = 0, prc = 0;
            for (int j = 0; j < m; ++j)
            {
                double pr;
                char ch;
                scanf(" %c:%lf", &ch, &pr);
                // if ((ch == 'A' || ch == 'B' || ch == 'C') && pr <= MM)
                if (ch == 'A')
                    pra += pr;
                else if (ch == 'B')
                    prb += pr;
                else if (ch == 'C')
                    prc += pr;
                else
                    vail = 0;
                sum += pr * MU;
                // cout << vail << " " << ch << " " << pr << " " << sum << endl;
            }
            if (vail && pra <= 600 && prb <= 600 && prc <= 600 && sum <= ML * MU)
                va.push_back(sum);
        }
        // for (auto i: va)
        // cout << i << endl;
        dp.fill(0);
        int ct = va.size();
        for (int i = 0; i < ct; ++i)
            for (int j = (int)(q * MU); j >= va[i]; --j)
                dp[j] = max(dp[j], dp[j - va[i]] + va[i]);
        printf("%.2f\n", dp[(int)(q * 100)] / 100.00);
    }
    return 0;
}