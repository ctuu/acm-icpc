#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a, b, c;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a >> b >> c;
        cout << "Case #" << i << ": ";
        if ( a + b > c)
            cout << "true";
        else
            cout << "false";
            cout << endl;
    }
    return 0;
}
