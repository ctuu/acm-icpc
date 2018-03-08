#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, ind = 0;
        cin >> n;
        vector<string> a;
        for (int i = 0; i < n; ++i)
        {
            string tmp;
            cin >> tmp;
            a.push_back(tmp);
            if (a[ind].size() < tmp.size())
                ind = i;
        }
        bool flag = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i == ind)
                continue;
            size_t fi = a[ind].find(a[i]);
            if (fi == a[ind].npos)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
            cout << a[ind] << endl;
        else
        cout << "NO" << endl;
    }
    return 0;
}