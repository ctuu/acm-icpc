#include <bits/stdc++.h>
using namespace std;
struct path
{
    int fo;
    int to;
    int cost;
};
bool comp_path(path a, path b);
int pre[10002];
int find(int i);
bool join(int a, int b);
int value[10002];
path roads[100002];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    int total = 0;
    int sum = 1001;
    for (int i = 0; i < m; ++i)
	{
        cin >> value[i];
        sum = min(sum, value[i]);
        pre[i] = i;
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> roads[i].fo >> roads[i].to >> roads[i].cost;
        roads[i].cost = (roads[i].cost << 1) + value[roads[i].fo - 1] + value[roads[i].to - 1];
    }
    sort(roads, roads + n, comp_path);

    for (int i = 0; i < n; ++i)
    {
        if (join(roads[i].to, roads[i].fo))
        {
            sum += roads[i].cost;
            // cout << roads[i].fo << " -> " << roads[i].to << endl;
            ++total;
        }
        if (total == m - 1)
            break;
    }
    cout << sum;
    return 0;
}

bool comp_path(path a, path b)
{
    return a.cost < b.cost;
}

int find(int i)
{
    return i == pre[i] ? i: pre[i] = find(pre[i]);
}

bool join(int a, int b)
{
    int i = find(a);
    int j = find(b);
    if (i == j)
        return false;
    pre[i] = j;
    return true;
}
