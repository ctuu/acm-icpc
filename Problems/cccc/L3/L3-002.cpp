#include <algorithm>
#include <array>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const int N = 100005;
int n;
array<int, N> atr;
stack<int> sk;
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

int query()
{
    int si = sk.size();
    si = (si + si % 2) / 2;
    int l = 1, r = N, m;
    while (l < r)
    {
        m = (l + r) / 2;
        if (sum(m) >= si)
            r = m;
        else
            l = m + 1;
    }
    return l;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, a;
    string s;
    atr.fill(0);
    n = N - 1;
    cin >> t;
    while (t--)
    {
        bool fl = 0;
        cin >> s;
        if (s == "Pop")
        {
            if (sk.empty())
                fl = 1;
            else
            {
                cout << sk.top() << '\n';
                add(sk.top(), -1);
                sk.pop();
            }
        }
        else if (s == "Push")
        {
            cin >> a;
            add(a, 1);
            sk.push(a);
        }
        else
        {
            if (sk.empty())
                fl = 1;
            else
                cout << query() << '\n';
        }
        if (fl)
            cout << "Invalid" << '\n';
    }
    return 0;
}