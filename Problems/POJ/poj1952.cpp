#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 5007;
const int INF = 0x3f3f3f3f;
int d[N], c[N], m[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    for(int i = 0; i < N; ++i)
        d[i] = m[i] = 1;
    
    for (int i = n - 1; i >= 0; --i)
        for (int j = i + 1; j < n; ++j)
        {
            if (c[i] > c[j])
            {
                if (d[i] < d[j] + 1)
                {
                    d[i] = d[j] + 1;
                    m[i] = m[j];
                }
                else if (d[i] == d[j] + 1)
                    m[i] += m[j];
            }
            else if (c[i] == c[j])
            {
                if (d[i] == 1)
                    m[i] = 0;
                break;
            }
        }
    int mx = 0, mxm = 0;
    
    for (int i = 0; i < n; ++i)
        mx = max(mx, d[i]);
    for (int i = 0; i < n; ++i)
        mxm = d[i] == mx ? mxm + m[i] : mxm;

    cout << mx << " " << mxm << endl;
    return 0;
}