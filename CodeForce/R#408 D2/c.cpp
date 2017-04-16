#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <algorithm>
#define INF 0x3FFFFFFF
using namespace std;
struct node {
    int id;
    set<int> con;
    int v;
}; 
vector<node> gr;
array<bool, 300010> xued;
bool comp_node(node a, node b);
bool comp_cone(node a, node b);
void xu1s(int cid, set<int> con);
int main()
{
    int n;
    cin >> n;
    gr.resize(n);
    int max = -INF;
    for (int i  = 0; i < n; ++i)
    {
        cin >> gr[i].v;
        max = (max, gr[i].v);
        gr[i].id = i;
    }
    for (int i  = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        gr[a].con.insert(b);
        gr[b].con.insert(a);
    }
    vector<node> grte;
    for (int ct = n; ct > 0; --ct)
    {
        grte = gr;
        sort(grte.begin(), grte.end(), comp_node);
        xued.fill(0);
        if (grte[0].v >= max)
        {
            max = grte[0].v;
            int cid = grte[0].id;
            xu1s(cid, gr[cid].con);
            gr[cid].con.clear();
            gr[cid].v = 0;
        }        
        else 
        {
            sort (grte.begin(), grte.end(), comp_cone);
            int cid = grte[0].id;
            xu1s(cid, gr[cid].con);
            gr[cid].con.clear();
            gr[cid].v = 0; 
        }
        for (int w = 0; w < n; ++w)
            cout << w << " " << gr[w].v << " --"; 
            cout << endl;
    }
    cout << max;
    return 0;
}
bool comp_node(node a, node b)
{
    if (a.v > b.v)
        return 1;
    else if (a.v == b.v && a.con.size() > b.con.size())
        return 1;
    return 0;
}
bool comp_cone(node a, node b)
{
    if (a.con.size(), b.con.size())
        return 1;
    return 0;
}
void xu1s(int cid, set<int> con)
{
    for (auto c: con)
    {
        if (xued[c] == 0)
        {
            ++gr[c].v;
            xued[c] = 1;
            xu1s(cid, gr[c].con);
        }
        if (gr[c].con.count(cid))
            gr[c].con.erase(cid);
    }
}
