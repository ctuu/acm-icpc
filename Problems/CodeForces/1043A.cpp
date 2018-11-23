#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, sum = 0, ma = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        ma = max(ma, t);
        sum += t;
    }
    int crs = (2 * sum) / n + ((2 * sum) % n ? 1 : 0);
    if (crs * n == 2 * sum)
        ++crs;
    cout << max(ma, crs) << endl;
    return 0;
}