#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#define N 50005
#define M 50005
#define A 50005
#define B 50005
using namespace std;

int PowerMod(int a, int b, int c)
{
    int ans = 1;
    a = a % c;
    while (b > 0)
    {
        if (b % 2 == 1)
            ans = (ans * a) % c;
        b = b / 2;
        a = (a * a) % c;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    array<int, N> ch;
    array<int, M> ca;
    array<int, M> qr;
    array<int, M> re;
    // array<int, 17> bin;
    //1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536
    cin >> t;
    while (t--)
    {
        // bin.fill(0);
        int n, m, q;
        set<pair> va;
        cin >> n >> m >> q;
        for (int i = 0; i < n; ++i)
            cin >> ch[i];
        for (int i = 0; i < m; ++i)
            cin >> ca[i];
        for (int i = 0; i < q; ++i)
            cin >> qr[i];
        sort(ch.begin(), ch.begin() + n);
        sort(ca.begin(), ca.begin() + m);
                for (int i = 0; i < n; ++i)
            for (int i = 0; i < m; ++i)
            {
                int a = ch[i];
                int b = ca[j];
                int c = _GCD(a, b);
                a /= c;
                b /= c;
                va.insert(a, b);
            }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (ch[j] < ca[i])
                {
                    ++re[ch[j]];
                    continue;
                }
                int ans = 0;
                int temp = ch[j], r = 65536, k = 16;
                while (temp)
                {
                    if (temp >= r)
                    {
                        temp -= r;
                        ans += PowerMod(2, k, ca[i]);
                    }
                    r >>= 1;
                    --k;
                }
                // cout << ch[j] << " " << ca[i] << " " << ans << endl;
                ++re[ans % ca[i]];
            }
        }
        for (int i = 0; i < q; ++i)
            cout << (re[i] & 1) << endl;
    }
    return 0;
}