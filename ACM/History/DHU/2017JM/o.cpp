#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        vector<long long> ng;
        int t;
        ng.resize(2 * n);
        for (auto &i: ng)
            cin >> i;
        sort(ng.begin(), ng.end());
        long long sum = 0;
        for (int i = 0; i < n; ++i)
            sum += abs(ng[2 * i + 1] - ng[2 * i]);
        cout << sum << endl;
    }
    return 0;
}
