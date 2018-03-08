//2017 CCPC QinHuangDao
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, R, r;
        cin >> n >> R >> r;
        long long a = (R - 2 * r)*(R - 2 * r), mlen = 0x3f3f3f3f;
        vector<int> ar, br;
        for (int i = 1; i <= n; ++i)
        {
            int j, k;
            cin >> j >> k;
            long long clen = j * j + k * k;
                if (a * a >= clen)
                {
                    ar.push_back(i);
                    continue;
                }
            if (mlen > clen)
            {
                mlen = clen;
                br.clear();
            }
            if (mlen == clen)
                br.push_back(i);
        }
        if (ar.size())
        {
            int si = ar.size();
            cout << si << endl;
            for (int i = 0; i < si; ++i)
            {
                if (i)
                    cout << " ";
                cout << ar[i];
            }
        }
        else
        {
            int si = br.size();
            cout << si << endl;
            for (int i = 0; i < si; ++i)
            {
                if (i)
                    cout << " ";
                cout << br[i];
            }
        }
        cout << endl;
    }
    return 0;
}