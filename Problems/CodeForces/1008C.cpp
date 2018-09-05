#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());

    vector<int> c(v);
    int ans = 0;
    int i = n - 1;
    for (int j = n - 1; j >= 0 && i >= 0; --j, --i)
    {
        while (v[i] >= v[j] && i >= 0)
            --i;
        if (i < 0)
            break;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}
