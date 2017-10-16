#include <iostream>
#include <algorithm>
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
        bool fl = 1;
        int n;
        cin >> n;
        int a = n / 4, b = n % 4;
        if (b == 1)
        {
            if (a - 2 < 0)
            fl = 0;
            a--;
        }
        if (b == 2)
            if (a - 1 < 0)
                fl = 0;
        if (b == 3)
        {
            if (a - 3 < 0)
            fl = 0;
            a--;
        }
        if (fl)
            cout << a << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}