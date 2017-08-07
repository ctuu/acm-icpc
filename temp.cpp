/********************
 * Author:fisty
 * Date:2014-11-29
 * HDU3535
 ********************/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 1100
#define INF 0x3f3f3f3f
struct number
{
    int t;
    int flag;
    int c[MAX_N];
    int v[MAX_N];

} bag[MAX_N];

int dp[MAX_N][MAX_N];
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &bag[i].t, &bag[i].flag);
            for (int j = 0; j < bag[i].t; j++)
            {
                scanf("%d%d", &bag[i].c[j], &bag[i].v[j]);
            }
            if (bag[i].flag == 0)
            {
                //至少选一个
                for (int j = 0; j <= m; j++)
                {
                    dp[i][j] = -INF;
                }
                for (int k = 0; k < bag[i].t; k++)
                {
                    for (int j = m; j >= bag[i].c[k]; j--)
                    {
                        dp[i][j] = max(dp[i][j], dp[i][j - bag[i].c[k]] + bag[i].v[k]);
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - bag[i].c[k]] + bag[i].v[k]);
                    }
                }
            }
            else if (bag[i].flag == 1)
            {
                //每组选一个，互斥
                for (int j = 0; j <= m; j++)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                for (int k = 0; k < bag[i].t; k++)
                {
                    for (int j = m; j >= bag[i].c[k]; j--)
                    {
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - bag[i].c[k]] + bag[i].v[k]);
                    }
                }
            }
            else
            {
                //0-1bag
                for (int j = 0; j <= m; j++)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                for (int k = 0; k < bag[i].t; k++)
                {
                    for (int j = m; j >= bag[i].c[k]; j--)
                    {
                        dp[i][j] = max(dp[i][j], dp[i][j - bag[i].c[k]] + bag[i].v[k]);
                    }
                }
            }
        }
        dp[n - 1][m] = max(dp[n - 1][m], -1);
        printf("%d\n", dp[n - 1][m]);
    }
    return 0;
}
