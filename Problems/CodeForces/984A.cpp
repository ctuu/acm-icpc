#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> vc;
    int n;
    cin >> n;
    vc.resize(n);
    for (auto &i : vc)
        cin >> i;
    sort(vc.begin(), vc.end());
    cout << vc[(n-1) / 2] << endl;
    return 0;
}