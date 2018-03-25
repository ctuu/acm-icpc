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
    int h;
    cin >> h;
    cout << fixed << setprecision(1) << (h - 100) * 1.8 << endl;
    return 0;
}