#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    map<string,int> mp;
    string ans, tns;
    for(int i = 0; i < n - 1; ++i)
    {
        tns = s.substr(i, 2);
        mp[tns]++;
    }
    int ct = 0;
    for(auto i: mp)
    {
        if(i.second > ct)
        {
            ct = i.second;
            ans = i.first;
        }
    }
    cout << ans << endl;
    return 0;
}