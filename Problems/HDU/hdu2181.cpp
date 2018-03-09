#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
array<set<int>, 21> ar;
int ct = 0;
struct Po
{
    int d, c, m;
    string s;
    array<bool, 21> v;
};
void dfs(Po a)
{
    for (auto i : ar[a.c])
    {
        if (a.d == 19 && i == a.m)
            cout << ++ct << ":  " << a.s << " " << a.m << endl;
        if (!a.v[i])
        {
            Po cu = a;
            cu.v[i] = 1;
            cu.c = i;
            cu.s += " " + to_string(i);
            cu.d++;
            dfs(cu);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, m;
    for (int i = 1; i < 21; ++i)
    {
        cin >> a >> b >> c;
        ar[i].insert(a);
        ar[i].insert(b);
        ar[i].insert(c);
    }
    array<bool, 21> vis;
    vis.fill(0);
    while (cin >> m && m != 0)
    {
        ct = 0;
        Po tmp;
        tmp.d = 0;
        tmp.c = tmp.m = m;
        tmp.s = to_string(m);
        tmp.v = vis;
        tmp.v[m] = 1;
        dfs(tmp);
    }
    return 0;
}