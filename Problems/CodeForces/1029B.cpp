#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a, b, t = 1, ans = 1;
    cin >> a;
    for (int i = 1; i < n; ++i)
    {
        cin >> b;
        t = a * 2 >= b ? t + 1:1;
        a = b;
        ans = max(ans, t);
    }
    cout << ans << endl;
    return 0;
}