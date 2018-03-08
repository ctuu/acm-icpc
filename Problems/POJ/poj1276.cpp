#include <iostream>
#include <algorithm>
#include <vector>
#define CA 100000
#define N 10
#define K 1000
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cash;
    while (cin >> cash)
    {
        int n;
        cin >> n;
        vector<int> va;
        for (int i = 0; i < n; ++i)
        {
            int nk, dk, r = 1;
            cin >> nk >> dk;
            while (nk >= r)
            {
                va.push_back(dk * r);
                nk -= r;
                r <<= 1;
            }
            while (nk)
            {
                if (nk >= r)
                {
                    nk -= r;
                    va.push_back(dk * r);
                }
                r >>= 1;
            }
        }
        int dp[CA] = {0};
        int ct = va.size();
        for (int i = 0; i < ct; ++i)
            for (int j = cash; j >= va[i]; --j)
                dp[j] = max(dp[j], dp[j - va[i]] + va[i]);
        cout << dp[cash] << endl;
    }
    return 0;
}