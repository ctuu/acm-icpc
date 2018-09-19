#include <iostream>
#include <array>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    double m;
    cin >> n >> m;
    vector<double> a, b;
    a.resize(n);
    b.resize(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    double ans = 0;
    double cf = m / (b[0] - 1);
    ans += cf;
    m += cf;
    for (int i = n - 1; i >= 0; --i)
    {
        cf = m / (a[i] - 1);
        ans += cf;
        m += cf;
        if (i < 1)
            continue;
        cf = m / (b[i] - 1);
        ans += cf;
        m += cf;
    }
    if (isinf(ans))
        cout << "-1" << endl;
    else
        cout << fixed << setprecision(10) << ans << endl;
    return 0;
}