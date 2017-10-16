#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> ar;
    for (int i = max(0, n - 82); i <= n; ++i)
    {
        int tmp = i;
        int k = 0;
        while (tmp > 0)
        {
            k += tmp % 10;
            tmp /= 10;
        }
        if (k == n - i)
            ar.push_back(i);
    }
    cout << ar.size() << endl;
    for (auto i : ar)
        cout << i << endl;
    return 0;
}