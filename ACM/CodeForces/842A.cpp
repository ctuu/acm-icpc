#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int l, r, x, y, k;
    cin >> l >> r >> x >> y >> k;
    bool fl = 0;
    for (long long i = x; i <= y; ++i)
        if (i * k >= l && i * k <= r)
            fl = 1;
    if (fl)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}