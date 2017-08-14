#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, k, ti = 0;
    while (cin >> n >> k)
    {
        ++ti;
        cout << "Case #" << ti << ": ";
        if (k <= n)
            cout << k;
        else
        {
            int i = (k - n) % (n - 1);
            if (i == 0)
            {
                if ((k - n) / (n - 1)& 1)
                    cout << n - 1;
                else
                    cout << n;
            }
            else
                cout << i;
        }
        cout << endl;
    }
    return 0;
}