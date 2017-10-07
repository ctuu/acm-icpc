#include <bits/stdc++.h>
using namespace std;
struct gra{
    string id;
    int dg, cg;
};
int h, l;
array<gra, 100020> dcl;
bool comp_gra(gra a, gra b);
int jud_gra(gra n);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, minn = 0;
    cin >> n >> l >> h;
    for (int i = 0; i < n; ++i)
    {
        cin >> dcl[i].id >> dcl[i].dg >> dcl[i].cg;
        if (dcl[i].dg >= l && dcl[i].cg >= l)
            ++minn;
    }
    cout << minn << endl;
    sort(dcl.begin(), dcl.begin() + n,  comp_gra);
    for (int i = 0; i < minn; ++i)
        cout << dcl[i].id << " " <<  dcl[i].dg << " " << dcl[i].cg << " " << endl;
    return 0;
}

bool comp_gra(gra a, gra b)
{
    if (jud_gra(a) > jud_gra(b))
        return 1;
    if (jud_gra(a) == jud_gra(b))
    {
        if (a.dg + a.cg > b.dg + b.cg)
            return 1;
        else if (a.dg + a.cg == b.dg + b.cg)
        {
            if (a.dg > b.dg)
                return 1;
            else
                return a.id < b.id; 
        }
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
