#include <iostream>
#include <algorithm>
#include <cmath>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long double k, r;
        k = (-3 + sqrt(9 + 12 * (n - 1))) / 6;
        r = (-3 - sqrt(9 + 12 * (n - 1))) / 6;
        cout << k <<  " " << r << endl;
    }
    return 0;
}