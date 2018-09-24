#include <array>
#include <iostream>
#include <array>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    array<int, 5> a{100, 20, 10, 5, 1};
    int ans = 0;
    for(int i = 0; i < 5; ++i)
    {
        while (n >= a[i])
        {
            n -= a[i];
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
