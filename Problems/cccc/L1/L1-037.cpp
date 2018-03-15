#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    if (b != 0)
    {
        double c = a / (double)b;
        cout << a << "/";
        if (b > 0)
            cout << b;
        else
            cout << "(" << b << ")";
        cout << "=" << fixed << setprecision(2) << c << endl;
    }
    else
        cout << a << "/" << b << "=Error" << endl;
    return 0;
}