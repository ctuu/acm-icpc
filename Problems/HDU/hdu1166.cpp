#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
const int N = 50005;
array<int, N> atr;
int n;
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
    int T, a, b;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cout << "Case " << t << ":" << endl;
        cin >> n;
        string sl;
        atr.fill(0);
        for (int i = 1; i <= n; ++i)
        {
            cin >> a;
            add(i, a);
        }
        while (cin >> sl && sl != "End")
        {
            cin >> a >> b;
            if (sl == "Add")
                add(a, b);
            else if (sl == "Sub")
                add(a, -b);
            else
                cout << sum(b) - sum(a-1) << endl;
        }
    }
    return 0;
}