#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double n, a;
    cin >> n >> a;
    double div = 180 / n;
    int v1 = 1, v2 = n, v3 = 2;
    double minm = INF;
    for (int i = 2; i < n; ++i)
    {
        double tmp = fabs((n - i) * div - a);
        if (tmp < minm)
        {
            v3 = i;
            minm = tmp;
        }
    }
    cout << v2 << " " << v1 << " " << v3 << endl;
    return 0;
}