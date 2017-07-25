#include <bits/stdc++.h>
using namespace std;
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    long long num;
    string ta;
    while (cin >> ta)
    {
        num = 0;
        string an;
        long long t = 1;
        for (auto i = ta.crbegin(); i < ta.crend(); ++i, t *= 26)
            num += (long long)(*i - 'a') * t;
        int m;
        cin >> m;
        if (num == 0)
        {
            cout << '0' << endl;
            continue;
        }
        while (num > 0)
        {
            an.insert(an.begin(), (char)(num % m + '0'));
            num /= m;
        }
        cout << an << endl;
    }
    return 0;
}