#include <bits/stdc++.h>
using namespace std;
int main()
{
    array<int, 100002> nu;
    int n, k;
    while (cin >> n >> k)
    {
        nu.fill(0);
        nu[0] = 1;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 1; i + j <= n && j <= k; ++j)
                nu[i + j] = nu[i + j] % 1000000007 +  nu[i] % 1000000007;
        }
        cout << nu[n] << endl;
    }
    return 0;
}