#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e6 + 7;
const int INF = 0x3f3f3f3f;
array<int, N> ar;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int x, k, t;
        cin >> x >> k >> t;
        ar.fill(INF);
        ar[x] = 0;
        int ct = t;
        for (int i = x; i > 0; --i)
        {
            int tmp = i % k;
            if (!tmp)
                ar[i/k] = min(ar[i/k], ar[i] + 1);
            if (ct == t)
            {
                ar[i - 1] = min(ar[i - 1], ar[i] + 1);
                ct = 0;
            }
            else
            {
                if (ar[i - 1] < ar[i])
                    ct = ct;
                ar[i - 1] = min(ar[i - 1], ar[i]);
            }
            ++ct;
        }
        // for (int i = x; i >= 1; --i)
        //     cout << ar[i] << " " << endl;
        cout << ar[1] << endl;
    }
    return 0;
}