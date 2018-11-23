#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, m, k, l;
    cin >> n >> m >> k >> l;
    long long ans = (k + l) / m + ((k + l) % m ? 1 : 0);
    if (m > n || k + l > n || ans * m > n)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}