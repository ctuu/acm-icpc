#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    double n, ct = 0, c = 2;
    int ans = 0;
    cin >> n;
    while (ct < n)
    {
        ++ans;
        ct += c;
        c *= 0.98;
    }
    cout << ans;
    return 0;
}