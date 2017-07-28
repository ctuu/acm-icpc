#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y, s = 0;
        cin >> n >> x >> y;
        string a, b;
        cin >> a >> b;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] != b[i])
                ++s;
        }
        if (s == abs(x - y) && x >=s && y >= s) 
            cout << "Not lying" << endl;
        else
            cout << "Lying" << endl;
    }
    return 0;
}