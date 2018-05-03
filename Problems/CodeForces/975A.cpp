#include <iostream>
#include <array>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<string> ans;
    for(int i  = 0; i < n; ++i)
    {
        set<char> tns;
        string tmp;
        cin >> tmp;
        for(auto i: tmp)
            tns.insert(i);
        tmp ="";
        for(auto i: tns)
        tmp += i;
        ans.insert(tmp);
    }
    cout << ans.size() << endl;
    return 0;
}