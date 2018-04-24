#include <algorithm>
#include <array>
#include <iostream>
using namespace std;

int com(int n, int m)
{
    m = min(m, n - m);
    int s = 1;
    for (int i = 1; i <= m; ++i)
        s = s * (n - i + 1) / i;
    return s;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m)
    {
        if (n == -1 && m == -1)
            return 0;
        if (n + m == com(n + m, n))
            cout << n << "+" << m << "=" << n + m << endl;
        else
            cout << n << "+" << m << "!=" << n + m << endl;
    }
    return 0;
}