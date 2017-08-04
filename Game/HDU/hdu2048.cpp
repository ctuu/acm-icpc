#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        double ans = 1.0 / n;
        cout << setprecision(2) << fixed << ans * 100 << "%" << endl;
    }
    return 0;
}