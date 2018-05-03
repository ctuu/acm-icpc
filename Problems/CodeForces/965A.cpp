#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    double k, n, s, p;
    cin >> k >> n >> s >> p;
    n = ceil(n/s);
    cout << (int)ceil(k*n/p) << endl;
    return 0;
}