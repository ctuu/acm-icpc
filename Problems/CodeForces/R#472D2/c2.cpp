#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
array<int, 100005> ar, ids;
double calc(double i, double j, double k)
{
    return (k - j) / (k - i);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, u;
    cin >> n >> u;
    double mef = -1.0;
    int idx = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> ar[i];
        while (u + ar[idx] < ar[i])
            ++idx;
        ids[i] = idx;
    }
    for (int i = 0; i < n; ++i)
    {
        int t = ids[i];
        if (t + 1 >= i)
            continue;
        if (t + 1 < n)
            mef = max(mef, calc(ar[t], ar[t + 1], ar[i]));
    }
    if (mef < 0)
        cout << "-1" << endl;
    else
        cout << mef << endl;
    return 0;
}