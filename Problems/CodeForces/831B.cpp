#include <iostream>
#include <algorithm>
#include <array>
#include <map>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string lnf, lns, sen;
    cin >> lnf >> lns >> sen;
    map<char, char> tr;
    for (int i = 0; i < 26; ++i)
        tr[lnf[i]] = lns[i];
    for (auto i : sen)
    {
        int t = 0;
        if (isdigit(i))
        {
            cout << i;
            continue;
        }
        if (isupper(i))
            t = 32;
        cout << (char)(tr[i + t] - t);
    }
    return 0;
}