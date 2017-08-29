#include <iostream>
#include <algorithm>
#include <array>
#include <set>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n)
    {
        multiset<long long> ms;
        for (int i = 0; i < n; ++i)
        {
            int tmp;
            cin >> tmp;
            ms.insert(tmp);
        }
        array<int, 125350> ar;
        int cnt = 1;
        ar[0] = *ms.begin();
        ms.erase(ms.begin());
        while (!ms.empty())
        {
            ar[cnt++] = *ms.begin();
            ms.erase(ms.begin());
            for (int i = 0; i < cnt - 1; ++i)
                ms.erase(ms.lower_bound(ar[cnt - 1] + ar[i]));
        }
        cout << cnt << endl;
        for (int i = 0; i < cnt; ++i)
        {
            if (i)
                cout << " ";
            cout << ar[i];
        }
        cout << endl;
    }
    return 0;
}