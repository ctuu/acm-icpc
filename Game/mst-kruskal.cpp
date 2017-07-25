#include <bits/stdc++.h>
using namespace std;
struct path {
    int fo;
    int to;
    int cost;
};
bool comp_path(path a, path b);
vector<int> pre;
int find(int i);
void join(int a, int b);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m && n)
    {
		bool flag = 0;
		int total = 0;
    	pre.resize(m);
    	vector<path> roads;
	    for(int i = 0; i <= m; ++i)
	    {
	        pre[i] = i;
	    }
	    roads.resize(n);
	    for (auto &i: roads)
		{
			cin >> i.fo >> i.to >> i.cost;

		}
	   sort(roads.begin(), roads.end(), comp_path);
	   long long sum = 0;
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

	    if (flag)
			cout << sum << endl;
		else
			cout << "?" << endl;
	}
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
