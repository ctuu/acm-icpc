#include <iostream>
#include <cmath>
#include <string>
#include <array>
using namespace std;
const int N = 2e5 + 7;
array<int, N> ru, rd, rl, rr;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ru.fill(0);
    rd.fill(0);
    rl.fill(0);
    rr.fill(0);
    int n, rx, ry, t = 0;
    string s;
    cin >> n >> s;
    cin >> rx >> ry;
    if ((abs(rx) + abs(ry)) % 2 != n % 2)
    {
        cout << "-1" << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        t = s[i - 1] == 'U' ? 1 : s[i - 1] == 'D' ? 2 : s[i - 1] == 'L' ? 4 : 8;
        ru[i] = ru[i - 1] + (t == 1);
        rd[i] = rd[i - 1] + (t == 2);
        rl[i] = rl[i - 1] + (t == 4);
        rr[i] = rr[i - 1] + (t == 8);
    }
    int ans = n + 1;
    for (int i = 0; i <= n; ++i)
    {
        int cx = rr[i] - rl[i];
        int cy = ru[i] - rd[i];
        int l = i, r = n + 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            int bx = rr[n] - rl[n] - (rr[mid] - rl[mid]) + cx;
            int by = ru[n] - rd[n] - (ru[mid] - rd[mid]) + cy;
            int cx = abs(rx - bx) + abs(ry - by);
            if (mid - i >= cx)
            {
                r = mid;
                ans = min(ans, mid - i);
            }
            else
                l = mid + 1;
        }
    }
    cout << (ans == n + 1 ? -1 : ans) << endl;
    return 0;
}
