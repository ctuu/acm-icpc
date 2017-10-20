#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    int t, b, l, r, sum = 0;
    char c;
    bool hasb = 0;
    array<array<char, 103>, 103> ar;
    t = l = 199;
    b = r = -1;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            cin >> c;
            ar[i][j] = c;
            if (c == 'B')
            {
                ++sum;
                t = min(i, t);
                l = min(j, l);
                b = max(i, b);
                r = max(j, r);
            }
        }
    int len = max(b - t + 1, r - l + 1);
    if (!sum)
        cout << 1;
    else if (len > n || len > m)
        cout << -1;
    else
        cout << len * len - sum;
    return 0;
}