#include <array>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    long long sum = 0;
    long long neg = 0, pos = 0;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        sum += x * n;
        neg += y > 0 ? 0 : y;
        pos += y > 0 ? y : 0;
    }
    sum += n * (n - 1) / 2 * pos;
    if (n % 2)
        sum += n / 2 * (n / 2 + 1) * neg;
    else
        sum += ((n - 1) / 2 * ((n - 1) / 2 + 1) + n / 2) * neg;
    double ans = sum * 1.0 / n;
    cout << fixed << setprecision(14) << ans << endl;
    return 0;
}