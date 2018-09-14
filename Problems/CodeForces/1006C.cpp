#include <iostream>
#include <array>
using namespace std;

const int N = 2e5 + 7;
using LL = long long;
array<int, N> ar;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> ar[i];
    int l = 0, r = n - 1;
    LL s1 = ar[l], s3 = ar[r], ans = 0;
    while (l < r)
    {
        if (s1 == s3)
            ans = s1;
        if (s1 <= s3)
        {
            ++l;
            s1 += ar[l];
        }
        else
        {
            --r;
            s3 += ar[r];
        }
    }
    cout << ans << endl;
    return 0;
}