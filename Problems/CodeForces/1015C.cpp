#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using PII = pair<int, int>;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<PII> v;
    long long mx = 0, mn = 0;
    v.resize(n);
    for (auto &i: v)
    {
        cin >> i.first >> i.second;
        mx += i.second;
        mn += i.first;
    }
    if(mx > m)
    {
        cout << "-1"<<endl;
        return 0;
    }
    sort(v.begin(), v.end(), [](PII &a, PII &b){
        return a.first - a.second > b.first - b.second;
    });
    int ans = 0;
    for(auto i: v)
    {
        if(mn <= m)
        break;
        mn -= i.first - i.second;
        ans++;
    }
    cout << ans << endl;
    return 0;
}