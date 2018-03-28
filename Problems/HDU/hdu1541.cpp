#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
const int N = 32003;
array<int, N> atr;
array<int, 15003> sr;
int n;
int lowbit(int x)
{
    return x & -x;
}

void add(int x, int v)
{
    for (int i = x; i <= N; i += lowbit(i))
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
    while (cin >> n)
    {
        int a, b;
        sr.fill(0);
        atr.fill(0);
        for (int i = 0; i < n; ++i)
        {
            cin >> a >> b;
            a++;
            b++;
            sr[sum(a)]++;
            add(a, 1);
        }
        for (int i = 0; i < n; ++i)
            cout << sr[i] << endl;
    }
    return 0;
}