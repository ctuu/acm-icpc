#include <algorithm>
#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
array<int, 100000> no, val;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int r, n;
    cin >> r >> n;
    no.fill(-1);
    for (int i = 0; i < n; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        val[a] = b;
        no[a] = c;
    }
    set<int> ext;
    vector<int> bsc;
    int st = no[r];
    cout << setw(5) << setfill('0') << r << " " << val[r] << " ";
    ext.insert(abs(val[r]));
    while (st != -1)
    {
        if (ext.count(abs(val[st])))
        {
            bsc.push_back(st);
            st = no[st];
            continue;
        }
        ext.insert(abs(val[st]));
        cout << setw(5) << setfill('0') << st << endl;
        cout << setw(5) << setfill('0') << st << " " << val[st] << " ";
        st = no[st];
    }
    cout << "-1" << endl;
    if (bsc.size() > 0)
    {
        cout << setw(5) << setfill('0') << bsc[0] << " " << val[bsc[0]] << " ";
        for (int i = 1; i < bsc.size(); ++i)
        {
            cout << setw(5) << setfill('0') << bsc[i] << endl;
            cout << setw(5) << setfill('0') << bsc[i] << " " << val[bsc[i]] << " ";
        }
        cout << "-1" << endl;
    }
    return 0;
}