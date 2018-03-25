#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string sln;
    cin >> sln;
    bool fl = 0;
    int mx = 0;
    if (sln[0] == '?')
        mx = 2;
    for (int i = 1; i < n; ++i)
    {
        if (sln[i] == sln[i - 1] && sln[i] != '?')
            fl = 1;
        if (i < n - 1 && sln[i] == '?')
        {
            int t = sln[i - 1] == sln[i + 1] ? 2 : 1;
            if(sln[i-1] == '?' || sln[i+1] == '?')
            mx = max(2, mx);
            mx = max(t, mx);
        }
    }
    if (sln[n - 1] == '?')
        mx = max(2, mx);
    if (fl || mx < 2)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}