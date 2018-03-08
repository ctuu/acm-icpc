#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   	long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a < c)
        cout << a << " " << b << " " << c << " " << d;
    else if (a > c)
        cout << c << " " << d << " " << a << " " << b;
    else if (b >= d)
        cout << a << " " << b << " " << c << " " << d;
    else
        cout << c << " " << d << " " << a << " " << b;
    return 0;
}