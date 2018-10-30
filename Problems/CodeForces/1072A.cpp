#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int w, h, k;
    cin >> w >> h >> k;
    int ans = (w + h - 2) * 2;
    k--;
    while (w && h && k)
    {
        k--;
        w -= 4;
        h -= 4;
        ans += (w + h - 2) * 2;
    }
    cout << ans << endl;
    return 0;
}