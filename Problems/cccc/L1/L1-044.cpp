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
    int n, ct = 0;
    string s;
    cin >> n;
    map<string, string> mp;
    mp["ChuiZi"] = "Bu";
    mp["JianDao"] = "ChuiZi";
    mp["Bu"] = "JianDao";
    while (cin >> s && s != "End")
    {
        if (ct == n)
        {
            cout << s << endl;
            ct = 0;
            continue;
        }
        cout << mp[s] << endl;
        ++ct;
    }
    return 0;
}