#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long fact[23] = {0};
    fact[0] = fact[1] = 1;
    long long d[23] = {0};
    for (int i = 1; i < 23; ++i)
    {
        fact[i] = fact[i - 1] * i;
        for(int j = 0; j <= i; ++j)
        {
            if(j%2)
                d[i] -= fact[i] / fact[j];
            else
                d[i] += fact[i] / fact[j];
        }
    }
    long long num[52][52] = {0};
    num[1][0] = 1;
    for (int m = 1; m <= 23; m++)
        for (int n = 1; n <= 23 + 1; n++)
            num[n][m] = num[n - 1][m - 1] + num[n][m - 1];
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        cout << num[m+1][n] * d[m] << endl;
    }
    return 0;
}