#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> v;
    v.resize(n);
    int res = 0;
    int idx = 0;

    //test
    for (int i = 0; i < n; ++i)
    {
        cout << 1 << endl;
        fflush(stdout);
        cin >> res;
        if (res == -2 || res == 0)
            return 0;
        v[i] = res == 1 ? 0 : 1;
    }
    //run
    int l = 1, r = m + 1, mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        cout << mid << endl;
        fflush(stdout);
        cin >> res;
        if (res == -2 || res == 0)
            return 0;

        if (v[idx])
            res = res == -1 ? 1 : -1;

        if (res == 1)
            l = mid + 1;
        else
            r = mid;
        idx = (idx + 1) % n;
    }
    return 0;
}