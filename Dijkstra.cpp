// 邻接表
#include <bits/stdc++.h>
#define INF 0x0FFFFFFF
using namespace std;

struct edge {
    int to;
    int v = INF;
};
struct comp_path{
    bool operator()(const edge i, const edge j) const {return i.to > j.to;}
};
int dij(vector<vector<edge>> &lj, int be, int en);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int no, path, be, en;
    vector<vector<edge>> lj;
    cin >> no >> path >> be >> en;
    lj.resize(no);
    for (int i = 0; i < path; ++i)
    {
        int a;
        edge cur;
        cin >> a >> cur.to >> cur.v;
        lj[i].push_back(cur);
    }
    cout << dij(lj, be, en);
    return 0;
}
int dij(vector<vector<edge>> &lj, int be, int en)
{
    int n = lj.size();
    vector<int> rlj(n, INF);
    set<edge> mod;
    return 0;
}
