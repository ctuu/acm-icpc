#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b, c, t, ans = 0;;
    array<int, 1003> ar;
    cin >> n >> a >> b >> c >> t;
    for(int i = 0; i < n; ++i)
        cin>>ar[i];
    if(b >= c)
        ans = a * n;
    else
        for(int i = 0; i < n; ++i)
            ans += a + (c - b) * (t - ar[i]);
    cout << ans << endl;
    return 0;
}