#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int ans = s[0] - 'a' + k;
    char tw = s[0];
    for (int i = 1; k > 1 && i < n; ++i)
        if (s[i] - tw > 1)
        {
            ans += s[i] - 'a';
            k--;
            tw = s[i];
        }
    if (k > 1)
        cout << "-1" << endl;
    else
        cout << ans << endl;
}