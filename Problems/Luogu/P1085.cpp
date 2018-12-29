#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0, mx = 0, a, b;
    for (int i = 0; i < 7; ++i)
    {
        cin >> a >> b;
        if (a + b > 8 && a + b > mx)
        {
            mx = a + b;
            ans = i + 1;
        }
    }
    cout << ans;
    return 0;
}