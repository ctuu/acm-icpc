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
    int t, b, l, r;
    char c;
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
                if (i < t)
                    t = i;
                if (j < l)
                    l = j;
                if (i > b)
                    b = i;
                if (j > r)
                    r = j;
            }
        }
        int len = min(min(n, m), max(b - t + 1, r - l + 1));
        // cout << t << " " << b << " " << l << " " << r << " " << len << endl;
    int ans = 0;
    for (int i = b; i > b - len; --i)
        for (int j = r; j > r - len; --j)
            if (ar[i][j] == 'W')
                ans++;
    if (t == l && t == r && t == b)
        cout << 0;
    else if (t == 199 && t == l && r == -1 && r == b)
        cout << 1;
    else if (b - len > t || r - len > l)
        cout << -1;
    else
        cout << ans;
    return 0;
}