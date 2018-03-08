#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a, b, al, bl, c;
    cin >> a >> b;
    al = a % 10;
    bl = b % 10;
    c = b - a;
    if (a == b)
        cout << 1;
    else if (c > 10)
        cout << 0;
    else
    {
        if (bl <= al)
            bl += 10;
        c = 1;
        for (int i = bl; i > al; --i)
            c *= i;
        cout << c % 10;
    }
    return 0;
}