#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x, y;
    cin >> x >> y;
    double ans = y * log(x) - x * log(y);
    cout << (ans == 0 ? '=' : ans > 0 ? '>' : '<') << endl;
    return 0;
}
