#include <array>
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 7;
array<bool, N> s;
array<int, N> sr, a;

int main()
{
    s.fill(0);
    sr.fill(0);
    vector<int> l;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (s[a[i]] == 0)
        {
            l.push_back(i);
            s[a[i]] = 1;
        }
    }
    s.fill(0);
    int b = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (s[a[i]] == 0)
        {
            b++;
            s[a[i]] = 1;
        }
        sr[i] = b;
    }

    long long ans = 0;
    for (auto i : l)
        ans += sr[i + 1];
    cout << ans << endl;
    return 0;
}