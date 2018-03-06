#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define N 3000
#define SI 110
#define G pair<vector<Edge>, int>
int p[N];
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
struct Edge
{
    int u, v, c;
    Edge(){};
    Edge(int u, int v, int c) : u(u), v(v), c(c) {}
};
bool cmp(Edge a, Edge b)
{
    return a.c < b.c;
}
int mst(G &gr)
{
    for (int i = 0; i < N; ++i)
        p[i] = i;
    int sum = 0, ct = 0;
    vector<Edge> pa = gr.first;
    sort(pa.begin(), pa.end(), cmp);
    int tmp = pa.size();
    for (int i = 0; i < tmp; ++i)
    {
        Edge e = pa[i];
        int u = find(e.u), v = find(e.v);
        if (u == v)
            continue;
        p[u] = v;
        ++ct;
        sum += e.c;
    }
    return sum;
}

struct Po
{
    int x, y, w, l;
    Po(int x, int y, int w, int l) : x(x), y(y), w(w), l(l) {}
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        char maze[SI][SI];
        int n, m, si = 0;
        // cin >> m >> n;
        scanf("%d %d\n",&m,&n); 
        // gets(maze[0]);
        G gr;
        vector<Po> pos;
        for (int i = 0; i < n; ++i)
        {
            gets(maze[i]);
            for (int j = 0; j < m; ++j)
                if (maze[i][j] == 'S' || maze[i][j] == 'A')
                    pos.push_back(Po(i, j, 0, si++));
        }
        // cout << "!!!!!!!" << endl;
        // for (int i = 0; i < n; ++i, cout << endl)
        //     for (int j = 0; j < m; ++j)
        //         cout << maze[i][j];
        // cout << "&&&&&&&" << endl;
        for (int t = 0; t < si; ++t)
        {
            queue<Po> aq;
            bool vis[SI][SI];
            for (int i = 0; i < SI; ++i)
                for (int j = 0; j < SI; ++j)
                    vis[i][j] = 0;
            aq.push(pos[t]);
            vis[pos[t].x][pos[t].y] = 1;
            while (!aq.empty())
            {
                Po tmp = aq.front();
                aq.pop();
                if (maze[tmp.x][tmp.y] == '#')
                    continue;
                else if (maze[tmp.x][tmp.y] == 'A' || maze[tmp.x][tmp.y] == 'S')
                {
                    int k;
                    for (k = 0; k < si; ++k)
                        if (tmp.x == pos[k].x && tmp.y == pos[k].y)
                            break;
                    if (k != t)
                        gr.first.push_back(Edge(t, k, tmp.w));
                }

                if (tmp.x + 1 < n && !vis[tmp.x + 1][tmp.y])
                {
                    aq.push(Po(tmp.x + 1, tmp.y, tmp.w + 1, tmp.l));
                    vis[tmp.x + 1][tmp.y] = 1;
                }
                if (tmp.x - 1 > -1 && !vis[tmp.x - 1][tmp.y])
                {
                    aq.push(Po(tmp.x - 1, tmp.y, tmp.w + 1, tmp.l));
                    vis[tmp.x - 1][tmp.y] = 1;
                }
                if (tmp.y + 1 < m && !vis[tmp.x][tmp.y + 1])
                {
                    aq.push(Po(tmp.x, tmp.y + 1, tmp.w + 1, tmp.l));
                    vis[tmp.x][tmp.y + 1] = 1;
                }
                if (tmp.y - 1 > -1 && !vis[tmp.x][tmp.y - 1])
                {
                    aq.push(Po(tmp.x, tmp.y - 1, tmp.w + 1, tmp.l));
                    vis[tmp.x][tmp.y - 1] = 1;
                }
            }
        }

        gr.second = si;
        int ans = mst(gr);
        cout << ans << endl;
    }
    return 0;
}