#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string st, t1, t2;
    int n, d;
    cin >> st >> n;
    map<string, string> nxt;
    map<string, int> dat;
    vector<string> ys;
    for (int i = 0; i < n; ++i)
    {
        cin >> t1 >> d >> t2;
        dat[t1] = d;
        nxt[t1] = t2;
    }
    t1 = st;
    for (int i = 0; i < n; ++i)
    {
        ys.push_back(t1);
        t1 = nxt[t1];
        if (t1 == "-1")
            break;
    }
    bool fl = 0;
    n = ys.size();
    t1 = ys[n - 1];
    cout << t1 << " " << dat[t1] << " ";
    for (int i = 0; i < n / 2;)
    {
        if (!fl)
            d = i;
        else
        {            
            ++i;
            if(n %2 == 0 && i >= n /2)
                break;
            d = n - 1 - i;
        }
        // cout << d << endl;
        t1 = ys[d];
        cout << t1 << endl;
        cout << t1 << " " << dat[t1] << " ";
        fl = !fl;
    }
    cout << "-1" << endl;
    return 0;
}