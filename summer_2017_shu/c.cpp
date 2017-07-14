#include <bits/stdc++.h>
#include <cctype>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string text;
    array<int, 26> a;
    while (cin >> text)
    {
        a.fill(0);
        for (auto i : text)
            ++a[toupper(i) - 'A'];
        // for (int i = 0; i < 26; ++i)
        //     cout << setw(2) << i << ' ';
        // cout << endl;
        // for (auto j : a)
        //     cout << setw(2) << j << ' ';
        // cout << endl;
        int to = 0;
        while (a[2] > 0 && a[4] > 1 && a[8] > 0 && a[11] > 0 && a[14] > 0 && a[18] > 0 && a[21] > 0)
        {
            ++to;
            --a[2];
            a[4] -= 2;
            --a[8];
            --a[11];
            --a[14];
            --a[18];
            --a[21];
        }
        cout << to << endl;
    }
    return 0;
}
