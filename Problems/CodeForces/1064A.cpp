#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    int ans = 0;
    cin >> a >> b >> c;
    ans = min(a + b - c - 1, min(a + c - b - 1, b + c - a - 1));
    ans = ans >= 0 ? 0 : -ans;
    cout << ans << endl;
    return 0;
}