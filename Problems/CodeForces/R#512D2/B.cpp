#include <iostream>
#include <array>
using namespace std;
const int N = 107;
array<array<bool, N>, N> ar;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (auto &i : ar)
        i.fill(0);
    int n, d, x, y;
    cin >> n >> d;
    x = 0, y = d;
    for (int i = d; i <= n; ++i)
    {
        x = i - d;
        y = i;
        for (int j = 0; j < d + 1; ++j)
        {
            ar[x][y] = 1;
            x++;
            y--;
        }
    }
        for (int i = d; i < n; ++i)
    {
        x = i - d+1;
        y = i;
        for (int j = 0; j < d; ++j)
        {
            ar[x][y] = 1;
            x++;
            y--;
        }
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> x >> y;
        if (ar[x][y])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}