#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    cin >> t;
    string s;
    while (t--)
    {
        cin >> n;
        cin >> s;
        bool fl = 0;
        int sum = 0;
        for (int i = 0; i < n - 3; ++i)
            if (s[i] == 'C' && s[i + 1] == 'C' && s[i + 2] == 'P' && s[i + 3] == 'C')
                sum++;
        for (int i = 0; i < n - 2; ++i)
        {
            if (s[i] == 'C' && s[i + 1] == 'C' && s[i + 2] == 'C')
            {
                if (i + 3 >= n || s[i + 3] != 'P')
                    fl = 1;
            }
            else if (s[i] == 'C' && s[i + 1] == 'C' && s[i + 2] == 'P')
            {
                if (i + 3 >= n || s[i + 3] != 'C')
                    fl = 1;
            }
            else if (s[i] == 'C' && s[i + 1] == 'P' && s[i + 2] == 'C')
            {
                if (i - 1 < 0 || s[i - 1] != 'C')
                    fl = 1;
            }
        }
        cout << sum + fl << endl;
    }
    return 0;
}