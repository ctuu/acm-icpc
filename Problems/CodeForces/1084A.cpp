#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    int ans = 0x7f7f7f7f, sum = 0;
    {
        for (int x = 1; x <= n; ++x)
        {
            for (int i = 0; i < n; ++i)
                sum += (abs(x - (i + 1)) + i + x - 1) * 2 * v[i];
            ans = min(ans, sum);
            sum = 0;
        }
    }
    cout << ans << '\n';
    return 0;
}
