#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    array<bool, 43202> ar;
    ar.fill(0);
    int h, m, s, t1, t2;
    cin >> h >> m >> s >> t1 >> t2;
    if (h >= 12)
        h -= 12;
    ar[h * 3600 + m * 60 + s] = ar[m * 720 + s * 12] = ar[s * 720] = 1;
    if (t1 > t2)
    {
        t1 = t1 + t2;
        t2 = t1 - t2;
        t1 = t1 - t2;
    }
    // cout << h * 3600 + m * 60 + s << " " << m * 720 + s * 12 << " " << s * 720 << endl;
    // cout << t1 * 3600 << " " << t2 * 3600 << endl;
    bool ans = 1, bns = 1;
    for (int i = t1 * 3600; i < t2 * 3600; ++i)
        if (ar[i])
        {
            ans = 0;
            break;
        }
    for (int i = t2 * 3600; i < 43200; ++i)
        if (ar[i])
        {
            bns = 0;
            break;
        }
    for (int i = 0; i < t1 * 3600; ++i)
        if (ar[i])
        {
            bns = 0;
            break;
        }
    // cout << ans << " " << bns << endl;
    if (ans || bns)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}