#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
const int N = 43;
array<int, N> ar;
int p = 0, cnt = 0;
array<vector<vector<int>>, N> ncf;
array<long long, N> dp;
void cf(int n, int mf)
{
    if (n <= 0)
    {
        vector<int> t;
        for (int i = 0; i < p; ++i)
            t.push_back(ar[i]);
        ncf[cnt].push_back(t);
        return;
    }
    for (int i = mf; i <= n; ++i)
    {
        ar[p] = i;
        ++p;
        cf(n - i, i);
        --p;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i < N; ++i)
    {
        cnt++;
        cf(i, 1);
    }
    for (auto i : ncf[6])
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    cout << endl;
    dp.fill(0);
    dp[1] = dp[2] = 1;
    dp[3] = 2;
    for (int i = 4; i < N; ++i)
    {
        for (auto j : ncf[i - 1])
        {
            long long tns = 1;
            for (auto k : j)
                tns *= dp[k];
            dp[i] += tns;
        }
    }
    int n;
    while (cin >> n)
        cout << dp[n] << endl;
    // cout << dp[5] <<endl;
    return 0;
}