#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int l, r, si = s.size();
    r = (si + 1) / 2;
    l = r - 1;
    while (l >= 0 || r < si)
    {
        if (l >= 0)
            cout << s[l--];
        if (r < si)
            cout << s[r++];
    }
    return 0;
}