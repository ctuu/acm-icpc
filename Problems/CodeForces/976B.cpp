#include <algorithm>
#include <iostream>
using namespace std;

using LL = long long;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    LL n, m, k;
    cin >> n >> m >> k;
    if (k < n)
    {
        cout << k + 1 << " " << 1 << endl;
        return 0;
    }
    k -= n;
    LL tx = n, ty = 2;
    LL b = k % (m - 1);
    LL a = k / (m - 1);
    tx -= a;
    if(a%2)
        ty = m - b;
    else
        ty = ty + b;
    cout << tx << " " << ty << endl;
    return 0;
}