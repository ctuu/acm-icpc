#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
map<string, int> nid;
array<int, 103> tg;
array<double, 103> avg;
bool cmp(string a, string b)
{
    int ia = nid[a], ib = nid[b];
    if (tg[ia] == tg[ib])
        return avg[ia] > avg[ib];
    return tg[ia] > tg[ib];
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<string> ne;

    tg.fill(0);
    int n, k, tmp;
    string tp;
    cin >> n;
    ne.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> tp >> k;
        nid[tp] = i;
        ne[i] = tp;
        set<int> st;
        for (int j = 0; j < k; ++j)
        {
            cin >> tmp;
            st.insert(tmp);
        }
        tg[i] = st.size();
        avg[i] = 1.0 * st.size() / k;
    }
    sort(ne.begin(), ne.end(), cmp);
    for (auto i = 0; i < 3 && i < n; ++i)
    {
        if (i)
            cout << " ";
        cout << ne[i];
    }
    n = 3 - n;
    while(n > 0)
    {
        cout <<" -";
        n--;
    }
    return 0;
}