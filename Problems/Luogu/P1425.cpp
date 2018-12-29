#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int e = abs(a -c) - (b > d);
    int f = b > d ? 60 - b + d : d - b;
    cout << e << ' ' << f << endl;
    return 0;
}
