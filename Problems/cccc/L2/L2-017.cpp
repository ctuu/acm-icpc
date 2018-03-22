#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v;
    int n, sum = 0;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end());
    int a, b, dif, tmp = 0;
    b = n / 2;
    a = n - b;
    for (int i = 0; i < n / 2; ++i)
        tmp += v[i];
    dif = sum - tmp - tmp;
    cout << "Outgoing #: " << a << endl;
    cout << "Introverted #: " << b << endl;
    cout << "Diff = " << dif << endl;
    return 0;
}