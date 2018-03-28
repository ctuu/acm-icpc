#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int n;
const int N = 100005;
array<int, N> atr;
int lowbit(int x)
{
    return x & -x;
}
void add(int x, int v)
{
    for (int i = x; i <= n; i += lowbit(i))
        atr[i] += v;
}
int sum(int x)
{
    int s = 0;
    for (int i = x; i; i -= lowbit(i))
        s += atr[i];
    return s;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    while (cin >> n && n)
    {
        atr.fill(0);
        for (int i = 0; i < n; ++i)
        {
            cin >> a >> b;
            add(a, 1);
            add(b + 1, -1);
        }
        for (int i = 1; i <= n; ++i)
        {
            if (i > 1)
                cout << " ";
            cout << sum(i);
        }
        cout << endl;
    }
    return 0;
}