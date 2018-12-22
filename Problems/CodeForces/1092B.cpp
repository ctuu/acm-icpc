#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    v.resize(n);
    for(auto &i: v)
        cin >> i;
    sort(v.begin(), v.end());
    int res = 0;
    for(int i = 0; i < n; i += 2)
        res += v[i + 1] - v[i];
    cout << res << endl;
    return 0;
}
