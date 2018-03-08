#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
#define PII pair<int, int>
#define MP make_pair
struct Po
{
    int ct;
    PII a;
    string s;
    Po() {}
    Po(int ct, PII a, string s) : ct(ct), a(a), s(s) {}
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, ct = -1;
    cin >> a >> b >> c;
    string ans = "impossible";
    queue<Po> qu;
    map<PII, bool> vis;
    qu.push(Po(0, make_pair(0, 0), ""));
    while (!qu.empty())
    {
        Po tmp = qu.front();
        qu.pop();
        if (tmp.a.first == c || tmp.a.second == c)
        {
            ans = tmp.s;
            ct = tmp.ct;
            break;
        }
        if (tmp.a.first < a && vis[MP(a, tmp.a.second)] != 1)
        {
            qu.push(Po(tmp.ct + 1, MP(a, tmp.a.second), tmp.s + "FILL(1)\n"));
            vis[MP(a, tmp.a.second)] = 1;
        }
        if (tmp.a.second < b && vis[MP(tmp.a.first, b)] != 1)
        {
            qu.push(Po(tmp.ct + 1, MP(tmp.a.first, b), tmp.s + "FILL(2)\n"));
            vis[MP(tmp.a.first, b)] = 1;
        }
        if (tmp.a.first > 0 && vis[MP(0, tmp.a.second)] != 1)
        {
            qu.push(Po(tmp.ct + 1, MP(0, tmp.a.second), tmp.s + "DROP(1)\n"));
            vis[MP(0, tmp.a.second)] = 1;
        }
        if (tmp.a.second > 0 && vis[MP(tmp.a.first, 0)] != 1)
        {
            qu.push(Po(tmp.ct + 1, MP(tmp.a.first, 0), tmp.s + "DROP(2)\n"));
            vis[MP(tmp.a.first, 0)] = 1;
        }
        //POUR(a,b)
        int ta, tb;
        ta = b - tmp.a.second >= tmp.a.first ? 0 : tmp.a.first - b + tmp.a.second;
        tb = b - tmp.a.second >= tmp.a.first ? tmp.a.second + tmp.a.first : b;
        if (vis[MP(ta, tb)] != 1)
            qu.push(Po(tmp.ct + 1, MP(ta, tb), tmp.s + "POUR(1,2)\n"));
        vis[MP(ta, tb)] = 1;
        //POUR(b,a)
        ta = a - tmp.a.first >= tmp.a.second ? tmp.a.second + tmp.a.first : a;
        tb = a - tmp.a.first >= tmp.a.second ? 0 : tmp.a.second - a + tmp.a.first;
        if (vis[MP(ta, tb)] != 1)
            qu.push(Po(tmp.ct + 1, MP(ta, tb), tmp.s + "POUR(2,1)\n"));
        vis[MP(ta, tb)] = 1;
    }
    if (ct != -1)
        cout << ct << endl;
    cout << ans << endl;
    return 0;
}