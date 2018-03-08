#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, k, maxm = -INF, mi = 0;
    array<long long, 100005> ar;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> ar[i];
        maxm = max(maxm, ar[i]);
        if (ar[mi] > ar[i])
            mi = i;
    }
    if (k >= 3)
        cout << maxm;
    else if (k == 2)
        cout << max(ar[n - 1], ar[0]);
    else
        cout << ar[mi];
    return 0;
}