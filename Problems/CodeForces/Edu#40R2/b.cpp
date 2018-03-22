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
    string s;
    cin >> n;
    cin >> s;
    int mct = 0;
    for (int i = 1; i < n; ++i)
    {
        int ct = 0;
        for (int j = i; j < n; ++j)
        {
            if (s[j] == s[j - i] && j < 2 * i)
                ct++;
            else
                break;
        }
        mct = max(ct, mct);
    }
    if (mct != 0)
        mct--;
    cout << s.size() - mct << endl;
    return 0;
}