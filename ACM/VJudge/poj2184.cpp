#include <iostream>
#include <algorithm>
#include <vector>
#define SH 100000
#define INF 0x3f3f3f3f
using namespace std;
int ds[100005 + SH];
int df[100005 + SH];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, sos = 0, sof = 0;
    cin >> n;
    int si[102], fi[102];
    for (int i = 0; i < n; ++i)
    {
        cin >> si[i] >> fi[i];
        if (si[i] < 0 && fi[i] < 0)
        {
            --i;
            --n;
            continue;
        }
        if (si[i] > 0)
            sos += si[i];
        if (fi[i] > 0)
            sof += fi[i];
        // si[i] += SH;
        // fi[i] += SH;
    }
    ds[SH] = 1;
    for (int i = 0; i < n; ++i)
    {
        if (si[i] > 0)
        {
            for (int j = sos + SH; j >= si[i]; --j)
                if (ds[j - si[i]])
                    ds[j] = 1;
        }
        else
            for (int j = -si[i]; j <= sos + SH; ++j)
                if (ds[j])
                    ds[j + si[i]] = 1;
    }
    vector<int> as;
    for (int i = sos + SH; i >= SH; --i)
        if (ds[i])
            as.push_back(i);
    // for (auto i : as)
    //     cout << i - SH << endl;
    // cout << endl;

    int ct = as.size();
    int ans = 0;
    for (int i = 0; i < ct; ++i)
    {
        for (int j = SH; j <= SH + sos; ++j)
            df[j] = -INF;
        df[SH] = 0;
        for (int j = 0; j < n; ++j)
        {
            if (si[j] > 0)
            {
                for (int k = as[i]; k >= si[j] + SH; --k)
                    df[k] = max(df[k], df[k - si[j]] + fi[j]);
            }
            else
                for (int k =si[j] + SH; k <= as[i]; ++k)
                    df[k + si[j]] = max(df[k + si[j]], df[k] + fi[j]);
        }
        // cout << as[i] << " " << df[as[i]] << endl;
        ans = max(ans, as[i] + df[as[i]]);
    }
    cout << ans - SH;
    return 0;
}