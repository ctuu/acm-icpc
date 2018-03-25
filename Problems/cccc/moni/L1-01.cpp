#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string sl;
    cin >> n;
    cin.get();
    getline(cin, sl);
    array<string, 103> ar;
    int si = sl.size();
    ar.fill("");
    for (int i = 0; i < si; ++i)
        ar[i % n].insert(0, 1, sl[i]);
    int mx = 0;
    for (int i = 0; i < n; ++i)
        mx = max(mx, (int)ar[i].size());
    for (int i = 0; i < n; ++i)
        cout << string(mx, ' ').replace(mx - ar[i].size(), ar[i].size(), ar[i]) << endl;
    return 0;
}