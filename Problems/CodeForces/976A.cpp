#include <algorithm>
#include <array>
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, c1 = 0, c0 = 0;
    string s;
    cin >> n >> s;
    for (auto i : s)
        if (i == '1')
            c1 = 1;
        else if (i == '0')
            c0++;
    s = c1 == 1 ? "1" : "";
    s += string(c0, '0');
    cout << s << endl;
    return 0;
}
