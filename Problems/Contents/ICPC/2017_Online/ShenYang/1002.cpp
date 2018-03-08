#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long m, k;
    while (cin >> m >> k)
        cout << k * (m - k + 1) << endl;
    return 0;
}