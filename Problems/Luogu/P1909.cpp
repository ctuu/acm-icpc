#include <iostream>
#include <array>
using namespace std;
const int N = 1e4 + 7;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int c, p;
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < 3; ++i)
    {
        cin >> c >> p;
        ans = min(ans, (n / c + (n % c ? 1 : 0)) * p);
    }
    cout << ans;
    return 0;
}