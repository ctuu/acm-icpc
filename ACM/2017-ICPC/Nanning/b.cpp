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
    array<int, 102> ar;
    while (cin >> n && n != 0)
    {
        ar.fill(0);
        for (int i = 0; i < n; ++i)
        {
            int a, b, c;
            cin >> a >> b >> c;
            for (int j = a; j < b; ++j)
                ar[j] += c;
        }
        int ans = 0;
        for (int i = 0; i <=100; ++i)
            ans = max(ans, ar[i]);
        cout << ans << endl;
    }
    cout << "*";
    return 0;
}