#include <bits/stdc++.h>
#include <array>
using namespace std;
const int N = 3e5 + 7;
const int M = 15e6 + 7;

array<int, M> ton;
array<int, M> p, bs;
array<int, N> a;
void pd(void)
{
	int pos = 0;
	p.fill(0);
	bs.fill(0);
	for (int i = 2; i < M; ++i)
	{
		if (!bs[i])
			bs[i] = p[++pos] = i;
		for (int j = 1; i * p[j] < M; ++j)
		{
			bs[i * p[j]] = p[j];
			if (i % p[j] == 0)
				break;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ton.fill(0);
	pd();
	int n, g = 0, ans = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		g = __gcd(g, a[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		int c = a[i] / g, x;
		while (c > 1)
			for (++ton[x = bs[c]]; bs[c] == x;)
				c /= bs[c];
	}
	for (int i = 0; i < M; ++i)
		ans = max(ans, ton[i]);
	cout << (ans ? n - ans : -1) << endl;
	return 0;
}