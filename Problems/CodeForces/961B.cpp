#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
const int N = 100000;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    array<int, N> theo, wk;
    int n, k, sum = 0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> theo[i];
    for (int i = 0; i < n; ++i)
    {
        cin >> wk[i];
        if (wk[i])
            sum += theo[i];
    }
    int ans = sum, tmp = 0;
    for (int i = 0; i < k; ++i)
        if (!wk[i])
            tmp += theo[i];
    ans += tmp;
    for (int i = k; i < n; ++i)
    {
        if (!wk[i - k])
            tmp -= theo[i - k];
        if (!wk[i])
            tmp += theo[i];
        ans = max(ans, sum + tmp);
    }
    cout << ans << endl;

    return 0;
}