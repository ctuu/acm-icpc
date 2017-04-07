#include <bits/stdc++.h>
#define MNUM 102
#define INF 0x03ffffff
using namespace std;

struct path
{
    int a, b, cost;
};
struct comp_path
{
    bool operator()(const path i, const path j) const
    {
	return i.cost < j.cost;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
	vector<int> ti;
	ti.push_back(0);
	for (int c = 1; c <= n; ++c)
		{
			int l;
			cin >> l;
			ti.push_back(l);
		}
	array<array<int, MNUM>, MNUM> lj;
    array<int, MNUM> rlj;

    rlj.fill(INF);
    for (auto &i : lj)
	i.fill(0);
    rlj[1] = 0;

    while (m--)
    {
	int a, b, c;
	cin >> a >> b >> c;
	if (lj[a][b])
	    lj[a][b] = lj[b][a] = min(c, lj[a][b]);
	else
	    lj[a][b] = lj[b][a] = c;
    }

    int cur = 1;
    int tot = 0;
    set<int> vied;
    vied.insert(1);
    int sum = 0;
    while (tot < n && vied.size() < n)
    {
		set<path, comp_path> sel;
		for (auto i : vied)
		{
		    path temp;
		    for (int j = 1; j <= n; ++j)
			if (lj[i][j])
			{
			    temp.a = i;
			    temp.b = j;
			    temp.cost = lj[i][j];
			    sel.insert(temp);
			}
		}
		path temp = *sel.begin();
		sum += 2 * temp.cost + ti[temp.a] + ti[temp.b];
		lj[temp.a][temp.b] = lj[temp.b][temp.a] = 0;
		vied.insert(temp.a);
		vied.insert(temp.b);
		++tot;
    }
    sort(ti.begin(), ti.end());
    cout << sum+ti[1];
    return 0;
}
