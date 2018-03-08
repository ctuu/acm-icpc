#include <iostream>
#include <algorithm>
#include <array>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;
struct node
{
    int t, x, y;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        vector<node> ar;
        ar.resize(n);
        for (auto &i : ar)
            cin >> i.t >> i.x >> i.y;
        double sum = 0;
        for (int i = 1; i < n; ++i)
        {
            double tmx = ar[i].x - ar[i - 1].x;
            double tmy = ar[i].y - ar[i - 1].y;
            double tm = ar[i].t - ar[i - 1].t;
            sum =max(sum, sqrt(tmx * tmx + tmy * tmy) / tm);
        }
        cout << fixed << setprecision(9) << sum << endl;
    }
    return 0;
}