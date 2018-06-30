#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, k, t;
    cin >> n >> k;
    vector<int> vt;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        vt.push_back(t);
    }
    for (int i = 0; i < n; ++i)
    {
        if (vt.empty())
            break;
        if (*vt.begin() <= k)
            vt.erase(vt.begin());
        if (vt.empty())
            break;
        if (*vt.rbegin() <= k)
            vt.erase(vt.end() - 1);
    }
    cout << n - vt.size() << endl;
    return 0;
}