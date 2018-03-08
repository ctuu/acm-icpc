#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, t;
    cin >> n >> k >> t;
    if (t < k)
        cout << t;
    else if (t <= n && t >= k)
        cout << k;
    else
        cout << n + k - t;
    return 0;
}