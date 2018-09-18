#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v;
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    if (n == 1)
    {
        cout << v[0] + m << " " << v[0] + m << endl;
        return 0;
    }
    int tma = 0, tmn = 0;
    for (auto i : v)
        tma = max(tma, i);
    tma += m;
    sort(v.begin(), v.end());
    while (m > 0)
    {
        bool aa = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            while (m > 0 && v[i] < v[i + 1])
            {
                v[i]++;
                m--;
                aa = 1;
            }
            if (aa)
                break;
        }
        if (!aa && m > 0 && v[n - 1] == v[n - 2])
        {
            v[n - 1]++;
            m--;
        }
        // for (auto i : v)
        //     cout << i << " ";
        // cout << m << endl;
    }
    for (auto i : v)
        tmn = max(tmn, i);
    cout << tmn << " " << tma << endl;
    return 0;
}