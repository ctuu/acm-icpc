#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a[3] = {0}, tmp;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin>>tmp;
        a[tmp]++;
    }
    int ans = 0;
    ans += min(a[1],a[2]);
    if(a[1] > a[2])
        ans += (a[1]-a[2])/3;
    cout << ans;
    return 0;
}