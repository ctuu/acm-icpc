#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin >> c;
    array<long long, 21> ar;
    array<long long, 21> q;
    q.fill(0);
    q[0] = 0;
    q[1] = 1;
    ar[0] = 0;
    ar[1] = 0;
    ar[2] = 1;
    for (int i = 3; i < 21; ++i)
        ar[i] = (i - 1) * (ar[i - 1] + ar[i - 2]);
    for (int i = 2; i < 21; ++i)
        q[i] = i * q[i - 1];
    while (c--)
    {
        int n;
        cin >> n;
        cout << setprecision(2) << fixed << (long double) ar[n] / (long double) q[n] * 100 << "%" << endl;
    }

    return 0;
}