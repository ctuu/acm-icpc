#include <iostream>
#include <algorithm>
#include <vector>
#define MH 20000005
using namespace std;
bool dp[MH];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    dp[0] = 1;
    int n, b, m = 0;
    cin >> n >> b;
    int vi[22];
    for (int i = 0; i < n; ++i)
    {
        cin >> vi[i];
        m += vi[i];
    }
    for (int i = 0; i < n; ++i)
        for (int j = m; j >= vi[i]; --j)
            if (dp[j - vi[i]])
                dp[j] = 1;
    int ans = 0;
    for (int i = b; i <= m; ++i)
        if (dp[i])
        {
            cout << i - b;
            break;
        }
    return 0;
}