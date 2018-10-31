#include <iostream>
#include <array>
using namespace std;
const int N = 2e5 + 7;
array<int, N> a, b, s;
array<bool, N> v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    s.fill(-1);
    v.fill(0);
    int n, pa = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = 0; i < n; ++i)
    {
        if (v[b[i]])
        {
            s[i] = 0;
            continue;
        }
        for (int j = pa; j < n; ++j)
        {
            v[a[j]] = 1;
            if (b[i] == a[j])
            {
                s[i] = j - pa + 1;
                pa = j + 1;
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        cout << s[i] << ' ';
    return 0;
}