#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
#define N 20000
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    array<bool, N + 5> mrk;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        mrk.fill(0);
        int n, a, b, ti = 0;
        cin >> n >> a >> b;
        ti = n / __gcd(a, b);
        cout << "Case #" << t << ": ";
        if (ti & 1)
            cout << "Yuwgna" << endl;
        else
            cout << "Iaka" << endl;
    }
    return 0;
}