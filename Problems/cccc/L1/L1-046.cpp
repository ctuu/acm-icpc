#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, dig = 1, g = 1;
    cin >> n;
    for (int i = n; i; i /= 10)
    {
        g = g * 10 + 1;
        ++dig;
    }
    if (n == g / 10)
    {
        cout << "1 " << --dig << endl;
        return 0;
    }
    while (1)
    {
        cout << g / n;
        g %= n;
        if (g == 0)
            break;
        g = g * 10 + 1;
        ++dig;
    }
    cout << " " << dig << endl;
    return 0;
}