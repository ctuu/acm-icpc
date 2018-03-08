#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 25
#define SH 5000 //offest
#define RAG 300
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c, g;
    cin >> c >> g;
    int nc[MAXN];
    int ng[MAXN];
    for (int i = 1; i <= c; ++i)
        cin >> nc[i];
    for (int i = 1; i <= g; ++i)
        cin >> ng[i];
    int dp[MAXN][SH + MAXN * RAG] = {0};
    dp[0][SH] = 1;
    for (int i = 1; i <= g; ++i)
        for (int k = 0; k < SH + MAXN * RAG; ++k)
            if (dp[i - 1][k])
                for (int j = 1; j <= c; ++j)
                    dp[i][k + ng[i] * nc[j]] += dp[i - 1][k];
    cout << dp[g][SH] << endl;
    return 0;
}