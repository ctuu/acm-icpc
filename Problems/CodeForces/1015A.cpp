#include <iostream>
#include <array>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    array<bool, 100+7> v;
    v.fill(false);

    for(int i = 0; i < n; ++i)
    {
        int l, r;
        cin >> l >> r;
        while(l <= r)
        {
            v[l] = 1;
            l++;
        }
    }
    int ans = 0;
    for(int i = 1; i <= m; ++i)
        ans += v[i] == 1 ? 0 : 1;
    cout << ans << endl;
    for(int i  = 1; i <= m; ++i)
        if(v[i] == 0)
            cout << i << " ";
    cout << endl;
    return 0;
}