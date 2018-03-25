#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string li;
    cin >> li;
    int ss = li.size() + 1;
    li = string(ss, '0').replace(1, ss, li);
    string a, b;
    cin >> a >> b;
    int sa = a.size();
    int sb = b.size();
    a = string(ss, '0').replace(ss - sa, sa, a);
    b = string(ss, '0').replace(ss - sb, sb, b);
    int c = 0;
    for (int i = ss - 1; i > -1; --i)
    {
        int bas = stoi(li.substr(i, 1));
        int ca = stoi(a.substr(i, 1));
        int cb = stoi(b.substr(i, 1));
        int sm = ca + cb + c;
        if (bas != 0)
        {
            c = sm / bas;
            a.replace(i, 1, to_string(sm % bas));
        }
        else
        {
            c = sm / 10;
            a.replace(i, 1, to_string(sm % 10));
        }
    }
    int idx = 0;
    while (a[idx] == '0' && idx < ss - 1)
        idx++;
    cout << a.substr(idx) << endl;
    return 0;
}