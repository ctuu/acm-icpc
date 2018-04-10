#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, num;
    cin >> n;
    vector<int> vc;
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        int l = 0, r = vc.size();
        while (l < r)
        {
            int m = (l + r) / 2;
            if (vc[m] > num)
                r = m;
            else
                l = m + 1;
        }
        if (vc.size() > l)
            vc[l] = num;
        else
            vc.push_back(num);
    }
    cout << vc.size() << endl;
    return 0;
}