#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
const int INF = 100007;
using PIS = pair<int, string>;

int main()
{
    int n;
    cin >> n;
    map<string, int> mp;
    mp["A"] = INF;
    mp["B"] = INF;
    mp["C"] = INF;
    mp["AB"] = INF;
    mp["BC"] = INF;
    mp["AC"] = INF;
    mp["ABC"] = INF;
    for (int i = 0; i < n; ++i)
    {
        int ci;
        string s;
        cin >> ci >> s;
        sort(s.begin(), s.end());
        mp[s] = min(mp[s], ci);
    }
    int ans = INF * 10;
    if (mp["ABC"] != INF)
        ans = min(mp["ABC"], ans);
    if (mp["A"] != INF && mp["BC"] != INF)
        ans = min(mp["A"] + mp["BC"], ans);
    if (mp["B"] != INF && mp["AC"] != INF)
        ans = min(mp["B"] + mp["AC"], ans);
    if (mp["C"] != INF && mp["AB"] != INF)
        ans = min(mp["C"] + mp["AB"], ans);
    if (mp["AC"] != INF && mp["BC"] != INF)
        ans = min(mp["AC"] + mp["BC"], ans);
    if (mp["AB"] != INF && mp["AC"] != INF)
        ans = min(mp["AB"] + mp["AC"], ans);
    if (mp["BC"] != INF && mp["AB"] != INF)
        ans = min(mp["BC"] + mp["AB"], ans);
    if (mp["C"] != INF && mp["A"] != INF && mp["B"] != INF)
        ans = min(mp["C"] + mp["B"] + mp["A"], ans);
    ans = ans == INF*10 ? -1 : ans;
    cout << ans << endl;
    return 0;
}