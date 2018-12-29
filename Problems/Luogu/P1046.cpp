#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    int a[10], b, ans = 0;
    for (int i = 0; i < 10; ++i)
        cin >> a[i];
    cin >> b;
    for (int i = 0; i < 10; ++i)
        ans += (b + 30 >= a[i]);
    cout << ans << '\n';
    return 0;
}