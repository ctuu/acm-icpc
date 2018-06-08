#include <algorithm>
#include <array>
#include <iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    array<int, 10> chs;
    int zs = INF;
    chs.fill(INF);
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int si = s.size(), ans = INF;
    for (int i = 0; i < si; ++i)
    {
        if (s[i] == '0')
        {
            if (chs[0] < i)
                zs = min(i, zs);
            else
                chs[0] = i;
            continue;
        }
        chs[s[i] - '0'] = min(i, chs[s[i] - '0']);
    }
    ans = min(ans, chs[5] + chs[7] + (chs[7] > chs[5] ? -1 : 0));
    ans = min(ans, chs[2] + chs[5] + (chs[2] > chs[5] ? -1 : 0));
    ans = min(ans, zs + chs[0] - 1);
    ans = min(ans, chs[0] + chs[5] + (chs[5] > chs[0] ? -1 : 0));
    ans = ans >= INF ? -1 : ans;
    cout << ans << endl;
    return 0;
}