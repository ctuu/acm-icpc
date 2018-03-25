#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        double h, w;
        cin >> h >> w;
        double bw = (h - 100) * 1.8;
        if (abs(bw - w) < bw * 0.1)
            cout << "You are wan mei!" << endl;
        else if (bw > w)
            cout << "You are tai shou le!" << endl;
        else
            cout << "You are tai pang le!" << endl;
    }
    return 0;
}