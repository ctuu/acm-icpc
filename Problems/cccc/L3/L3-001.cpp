#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
const int N = 10003;
const int INF = 0x3f3f3f3f;
array<int, N> dp, money, sq;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    dp.fill(-INF);
    sq.fill(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> money[i];
    dp[0] = 0;
    sort(money.begin() + 1, money.begin() + n + 1,greater<int>());
    for (int i = 1; i <= n; ++i) 
        for (int j = m; j >= money[i]; j--)
        {
            if (dp[j - money[i]] == -INF)
                continue;
            if (dp[j - money[i]] + 1 >= dp[j])
            {
                dp[j] = dp[j - money[i]] + 1;
                sq[j] = i;
            }
        }
    if (dp[m] != -INF)
    {
        int k = m;
        vector<int> vec;
        while (k > 0)
        {
            vec.push_back(money[sq[k]]);
            k -= money[sq[k]];
        }
        sort(vec.begin(), vec.end());
        for(int i = 0; i < vec.size(); ++i)
        {
            if(i)
                cout <<" ";
            cout << vec[i];
        }
    }
    else
        cout << "No Solution" << endl;
    return 0;
}