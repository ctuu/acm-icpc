#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v;
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    int ans = 0;
    for (int i = 0; i < n / 2; ++i)
    {
        int tb = v[i];
        int te = v[n - 1 - i];
        if (tb != 2 && te != 2 && te != tb)
        {
            cout << "-1" << endl;
            return 0;
        }
        if (tb != 2 && te == 2)
            ans += tb == 1 ? b : a;
        else if (tb == te && te == 2)
            ans += min(2 * b, 2 * a);
        else if (te != 2 && tb == 2)
            ans += te == 1 ? b : a;
    }
    if (n % 2 && v[n / 2] == 2)
        ans += min(a, b);

    cout << ans << endl;
    return 0;
}