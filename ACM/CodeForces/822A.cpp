#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    int k = min(a, b);
    int ans = 1;
    while (k--)
    ans *= (k + 1);
    cout << ans;
    return 0;
}