#include <iostream>
#include <algorithm>
#include <array>
#include <map>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,t;
    map<int, int> mp;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> m;
        for(int j = 0; j < m; ++j)
        {
            cin >> t;
            mp[t]++;
        }
    }
    int ma = 0, mi = 0;
    for(auto i: mp)
        if((i.second > mi)||(i.second == mi && i.first > ma))
        {
            mi = i.second;
            ma = i.first;
        }
    cout << ma <<" " << mi << endl;
    return 0;
}