#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b, c = 0, tmp, ans = 0;
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        if (tmp == 1)
        {
            if (a > 0)
                a--;
            else if (b > 0)
            {
                b--;
                c++;
            }
            else if (c > 0)
                c--;
            else
                ans++;
        }
        else
        {
            if (b > 0)
                b--;
            else
                ans += 2;
        }
    }
    cout << ans;
    return 0;
}