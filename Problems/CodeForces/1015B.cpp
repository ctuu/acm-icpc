#include <array>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    array<int, 27> as, at;
    as.fill(0);
    at.fill(0);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    for (auto i : s)
        as[i - 'a']++;
    for (auto i : t)
        at[i - 'a']++;

    for (int i = 0; i < 27; ++i)
        if (as[i] != at[i])
        {
            cout << "-1" << endl;
            return 0;
        }
    int ans = 0;
    vector<int> q;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == t[i])
            continue;
        int j = i + 1;
        while (j < n && s[j] != t[i])
        {
            ++j;
            continue;
        }
        ans += j - i;
        for (int k = j - 1; k >= i; --k)
        {
            q.push_back(k+1);
            char a = s[k];
            s[k] = s[k + 1];
            s[k + 1] = a;
        }
    }
    cout << ans << endl;
    for (auto i : q)
        cout << i <<  " ";
    cout << endl;
    return 0;
}