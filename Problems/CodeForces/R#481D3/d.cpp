#include <array>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 7;
const int INF = 0x3f3f3f3f;
array<int, N> a;
int n;
int chk(array<int, N> &a, int js)
{
    int ans = 0, t;
    for (int i = 1; i < n; ++i)
    {
        t = a[i] - a[i - 1];
        if (t == js)
            continue;
        if (t + 1 == js)
        {
            ans++;
            a[i]++;
        }
        else if (t - 1 == js)
        {
            ans++;
            a[i]--;
        }
        else
            return INF;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (n <= 2)
    {
        cout << "0" << endl;
        return 0;
    }
    int ans = INF;
    for (int i = -1; i < 2; ++i)
        for (int j = -1; j < 2; ++j)
        {
            auto b = a;
            b[1] += i;
            b[0] += j;
            int js = b[1] - b[0];
            int t = chk(b, js);
            t = i == 0 ? t : t + 1;
            t = j == 0 ? t : t + 1;
            ans = min(ans, t);
        }
    ans = ans == INF ? -1 : ans;
    cout << ans << endl;
    return 0;
}