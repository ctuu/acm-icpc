#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, t = 0;
    long long a, b;
    for (cin >> T; T > t;)
    {
        cin >> a >> b;
        cout << "Case #" << ++t << ":\n";
        if (a == b)
            cout << "1\n"
                 << a << " " << b << endl;
        else
            cout << "2\n" << a << " " << b << endl << b << " " << a << endl;
    }
    return 0;
}