#include <iostream>
#include <algorithm>
#include <vector>
#define E 10005
#define F 10005
#define N 505
#define P 50005
#define W 10005
#define INF 0x3f3f3f3f
using namespace std;
struct no
{
    int p, w;
    no() = default;
    no(int a, int b)
    {
        this->p = a;
        this->w = b;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int e, f;
        cin >> e >> f;
        int wei = f - e;
        int n, p, w;
        cin >> n;
        vector<no> va;
        for (int i = 0; i < n; ++i)
        {
            cin >> p >> w;
            va.push_back(no(p, w));
        }
        // array<int, F> dp;
        int dp[F];
        for (int i = 0; i < F; ++i)
            dp[i] = INF;
        dp[0] = 0;
        int ct = va.size();
        for (int i = 0; i < ct; ++i)
            for (int j =va[i].w; j <= wei; ++j)
                dp[j] = min(dp[j], dp[j - va[i].w] + va[i].p);
        if (dp[wei] == INF)
            cout << "This is impossible.\n";
        else
            cout << "The minimum amount of money in the piggy-bank is " << dp[wei] << ".\n";
    }
    return 0;
}