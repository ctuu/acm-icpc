#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    vector<int> v;
    int si = s.size();
    v.resize(si);
    bool fl = 0;
    auto la = *v.rbegin();
    if(la == 'a')
    {
        v[si-1] = 1;
        fl = 1;
    }
    for(int i = si - 1; i >= 0; --i)
    {
        if(s[i] != la)
        {
            if(fl || s[i] == 'a')
                v[i] = 1;
            if(s[i] == 'a')
                fl = 1;
            la = s[i];
        }
    }
    for (auto i : v)
        cout << i << ' ';
    return 0;
}