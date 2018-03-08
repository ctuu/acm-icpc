#include <iostream>
#include <algorithm>
#include <vector>
#define K 405
#define A 40000
using namespace std;
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

bool cmp(no a, no b) { return a.a < b.a; }
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
    sort(va.begin(), va.begin() + ct, cmp);
    int dp[A] = {0}, ans = 0;
    dp[0] = 1;
    for (int i = 0; i < ct; ++i)
        for (int j = va[i].a; j >= va[i].h; --j)
            if (!dp[j] && dp[j - va[i].h])
            {
                dp[j] = 1;
                ans = max(ans, j);
            }
    cout << ans << endl;
    return 0;
}