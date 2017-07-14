#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    array<int, 102> a;
    int m, n, k;
    while (cin >> m >> n)
    {
        a.fill(0);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (cin >> k, k == 1)
                    ++a[j];
        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
                cout << ' ';
            cout << a[i];
        }
        cout << endl;
    }
    return 0;
}