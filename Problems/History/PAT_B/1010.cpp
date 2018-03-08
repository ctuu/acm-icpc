#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x, y;
    int i = 0;
    while ( cin >> x >> y)
    {
        if (y == 0)
            continue;
        if (i)
            cout << " ";
        i = 1;
        cout << x * y << " " << y - 1;
    }
    if (!i)
        cout << "0 0";
    return 0;
}
