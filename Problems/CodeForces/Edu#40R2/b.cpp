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
        auto ta = s.substr(0, i);
        auto tb = s.substr(i, i);
        if (ta == tb)
            mct = i;
    }
    if (mct != 0)
        mct--;
    cout << s.size() - mct << endl;
    return 0;
}