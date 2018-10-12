#include <array>
#include <iostream>
using namespace std;
const int N = 1e5 + 7;

array<int, N> tb, te;
int main()
{
    int n, l, a;
    cin >> n >> l >> a;
    for (int i = 0; i < n; ++i)
        cin >> tb[i] >> te[i];
    int ans = 0;
    if (n == 0)
        ans = l / a;
    else
    {
        ans += tb[0] / a;
        for (int i = 1; i < n; ++i)
            ans += (tb[i] - (tb[i-1] + te[i-1])) / a;
        ans += (l - (tb[n-1] + te[n-1])) / a;
    }
    cout << ans << endl;
    return 0;
}