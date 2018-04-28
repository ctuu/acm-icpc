#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    array<int, 1003> ar;
    ar.fill(0);
    for(int i = 0; i < m; ++i)
    {
        int t;
        cin >> t;
        ar[t]++;
    }
    int mx = ar[1];
    for(int i = 2; i <= n; ++i)
        mx = min(mx, ar[i]);
    cout << mx << endl;
    return 0;
}