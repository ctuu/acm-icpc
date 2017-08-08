#include <iostream>
#include <array>
#define N 50005
#define M 50005
#define A 50005
#define B 50005
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    array<int, N> ch;
    array<int, M> ca;
    array<int, M> qr;
    cin >> t;
    while (t--)
    {
        int n, m, q;
        cin >> n >> m >> q;
        for (int i = 0; i < n; ++i)
            cin >> ch[i];
        for (int i = 0; i < m; ++i)
            cin >> ca[i];
        for (int i = 0; i < q; ++i)
            cin >> qr[i];
        for (int i = 0; i < q; ++i)
        {
            int ans = 0;
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < m; ++k)
                {
                    // cout << ch[j] << " " << ca[k] << " " << ch[j] % ca[k] << " " << qr[i] << endl;
                    if (ch[j] % ca[k] == qr[i])
                        ++ans;
                }
            cout << (ans & 1) << endl;
        }
    }
    return 0;
}