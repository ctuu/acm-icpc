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
    }
    for (int i = 0; i < n; ++i)
    {
        int idx = 0;
        while (u < ar[i] - ar[idx])
            ++idx;
        if (idx + 1 >= i)
            continue;
        mef = max(mef, calc(ar[idx], ar[idx + 1], ar[i]));
        while (idx + 2 < i)
        {
            double b = calc(ar[idx + 1], ar[idx + 2], ar[i]);
            mef = max(mef, b));
            idx++;
        }
    }
    if (mef < 0)
        cout << "-1" << endl;
    else
        cout << mef << endl;
    return 0;
}