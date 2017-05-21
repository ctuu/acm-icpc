#include <bits/stdc++.h>
using namespace std;
struct gra{
    string id;
    int dg, cg;
};
int h, l;
bool comp_gra(gra a, gra b);
int jud_gra(gra n);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, minn = 0;
    vector <vector<gra>> grou(4);
    gra te;
    cin >> n >> l >> h;
    for (int i = 0; i < n; ++i)
    {
        cin >>te.id >> te.dg >> te.cg;
        if (jud_gra(te) > -1)
        {
            grou[3 - jud_gra(te)].push_back(te);
            ++minn;
        }
    }
    cout << minn << endl;
    for (auto n: grou)
    {
        sort(n.begin(), n.end(), comp_gra);
        for (auto i : n)
            cout << i.id << " " << i.dg << " " << i.cg << endl;
    }
    return 0;
}

bool comp_gra(gra a, gra b)
{
    if (a.dg + a.cg > b.dg + b.cg)
        return 1;
    else if (a.dg + a.cg == b.dg + b.cg)
    {
        if (a.dg > b.dg)
            return 1;
        else if (a.dg == b.dg)
            return a.id < b.id; 
    }
    return 0;
}

int jud_gra(gra n)
{
    if (n.dg < l || n.cg < l)
        return -1;
    if (n.dg >= h && n.cg >= h)
        return 3;
    if (n.dg >= h && n.cg >= l)
        return 2;
    if (n.dg >= l && n.cg >= l && n.dg >= n.cg)
        return 1;
    return 0;
}
