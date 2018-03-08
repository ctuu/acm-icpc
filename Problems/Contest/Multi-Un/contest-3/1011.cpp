#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, to = 0, te;
    cin >> t;
    for (int i =0; i < t; ++i)
    {
        cin >> te;
        if (te <= 35)
        ++to;
    }
    cout << to;
    return 0;
}