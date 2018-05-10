#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> vc;
    vc.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> vc[i];
    sort(vc.begin(), vc.end());
    if (k == 0)
    {
        if (vc[0] == 1)
            cout << "-1" << endl;
        else
            cout << "1" << endl;
        return 0;
    }
    if (k == n)
    {
        cout << vc[n - 1] << endl;
        return 0;
    }
    if (vc[k] == vc[k - 1])
        cout << "-1" << endl;
    else
        cout << vc[k - 1] << endl;
    return 0;
}