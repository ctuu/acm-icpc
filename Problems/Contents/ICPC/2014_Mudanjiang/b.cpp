#include <iostream>
#include <algorithm>
#include <array>
#include <queue>
#include <vector>
#define MP 200002
using namespace std;
array<vector<int>, MP> ar;
array<int, MP> dis;
int mid_find(int leaf, int len);
int bfs(int init);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n, a, b;
        cin >> n;
        for (int i = 0; i <= n; ++i)
            ar[i].clear();
        for (int i = 1; i < n; ++i)
        {
            cin >> a >> b;
            ar[a].push_back(b);
            ar[b].push_back(a);
        }
        a = bfs(1);
        b = bfs(a);
        int rd = 0, rc, lc;
        int l, r, md = (dis[b] + 1) / 2;
        l = mid_find(b, md);
        for (auto i : ar[l])
            if (dis[i] < dis[l])
            {
                r = i;
                break;
            }
        ar[r].erase(find(ar[r].begin(), ar[r].end(), l));
        ar[l].erase(find(ar[l].begin(), ar[l].end(), r));

        if (ar[l].size() != 0)
        {
            a = bfs(l);
            b = bfs(a);
            md = (dis[b] + 1) / 2;
            lc = mid_find(b, md);
            rd = max(rd, max(dis[lc], dis[b] - dis[lc]));
        }
        else
            lc = l;
        if (ar[r].size() != 0)
        {
            a = bfs(r);
            b = bfs(a);
            md = (dis[b] + 1) / 2;
            rc = mid_find(b, md);
            rd = max(rd, max(dis[rc], dis[b] - dis[rc]));
        }
        else
            rc = r;
        if (rc > lc)
            swap(rc, lc);
        cout << rd << " " << rc << " " << lc << endl;
    }
    return 0;
}

int bfs(int init)
{
    queue<int> qu;
    dis.fill(0);
    for (auto i : ar[init])
    {
        qu.push(i);
        dis[i] = dis[init] + 1;
    }
    int mdis = qu.front();
    while (!qu.empty())
    {
        int tmp = qu.front();
        qu.pop();
        for (auto i : ar[tmp])
        {
            if (!dis[i] && i != init)
            {
                qu.push(i);
                dis[i] = dis[tmp] + 1;
                if (dis[mdis] < dis[i])
                    mdis = i;
            }
        }
    }
    return mdis;
}

int mid_find(int leaf, int len)
{
    int pin = leaf;
    while (dis[pin] > len)
        for (auto i : ar[pin])
            if (dis[i] < dis[pin])
            {
                pin = i;
                break;
            }
    return pin;
}