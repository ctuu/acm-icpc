#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
#define N 20000
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    array<bool, N + 5> mrk;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        mrk.fill(0);
        int n, a, b, ti = 0;
        bool fl = 0;
        cin >> n >> a >> b;
        mrk[a] = mrk[b] = 1;
        vector<int> ar;
        ar.push_back(a);
        ar.push_back(b);
        do
        {
            fl = 0;
            int re;
            for (auto i : ar)
            {
                if (mrk[i])
                {
                    for (auto j : ar)
                        if (i != j && mrk[j])
                        {
                            re = i + j;
                            if (re <= n && !mrk[re])
                            {
                                ++ti;
                                mrk[re] = 1;
                                fl = 1;
                                ar.push_back(re);
                                break;
                            }
                            re = abs(i - j);
                            if (!mrk[re])
                            {
                                ++ti;
                                mrk[re] = 1;
                                fl = 1;
                                ar.push_back(re);
                                break;
                            }
                        }
                }
                if (fl)
                    break;
            }
        } while (fl);
        cout << "Case #" << t << ": ";
        if (ti & 1)
            cout << "Yuwgna" << endl;
        else
            cout << "Iaka" << endl;
    }
    return 0;
}