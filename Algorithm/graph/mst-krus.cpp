#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
struct krus
{
    struct path
    {
        int fo;
        int to;
        int cost;
    };
    long long sum = 0;
    int n, m, total = 0;
    bool flag = 0;
    vector<int> pre;
    vector<path> roads;
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

  public:
    krus(int n, int m)
    {
        this->n = n;
        this->m = m;
        pre.resize(m);
        roads.resize(n);
        for (int i = 0; i <= m; ++i)
            pre[i] = i;
    }

    void input()
    {
        for (auto &i : roads)
            cin >> i.fo >> i.to >> i.cost;
        sort(roads.begin(), roads.end(), comp_path);
    }
    long long calc()
    {
        for (int i = 0; i < n; ++i)
        {
            if (find(roads[i].fo) != find(roads[i].to))
            {
                sum += roads[i].cost;
                join(roads[i].to, roads[i].fo);
                ++total;
            }
            if (total == m - 1)
            {
                flag = 1;
                break;
            }
        }
        return sum;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}