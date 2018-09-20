#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    a = a + b - c;
    if (a > (n - 1) || a + c - b < c || b < c)
        cout << "-1" << endl;
    else
        cout << n - a << endl;
    return 0;
}