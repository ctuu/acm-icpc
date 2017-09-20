#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    array<int, 101> ar;
    ar.fill(0);
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        ar[tmp] = 1;
    }
    int ans = 0;
    for (int i = 0; i < x; ++i)
        if (!ar[i])
            ans++;
    if (ar[x])
        ans++;
    cout << ans;
    return 0;
}