#include <bits/stdc++.h>
using namespace std;
struct path{
	int a;
	int b;
 
};
struct comp {
	bool operator()(const path i, const path j) const
	{
	return i.b < j.b;
	}
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    set<path, comp> road;
    int k = 4;
    while (k--)
    {
    	path temp;
		cin >> temp.a >> temp.b;
		road.insert(temp);
	}
	for (auto i: road)
	cout << i.a << " " << i.b << endl;
    cout << "Hello";
    return 0;
}

bool comp(path i, path j)
{
	return i.b < j.b;
}
