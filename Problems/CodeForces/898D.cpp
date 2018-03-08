#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
const int M = 1e6 + 7;
array<int, M> ar;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, t;
    ar.fill(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        ar[t]++;
    }
    for (int i = 1; i < M; ++i)
        ar[i] += ar[i - 1];
    int ma = ar[0];
    for (int i = 1; i < M; ++i)
    {
        int b = max(i - m +1, 0);
        ma = max(ma, ar[i] - ar[b]);
    }
    cout <<  max(ma - k + 1, 0);
    return 0;
}