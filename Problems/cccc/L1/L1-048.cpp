#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    array<array<int, 103>, 103> a, b, c;
    int n, m, o, p;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    cin >> o >> p;
    if (m != o)
    {
        cout << "Error: " << m << " != " << o << endl;
        return 0;
    }
    for (auto &i : c)
        i.fill(0);
    for (int i = 0; i < o; ++i)
        for (int j = 0; j < p; ++j)
            cin >> b[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < p; ++j)
            for (int k = 0; k < m; ++k)
                c[i][j] += a[i][k] * b[k][j];
    cout << n << " " << p << endl;
    for (int i = 0; i < n; ++i)
    {
        if (i)
            cout << endl;
        for (int j = 0; j < p; ++j)
        {
            if (j)
                cout << " ";
            cout << c[i][j];
        }
    }
    return 0;
}