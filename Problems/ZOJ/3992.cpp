#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int n, m;
        cin >> n >> m;
        cin >> s;
        int cr = 0, cl = 0;
        for (int i = 1; i < m; ++i)
            if (s[i] == 'R')
                ++cr;
        for (int i = m - 1; i < n - 1; ++i)
            if (s[i] == 'L')
                ++cl;
        cout << min(cl, cr) << endl;
    }
    return 0;
}