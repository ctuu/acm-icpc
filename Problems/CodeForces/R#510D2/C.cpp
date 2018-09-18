#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using PII = pair<int, int>;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ct = n - 1;
    bool op2 = 1;
    vector<int> vop, voz;
    vector<PII> von;
    for (int i = 1; i <= n; ++i)
    {
        int c;
        cin >> c;
        if (c < 0)
            von.push_back({c, i});
        else if (c == 0)
            voz.push_back(i);
        else
            vop.push_back(i);
    }
    sort(von.begin(), von.end(),[](PII &a, PII &b){
        return a > b;});
    int nsi = von.size();
    for (int i = nsi % 2; ct > 0 && i < nsi - 1; ++i, --ct)
        cout << "1 " << von[i].second << " " << von[i + 1].second << endl;
    if (nsi > 1)
        vop.push_back(von[nsi - 1].second);
    int zsi = voz.size();
    if (zsi)
    {
        for (int i = zsi - 1; ct > 0 && i > 0; --i, --ct)
            cout << "1 " << voz[i] << " " << voz[i - 1] << endl;
    }
    if (zsi && nsi % 2)
    {
        if (ct > 0)
        {
            cout << "1 " << von[0].second << " " << voz[0] << endl;
            --ct;
        }
        if (ct > 0)
        {
            op2 = 0;
            cout << "2 " << voz[0] << endl;
            --ct;
        }
    }
    if (op2 && nsi % 2 && ct > 0)
    {
        op2 = 0;
        cout << "2 " << von[0].second << endl;
        --ct;
    }
    if (op2 && zsi && ct > 0)
    {
        op2 = 0;
        cout << "2 " << voz[0] << endl;
        --ct;
    }
    int si = vop.size();
    for (int i = 0; ct > 0 && i < si - 1; ++i, --ct)
        cout << "1 " << vop[i] << " " << vop[i + 1] << endl;
    return 0;
}