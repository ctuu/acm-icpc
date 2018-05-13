#include <array>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1007;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, w;
    cin >> n >> w;
    int l = 0, h = w;
    array<int, N> a;
    int sm = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sm += a[i];
        if(sm > w || sm < -w)
        {
            cout << 0 << endl;
            return 0;
        }
        h = min(h, w - sm);
        l = max(l, -sm);
    }
    int ans = h - l + 1;
    ans = ans < 0 ? 0: ans;
    cout << ans << endl;
    return 0;
}