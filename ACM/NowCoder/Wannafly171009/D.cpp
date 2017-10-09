#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    array<vector<int>, 502> ar;
    int n, m, a, b;
    cin >> n >> m;
    int ix = 0, iy = 0, ii = 0, uv = 0;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i)
    {
        int tmp = ar[i].size();
        if (tmp == 4)
            ++ix;
        else if (tmp == 3)
            ++iy;
        else if (tmp == 2)
            ++ii;
        else if (tmp != 1)
            ++uv;
    }
    if (uv || (ix && iy))
        cout << "NotValid";
    else if (ix)
        cout << "X";
    else if (iy)
        cout << "Y";
    else
        cout << "I";
    return 0;
}