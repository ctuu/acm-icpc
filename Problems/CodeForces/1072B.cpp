#include <iostream>
#include <array>
using namespace std;
const int N = 1e5 + 7;

array<int, N> a, b;
array<array<int, 4>, N> t;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (auto &i : t)
        i.fill(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i)
        cin >> b[i];
    t[n - 1].fill(1);
    for (int i = n - 2; i >= 0; --i)
    {
        for (auto j : {0, 1, 2, 3})
            if (t[i + 1][j] > 0)
                for (auto k : {0, 1, 2, 3})
                    if ((j & k) == b[i + 1] && (j | k) == a[i + 1])
                        t[i][k] = max(t[i][k], t[i + 1][j] + 1);
    }
    int mk = 0;
    for (; mk < 4 && t[0][mk] != n; ++mk)
        ;
    if (mk > 3)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    cout << mk;
    for (int i = 1; i < n; ++i)
    {
        mk = a[i] - mk + b[i];
        cout << ' ' << mk;
    }
    return 0;
}