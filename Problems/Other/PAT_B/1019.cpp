#include <bits/stdc++.h>
using namespace std;
bool compg(char a, char b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string res;
    cin >> res;
    while (res.size() < 4)
        res.insert(0, "0");
    bool k = 0;
    while (!k || res != "6174")
    {
        k = 1;
        string nua = res;
        string nub = res;
        sort(nua.begin(), nua.end(), compg);
        sort (nub.begin(), nub.end());
        int na = (nua[0] - '0') * 1000 + (nua[1] - '0') * 100 + (nua[2] - '0') * 10 + nua[3] - '0';
        int nb = (nub[0] - '0') * 1000 + (nub[1] - '0') * 100 + (nub[2] - '0') * 10 + nub[3] - '0';
        int te = na - nb;
        res = to_string(te);
        if (te == 0)
        {
            cout << nua << " - " << nub << " = 0000";
            return 0;
        }
        while (res.size() < 4)
            res.insert(0, "0");
        cout << nua << " - " << nub << " = " << res << endl;
    }
    return 0;
}
