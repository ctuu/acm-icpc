#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int dp[22][22][22];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 22; ++i)
        for(int j = 0; j < 22; ++j)
            for(int k = 0; k < 22; ++k)
            {
                if(!i || !j || !k)
                    dp[i][j][k] = 1;
                else if(i < j && j < k)
                    dp[i][j][k] = dp[i][j][k-1] + dp[i][j-1][k-1] - dp[i][j-1][k];
                else
                    dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1];
            }
    int a, b, c;
    while(cin >> a >> b >> c)
    {
        if(a == -1 && b == -1 && c == -1)
            return 0;
        cout << "w(" << a <<", " << b << ", " << c << ") = ";
        a = a < 0 ? 0 : a > 20 ? 20 : a;
        b = b < 0 ? 0 : b > 20 ? 20 : b;
        c = c < 0 ? 0 : c > 20 ? 20 : c;
        cout << dp[a][b][c] << endl;
    }
    return 0;
}
    