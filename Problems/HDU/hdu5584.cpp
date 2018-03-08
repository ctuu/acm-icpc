#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int ans = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        ans = 1;
        int n, m, k;
        cin >> n >> m;
        if (n < m)
            swap(n, m);
        k = __gcd(n, m);
        while (n % (m+ k)== 0)
        {
            ++ans;
            n /= m / k + 1;
            if (n < m)
                swap(n, m);
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}