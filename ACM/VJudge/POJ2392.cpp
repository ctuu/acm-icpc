#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#define K 405
#define A 40000
struct no
{
    int h, a;
    no() = default;
    no(int x, int y)
    {
        this->h = x;
        this->a = y;
    }
};
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<no> va;
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        int r = 1;
        int x, y, z;
        cin >> x >> y >> z;
        while (z)
        {
            if (z >= r)
            {
                va.push_back(no(x * r, y));
                z -= r;
                r <<= 1;
            }
            else
                r >>= 1;
        }
    }
    int ct = va.size();
    sort(va.begin(), va.begin() + k, [](no a, no b) { return a.a < b.a; });
    int dp[A] = {0}, ans = 0;
    for (int i = 0; i < ct; ++i)
        for (int j = va[k].a; j >= 0; --j)
        {
                dp[j] = max(dp[j], dp[j - 1] + va[k].h);
                ans = max(ans, dp[j]);
        }
    cout << ans << endl;
    return 0;
}