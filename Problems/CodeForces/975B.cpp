#include <array>
#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    array<long long, 14> ar;
    for (auto &i : ar)
        cin >> i;
    long long ans = 0;
    for (int i = 0; i < 14; ++i)
    {
        auto br = ar;
        long long ct = ar[i];
        br[i] = 0;
        if (ct >= 14)
        {
            long long wg = ct / 14;
            for (auto &j : br)
                j += wg;
            ct %= 14;
        }
        if (ct < 14)
        {
            for (int j = i + 1; ct > 0; j++)
            {
                if (j == 14)
                    j = 0;
                br[j]++;
                ct--;
            }
        }
        long long tns = 0;
        for (int j = 0; j < 14; ++j)
            if (br[j] % 2 == 0)
                tns += br[j];
        ans = max(ans, tns);
    }
    cout << ans << endl;
    return 0;
}