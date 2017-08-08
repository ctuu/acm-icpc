#include <iostream>
#include <array>
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
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    int t;
    // array<int, N> ch;
    array<int, M> ca;
    array<int, M> qr;
    array<int, M> re;
    array<int, 17> bin;
    //1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536
    cin >> t;
    while (t--)
    {
        bin.fill(0);
        int n, m, q;
        cin >> n >> m >> q;
        cout << n << "!" << endl;
        for (int i = 0; i < n; ++i)
        {
            cout << i << endl;
            int temp, r = 65536, j = 16;
            cin >> temp;
            while (temp)
            {
                if (temp >= r)
                {
                    temp -= r;
                    ++bin[j];
                }
                r >>= 1;
                --j;
            }
        }
        // for (int i = 0; i < 16; ++i)
        //     cout << bin[i] << " ";
        // cout << endl;
        for (int i = 0; i < m; ++i)
            cin >> ca[i];
        for (int i = 0; i < q; ++i)
            cin >> qr[i];
        for (int j = 0; j < m; ++j)
        {
            for (int k = 0; k < 16; ++k)
                if (bin[k] && PowerMod(2, k, ca[j]) == qr[i])
                {
                    cout << k << " " << ca[j] << " " << qr[i] << endl;
                    ans += bin[k];
                }
        }
        cout << (ans & 1) << endl;
    }
}
return 0;
}