#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, k;
    cin >> n >> k;
    if (n == k || k == 0)
    {
        cout << 0 << " "
             << "0";
        return 0;
    }
    cout << 1 << " ";
    if (3 * k <= n)
        cout << 2 * k;
    else
    {
        k -= n /3;
            cout << 2 * (n / 3) + n%3 - k;
    }
    return 0;
}