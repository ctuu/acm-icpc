#include <algorithm>
#include <array>
#include <iostream>
using namespace std;
const int INF = 0x3f3f3f3f;

int deal(string s, int a, int b)
{
    int tns = a + b;
    string tms = s.substr(a,1) + s.substr(b,1);
    if(tms == "00" || tms == "57" || tms == "52" || tms == "05")
        --tns;
    if (s[a] > s[b])
        swap(a, b);
    tms = s.substr(a,1) + s.substr(b,1);
    if(tms == "00" || tms == "25" || tms == "05" || tms == "57")
    {
        s.erase(max(a,b), 1);
        s.erase(min(a,b), 1);
        int si = s.size() - 1;
        while (s[si] == '0' && si > 0)
            si--;
        tns += s.size() - 1 - si;
        if (si == 0 && s[si] == '0')
            return INF;
        return tns;
    }
    return INF;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int si = s.size(), ans = INF;
    for (int i = 0; i < si; ++i)
        for (int j = i + 1; j < si; ++j)
            ans = min(ans, deal(s, i, j));
    ans = ans >= INF ? -1 : ans;
    cout << ans << endl;
    return 0;
}