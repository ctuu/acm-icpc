#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cost[4][2]{0};
    array<array<string, 103>, 4> cb;
    int n;
    cin >> n;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < n; ++j)
            cin >> cb[i][j];
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                if (cb[i][j][k] != (j + k) % 2 + '0')
                    cost[i][0]++;
                else
                    cost[i][1]++;
    int ans = INF;
    for (int i = 0; i < 3; ++i)
        for (int j = i + 1; j < 4; ++j)
        {
            int k = 0, l = 0;
            while (k == i || k == j)
                ++k;
            while (l == i || l == j || l == k)
                ++l;
            ans = min(ans, cost[i][0] + cost[j][0] + cost[k][1] + cost[l][1]);
        }
    cout << ans << endl;
    return 0;
}