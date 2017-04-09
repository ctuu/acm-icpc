#include <bits/stdc++.h>
using namespace std;
struct path
{
    int fo;
    int to;
    int cost;
};
bool comp_path(path a, path b);
array<int, 10002> pre;
int find(int i);
void join(int a, int b);
array<long long, 10002> value;
array<path, 100002> roads;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    int total = 0;
    long long sum = 1001;
    for (int i = 0; i < m; ++i)
	{
        cin >> value[i];
        sum = min(sum, value[i]);
        pre[i] = i;
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> roads[i].fo >> roads[i].to >> roads[i].cost;
        roads[i].cost = roads[i].cost * 2 + value[roads[i].fo - 1] + value[roads[i].to - 1];
    }
    sort(roads.begin(), roads.begin() + n, comp_path);

    for (int i = 0; i < n; ++i)
    {
        if (find(roads[i].fo) != find(roads[i].to))
        {
            sum += roads[i].cost;
            join(roads[i].to, roads[i].fo);
            cout << roads[i].fo << " -> " << roads[i].to << endl;
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
    while (pre[i] != i)
        i = pre[i];
    return i;
}

void join(int a, int b)
{
    int i, j;
    i = find(a);
    j = find(b);
    pre[i] = j;
}
