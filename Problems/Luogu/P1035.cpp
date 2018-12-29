#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    double d;
    for (int i = 1; d <= k && i < 10000000; ++i)
    {
        d += 1.0 / i;
        if (d > k)
            cout << i;
    }
    return 0;
}