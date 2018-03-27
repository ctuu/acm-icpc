#include <algorithm>
#include <array>
#include <iomanip>
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
    for (int i = 0; i < n; ++i)
        cin >> ar[i];
    for (int i = 0; i < n - 2; ++i)
    {
        int k = upper_bound(ar.begin(), ar.begin() + n, ar[i] + u) - ar.begin();
        k--;
        if (k >= 0 && k < n && i + 1 < k && ar[k] - ar[i] <= u)
            mef = max(mef, calc(ar[i], ar[i + 1], ar[k]));
    }
    if (mef < 0)
        cout << "-1" << endl;
    else
        cout << fixed << setprecision(10) << mef << endl;
    return 0;
}