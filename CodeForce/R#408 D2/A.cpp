#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
	cin >> n >> m >> k;
	int a[101];
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int le = m - 1, ri = m + 1;
	int min = 200;
	for (;min == 200; le = (le > 0)? le - 1 : 0, ri = (ri <= n) ? ri + 1 : n+1)
	{
		if (le > 0)
			if(a[le] && k >= a[le])
				min = (abs(min - m) < abs(le - m))? min : le;
		if (ri <= n)
			if(a[ri] && k >= a[ri])
				min = (abs(min - m) < abs(ri - m))? min : ri;
	}
	cout << abs(min - m) * 10;
    return 0;
}
