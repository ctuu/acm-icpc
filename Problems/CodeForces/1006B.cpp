#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    v.resize(n);
    for(auto &i: v)
        cin >> i;
    sort(v.begin(), v.end());
    int gr = n / k;
    int sum = 0;
    for(auto i = v.rbegin(); i < v.rbegin() + k; ++i)
        sum += *i;
    cout << sum << endl;
    for(int i = 0; i < k - 1; ++i)
        cout << gr << " ";
    cout << n - gr * (k - 1)<< endl;
    return 0;
}