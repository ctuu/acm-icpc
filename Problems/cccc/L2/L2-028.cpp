#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
array<bool, 1003> bg;
vector<vector<int>> pt, hs;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, t;
    cin >> n >> m;
    pt.resize(m);
    hs.resize(n);
    for (int i = 0; i < m; ++i)
    {
        cin >> k;
        string s;
        for (int j = 0; j < k; ++j)
        {
            cin >> s;
            t = s[0] == '-' ? stoi(s.substr(1)) : stoi(s);
            bg[t] = s[0] == '-' ? 1 : 0;
            pt[i].push_back(t);
            hs[t].push_back(i);
        }
    }
    string sa, sb;
    cin >> sa >> sb;
    int ta = sa[0] == '-' ? stoi(sa.substr(1)) : stoi(sa);
    bg[ta] = sa[0] == '-' ? 1 : 0;
    int tb = bg[ta] == 0 ? stoi(sb.substr(1)) : stoi(sb);
    bg[tb] = !bg[ta];
    array<double, 1003> ara, arb;
    ara.fill(0);
    arb.fill(0);
    for (auto i : hs[ta])
        for (auto j : pt[i])
            if (bg[j] != bg[ta])
                ara[j] += 1.0 / pt[i].size();
    for (auto i : hs[tb])
        for (auto j : pt[i])
            if (bg[j] != bg[tb])
                arb[j] += 1.0 / pt[i].size();
    double ma = 0, mb = 0;
    set<int> sta, stb;
    for (int i = 0; i < n; ++i)
    {
        ma = max(ma, ara[i]);
        mb = max(mb, arb[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        if (fabs(ara[i] - ma) < 10e-8)
            sta.insert(i);
        if (fabs(arb[i] - mb) < 10e-8)
            stb.insert(i);
    }
    if (sta.count(tb) && stb.count(ta))
        cout << sa << " " << sb << endl;
    else
    {
        for (auto i : sta)
        {
            cout << sa << " ";
            if (!bg[ta])
                cout << "-";
            cout << i << endl;
        }
        for (auto i : stb)
        {
            cout << sb << " ";
            if (!bg[tb])
                cout << "-";
            cout << i << endl;
        }
    }
    return 0;
}