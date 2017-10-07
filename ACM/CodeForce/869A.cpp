#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    array<int, 2007> a, b;
    array<bool, 10000007> ca;
    ca.fill(false);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        ca[a[i]] = 1;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
        ca[b[i]] = 1;
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (ca[a[i] ^ b[j]])
                ++ans;
    // cout << ans << endl;
    if (ans & 1)
        cout << "Koyomi";
    else
        cout << "Karen";
    return 0;
}