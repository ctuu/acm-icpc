#include <bits/stdc++.h>
using namespace std;
int a[1000002];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 1000002; ++i)
		a[i] = i;
	int n, m, k;
	int max = 0;
	cin >> n >> m >> k;
	while (m--)
	{
		int i;
		cin >> i;
		max = (max > i) ? max:i;
	}

	while (k--)
	{
		int i, j, te;
		cin >> i >> j;
		te = a[j];
		a[j] = a[i];
		a[i] = te;
	}
	cout << a[1];
    return 0;
}
