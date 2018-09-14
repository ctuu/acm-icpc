#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using PII = pair<int, int>;
const int INF = 0x3f3f3f3f;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<PII> v;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    return 0;
}