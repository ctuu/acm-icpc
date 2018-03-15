#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    char c;
    double l;
    cin >> n;
    cout.setf(ios::fixed);
    for (int i = 0; i < n; ++i)
    {
        cin >> c >> l;
        if (c == 'F')
            l *= 1.09;
        else
            l /= 1.09;
        cout << setprecision(2) << l << endl;
    }
    return 0;
}