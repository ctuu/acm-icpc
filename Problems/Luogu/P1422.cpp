#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    double n, ans = 0;
    cin >> n;
    if (n <= 150)
        ans = 0.4463 * n;
    else if (n > 400)
        ans = 0.5663 * (n - 400) + 150 * 0.4463 + (400 - 150) * 0.4663;
    else
        ans = 0.4663 * (n - 150) + 150 * 0.4463;
    cout << fixed << setprecision(1) << ans << endl;
    return 0;
}
