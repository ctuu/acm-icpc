#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    array<string, 505> ar;
    for (int t = 1; t <= T; ++t)
    {
        int n, ans = -1;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> ar[i];
        for (int i = 1; i < n; ++i)
        {
            if (ar[i + 1].find(ar[i]) == string::npos)
            {
                ans = max(ans, i + 1);
                for (int j = i + 2; j <= n; ++j)
                    if (ar[j].find(ar[i]) == string::npos)
                        ans = max(ans, j);
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}