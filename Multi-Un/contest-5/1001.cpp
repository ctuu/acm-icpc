#include <iostream>
#include <array>
#include <vector>
#include <set>
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
int Gcd(int a, int b)
{
    while (b != 0)
    {
        int r = b;
        b = a % b;
        a = r;
    }
    return a;
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
        // set<pair<int, int>> va;
        vector<pair<int, int>> va;
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
            for (int j = 0; j < m; ++j)
            {
                int a = ch[i];
                int b = ca[j];
                if (a >= b)
                {
                    int c = Gcd(a, b);
                    a /= c;
                    b /= c;
                }
                va.push_back(pair<int, int>(a, b));
            }
        sort(va.begin(), va.end());
        // for (auto i : va)
        //     cout << i.first << " " << i.second << endl;
        // cout << "SUM: " << va.size() << endl;
        int ct = va.size();
        int ans = 0;
        for (int i = 0; i < ct; ++i)
        {
            if (va[i].first < va[i].second)
            {
                ++re[va[i].first];
                continue;
            }
            if (i && va[i].first == va[i - 1].first && va[i].second == va[i - 1].second)
            {
                ++re[ans % va[i].second];
                continue;
            }
            ans = 0;
            int temp = va[i].first, r = 65536, k = 16;
            while (temp)
            {
                if (temp >= r)
                {
                    temp -= r;
                    ans += PowerMod(2, k, va[i].second);
                }
                r >>= 1;
                --k;
            }
            // cout << ch[j] << " " << ca[i] << " " << ans << endl;
            ++re[ans % va[i].second];
        }
        for (int i = 0; i < q; ++i)
            cout << (re[i] & 1) << endl;
    }
    return 0;
}