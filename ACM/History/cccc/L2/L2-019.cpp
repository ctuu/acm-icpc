#include <bits/stdc++.h>
using namespace std;
struct sid{
    string id;
    int nu;
};
bool comp(sid a, sid b);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i, n;
    cin >> i;
    set<string> exname;
    while (i--)
    {
        string temp;
        cin >> temp;
        exname.insert(temp);
    }
    cin >> n;
    i = n;
    int sum = 0;
    vector<sid> sname;
    sname.resize(n);
    for (auto &k:sname)
    {
    cin >> k.id >> k.nu;
    sum += k.nu;
    }
    sort(sname.begin(), sname.end(),comp);
    sum /=n;
    bool flag = 1;
    for (auto k:sname)
    {
        if (k.nu > sum && !exname.count(k.id))
        {
            cout << k.id << endl;
            flag = 0;
        }
    }
    if (flag)
    cout << "Bing Mei You";
    return 0;
}
bool comp(sid a, sid b)
{
    if (a.id <= b.id)
    return 1;
    return 0;
}
