#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x;
    cin >> x;
    if (x <= 1)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << x << ' ' << x << endl;
    return 0;
}