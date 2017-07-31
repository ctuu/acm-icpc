#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char a, b;
    int n, ac, bc;
    cin >> a >> b >> n;
    ac = (a == '^') ? 0 : (a == '>') ? 1 : (a == 'v') ? 2 : 3;
    bc = (b == '^') ? 0 : (b == '>') ? 1 : (b == 'v') ? 2 : 3;
    n %= 4;
    if ((ac + n) % 4 == bc && (ac + 4 - n) % 4 == bc)
        cout << "undefined";
    else if ((ac + n) % 4 == bc)
        cout << "cw";
    else
        cout << "ccw";
    return 0;
}