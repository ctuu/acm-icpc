#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long x, n, ans = 0;
    cin >> x >> n;
    for(int i = 0; i < n; ++i)
    {
        if(x>0 && x < 6)
        ans += 250;
        x = (x+1)%7;
    }
    cout << ans << endl;
    return 0;
}
