#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    array<int, 101> ar;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> ar[i];
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (k <= 0)
            break;
        if (ar[i] > 8)
        {
            ar[i + 1] += ar[i] - 8;
            k -= 8;
        }
        else
            k -= ar[i];
        ++ans;
    }
    if (k > 0)
        cout << -1;
    else
        cout << ans;
    return 0;
}