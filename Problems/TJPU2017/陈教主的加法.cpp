#include <iostream>
#include <algorithm>
#include <iomanip>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a, b, c, d, e, f;
    while (cin >> a >> b >> c >> d >> e >> f)
    {
        long long sum = 0, aver = 0, nega = 0;
        if (a > 0)
        {
            sum += a;
            aver++;
        }
        else if (a < 0)
            nega++;
        if (b > 0)
        {
            sum += b;
            aver++;
        }
        else if (b < 0)
            nega++;
        if (c > 0)
        {
            sum += c;
            aver++;
        }
        else if (c < 0)
            nega++;
        if (d > 0)
        {
            sum += d;
            aver++;
        }
        else if (d < 0)
            nega++;
        if (e > 0)
        {
            sum += e;
            aver++;
        }
        else if (e < 0)
            nega++;
        if (f > 0)
        {
            sum += f;
            aver++;
        }
        else if (f < 0)
            nega++;
        cout << nega << " ";
        if (aver == 0)
            cout << "0.00" << endl;
        else
            cout << fixed << setprecision(2) << sum / (double)aver << endl;
    }
    return 0;
}