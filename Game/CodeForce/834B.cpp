#include <bits/stdc++.h>
using namespace std;

struct node
{
    bool en;
    int nu;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    array<pair<int, int>, 26> al;
    al.fill(pair<int, int>(-1, 0));
    cin >> n >> k;
    char t;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        int &ta = al[t - 'A'].first;
        int &tb = al[t - 'A'].second;
        if (ta == -1)
            ta = i;
        tb = i;
    }
    vector<node> qu;
    for (int i = 0; i < 26; ++i)
    {
        node temp;
        if (al[i].first > -1)
        {
            temp.en = 0;
            temp.nu = al[i].first;
            qu.push_back(temp);
            temp.en = 1;
            temp.nu = al[i].second;
            qu.push_back(temp);
        }
    }
    sort(qu.begin(), qu.end(), [](node a, node b) { return a.nu < b.nu; });
    // for (auto i: qu)
    //     cout << i.en <<' '<< i.nu << endl;
    int an = 0;
    for (auto i : qu)
    {
        if (!i.en)
            ++an;
        else if (i.nu != n)
            --an;
        if (an > k)
        {
            cout << "YES";
            return 0;
        }
        // cout << "an= " << an << endl;
    }
    cout << "NO";
    return 0;
}