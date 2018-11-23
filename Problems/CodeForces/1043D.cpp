#include <array>
#include <iostream>
using namespace std;
const int N = 1e5 + 7;
array<array<int, N>, 10> a, b;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
            b[i][a[i][j]] = j;
        }
    long long ans = n, ct = 1;
    for (int i = 1; i < n; ++i)
    {
        auto &la = a[0][i - 1];
        auto &c = a[0][i];
        bool fl = 1;
        for (int j = 1; j < m; ++j)
            if (b[j][la] != b[j][c] - 1)
            {
                fl = 0;
                break;
            }
        if (fl)
            ++ct;
        else
        {
            ans += ct * (ct - 1) / 2;
            ct = 1;
        }
    }
    ans += ct * (ct - 1) / 2;
    cout << ans << endl;
    return 0;
}