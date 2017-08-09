#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#define N 55
#define W 100005
#define P 1005
#define M 10
#define C 105
#define V 1000005
#define INF 0x3f3f3f3f
using namespace std;
struct no
{
    int c, v;
    no() = default;
    no(int a, int b)
    {
        this->c = a;
        this->v = b;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, w;
    while (cin >> n >> w)
    {
        array<int, W> dp, pdp;
        dp.fill(0);
        for (int i = 0; i < n; ++i)
        {
            int pi, mi;
            cin >> pi >> mi;
            for (int j = 0; j <= w; ++j)
                pdp[j] = dp[j];
            for (int j = 0; j < mi; ++j)
            {
                int c, v;
                cin >> c >> v;
                for (int k = w - pi; k >= c; --k)
                    pdp[k] = max(pdp[k], pdp[k - c] + v);
            }
            for (int j = pi; j <= w; ++j)
                dp[j] = max(dp[j], pdp[j - pi]);
        }
        cout << dp[w] << endl;
    }
    return 0;
}