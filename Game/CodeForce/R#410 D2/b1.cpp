#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> word;
    vector<string> wor2;
    array<int, 52> minn;
    minn.fill(0);
    word.resize(n);
    wor2.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> word[i];
        wor2[i] = word[i] + word[i];
    }
    int le = word[0].size();
    for (int i = 0; i < n; ++i)
    {
        string ini = word[i];
        for (int j = 0; j < n; ++j)
        {
            bool sfl = 0;
            if (j == i)
                continue;
            for (int k = 0; k < le; ++k)
            {
                string cur = wor2[j].substr(k, le);
                if (cur == ini)
                {
                    minn[i] += k;
                    sfl = 1;
                    break;
                }
            }
            if (sfl == 0)
            {
                cout << "-1";
                return 0;
            }
        }
    }
    int mx = 0x3ffffff;
    for (int i = 0; i < n; ++i)
        mx = min(mx, minn[i]);
    cout << mx;
    return 0;
}
