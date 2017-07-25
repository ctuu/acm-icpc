#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int num[202] = {0};
    int n, k;
    cin >> n >> k;
    k %= n;
    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        num[i] = num[i + n] = t;
    }
    int i;
    for (int i = n - k; i < 2 * n - k; ++i)
    {
        if (i != n - k)
            cout << " ";
        cout << num[i];
    }
    return 0;
}
