#include <iostream>
#include <algorithm>
#include <array>
#define N 100005
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    array<int, N> ar;
    while (t--)
    {
        int n, k, ans = 1;
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
            cin >> ar[i];
        sort(ar.begin(), ar.begin() + n);
        for (int i = n - 2; i > -1; --i)
            if (ar[i + 1] - ar[i] <= k)
                ++ans;
            else
                break;
        cout << ans << endl;
    }
    return 0;
}