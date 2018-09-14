#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, h, a, b, k;
    cin >> n >> h >> a >> b >> k;
    for (int i = 0; i < k; ++i)
    {
        int t1, f1, t2, f2;
        cin >> t1 >> f1 >> t2 >> f2;
        if (t1 == t2)
        {
            cout << abs(f1 - f2) << endl;
            continue;
        }
        if (f1 >= a && f1 <= b)
        {
            cout << abs(t2 - t1) + abs(f1 - f2) << endl;
            continue;
        }
        int tr = abs(f1 - a) < abs(f1 - b) ? a : b;
        cout << abs(f1 - tr) + abs(t2 - t1) + abs(f2 - tr) << endl;
    }
    return 0;
}