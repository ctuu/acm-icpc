#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    vector<vector<int>> e;
    e.resize(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        e[a - 1].push_back(b - 1);
        e[b - 1].push_back(a - 1);
    }
    double sum = 0;
    for (auto i : e)
        sum += (i.size() == 1);
    cout << setprecision(10) << (double)s / sum * 2.0;
    return 0;
}