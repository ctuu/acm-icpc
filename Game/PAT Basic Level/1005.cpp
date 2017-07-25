#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int occ[10000] = {0};
    int t;
    cin >> t;
    vector <int> num;
    num.resize(t);
    for (auto &i: num)
    {
        cin >> i;
        occ[i] = 1;
    }
    sort(num.begin(), num.end(), greater<int>());
    for (int i: num)
    {
        int n = i;
        while (n != 1)
        {
            if (n % 2 == 0)
                n /= 2;
            else 
                n = (3 * n + 1) / 2;
            if (occ[n])
                occ[n] = 0;
        }
    }
    bool flag = 0;
    for (int i = 0; i < t; ++i)
    {
        if (occ[num[i]])
        {
            if (flag)
                cout << " ";
            else
                flag = 1;
            cout << num[i];
        }
    }
    return 0;
}
