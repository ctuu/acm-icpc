#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
const double G = 9.8;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double w, p;
    cin >> w >> p;
    w /= 100;
    p /= 100;
    double e = 1000;
    double s = 0;
    while (e > 10e-9)
    {
        s += 2 * e / (w * G);
        e *= (1 - p);
    }
    cout << fixed << setprecision(3) << s << endl;
    return 0;
}