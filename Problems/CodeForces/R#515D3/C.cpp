#include <cmath>
#include <iostream>
#include <map>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    int l = 0, r = 1;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        char c;
        int k;
        cin >> c >> k;
        if (c == 'L')
            mp[k] = l--;
        else if (c == 'R')
            mp[k] = r++;
        else
        {
            int ans = min(r - mp[k] - 1, mp[k] - l - 1);
            cout << ans << endl;
        }
    }
    return 0;
}