#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    vector<int> v;
    cin >> n;
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    int sum = 0;
    for (auto &i : v)
        sum += i;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i)
    {
        int res = (double)sum / n + 0.5;
        if (res == 5)
        {
            cout << i << endl;
            return 0;
        }
        sum += (5 - v[i]);
    }
    cout << n << endl;
    return 0;
}