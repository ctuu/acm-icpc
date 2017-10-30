#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c, v0, v1, a, l, day = 0, sp;
    cin >> c >> v0 >> v1 >> a >> l;
    while (c > 0)
    {
        ++day;
        sp = min(v0, v1);
        c -= sp;
        if (c > 0)
        c += l;
        v0 += a;
    }
    cout << day;
    return 0;
}