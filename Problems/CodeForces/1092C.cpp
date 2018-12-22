#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <set>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> v;
    v.resize(2 * n - 2);
    for (auto &i : v)
        cin >> i;
    vector<string> vc(v);
    sort(vc.begin(), vc.end(),
         [](auto a, auto b) {  if (a.size() == b.size()) return a < b;
                                  return a.size() < b.size(); });
    set<string> po;
    po.insert(*vc.begin() + *vc.rbegin());
    po.insert(*vc.rbegin() + *vc.begin());
    po.insert(vc[1] + *vc.rbegin());
    po.insert(*vc.rbegin() + vc[1]);
    array<vector<int>, 100> ar;

    for (int i = 0; i < 2 * n - 2; ++i)
        ar[v[i].size()].push_back(i);
    for (auto c : po)
    {
        array<int, 200> tp;
        tp.fill(0);
        int fl = 0;
        for (int i = 1; i < n; ++i)
        {
            int &a = ar[i][0], &b = ar[i][1];
            tp[a] = v[a] == c.substr(0, v[a].size()) ? 1 : v[a] == c.substr(c.size() - v[a].size()) ? -1 : -2;
            if (tp[a] == 1 && v[a] == c.substr(c.size() - v[a].size()))
                tp[a] = 0;
            tp[b] = v[b] == c.substr(0, v[b].size()) ? 1 : v[b] == c.substr(c.size() - v[b].size()) ? -1 : -2;
            if (tp[b] == 1 && v[b] == c.substr(c.size() - v[b].size()))
                tp[b] = 0;
            if (tp[a] == 0 && tp[a] == tp[b])
            {
                tp[a] = 1;
                tp[b] = -1;
            }
            else if (tp[a] != 0 && tp[b] == 0)
                tp[b] = -tp[a];
            else if (tp[a] == 0 && tp[b] != 0)
                tp[a] = -tp[b];
            else if (tp[a] == tp[b])
                tp[a] = -2;
            if (tp[a] == -2 || tp[b] == -2)
                fl = 1;
        }
        if (fl)
            continue;
        for (int i = 0; i < 2 * n - 2; ++i)
            cout << (tp[i] == 1 ? 'P' : 'S');
        break;
    }
    return 0;
}