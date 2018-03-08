#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int gcd(int a, int b) { return a == 0 ? b : gcd(b % a, a); }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ti, tj;
    double sum = 0;
    for (int i = n; i >= 0; --i)
    {
            if (gcd(i, n - i) == 1 && i >= n - i)
            if (sum < (double) (n - i) / (double) i)
            {
                sum = (double) (n - i) / (double) i;
                ti = i;
                tj = n - i;
            }
    }
    cout << tj << " " << ti;
    return 0;
}