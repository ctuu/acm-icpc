#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <array>
#include <vector>
const int INF = 0x3f3f3f3f;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    map<string, int> mp;
    array<int, 100005> gb;
    array<long long, 100005> val, mv;
    for(int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        mp[s] = i;
        gb[i] = i;
    }
    mv.fill(INF);
    for(int i = 1; i <= n; ++i)
        cin >> val[i];
    while(k--)
    {
        int t,c;
        cin >> t;
        for(int i = 0; i < t; ++i)
        {
            cin >> c;
            gb[c] = k;
            mv[k] = min(mv[k], val[c]);
        }
    }
    long long sum = 0;
    for(int i = 0; i < m;++i)
    {
        string s;
        cin >> s;
        sum += mv[gb[mp[s]]];
    }
    cout << sum << endl;
    return 0;
}