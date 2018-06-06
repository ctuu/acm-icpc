#include <iostream>
#include <map>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string t;
    map<char, int> a, b, c;
    cin >> t;
    for (auto i : t)
        a[i]++;
    cin >> t;
    for (auto i : t)
        b[i]++;
    cin >> t;
    for (auto i : t)
        c[i]++;
    int ma = 0, mb = 0, mc = 0;
    for (auto i : a)
        ma = max(ma, i.second);
    for (auto i : b)
        mb = max(mb, i.second);
    for (auto i : c)
        mc = max(mc, i.second);
    int si = t.size();
    // cout << ma << " " << mb << " " << mc << endl;
    ma = ma + n > si ? si - (a.size() > 2 ? 0 : (ma + n - si) % 2) : ma + n;
    for (auto i : a)
    {
        int cr = i.second;
        ma = max(ma, cr + n > si ? si - (a.size() > 2 ? 0 : (cr + n - si) % 2) : cr + n);
    }
    for (auto i : b)
    {
        int cr = i.second;
        mb = max(mb, cr + n > si ? si - (b.size() > 2 ? 0 : (cr + n - si) % 2) : cr + n);
    }
    for (auto i : c)
    {
        int cr = i.second;
        mc = max(mc, cr + n > si ? si - (c.size() > 2 ? 0 : (cr + n - si) % 2) : cr + n);
    }
    // cout << ma << " " << mb << " " << mc << endl;
    if ((ma == mb && mb >= mc) || (ma == mc && mc >= mb) || (mb == mc && mc >= ma))
        cout << "Draw" << endl;
    else if (ma > mb && ma > mc)
        cout << "Kuro" << endl;
    else if (mb > ma && mb > mc)
        cout << "Shiro" << endl;
    else if (mc > ma && mc > mb)
        cout << "Katie" << endl;
    return 0;
}