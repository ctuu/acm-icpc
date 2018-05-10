#include <array>
#include <iostream>
#include <map>
using namespace std;
const int N = 2e5 + 7;
map<int, int> dp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, mx = 0, v = -1;
    cin >> n;
    array<int, N> ar;
    for (int i = 1; i <= n; ++i)
    {
        cin >> ar[i];
        dp[ar[i]] = dp[ar[i] - 1] + 1;
        if (dp[ar[i]] > mx)
        {
            v = ar[i];
            mx = dp[ar[i]];
        }
    }
    v = v - mx + 1;
    cout << mx << endl;
    for (int i = 1; i <= n; ++i)
        if (ar[i] == v)
        {
            cout << i << " ";
            ++v;
        }
    return 0;
}