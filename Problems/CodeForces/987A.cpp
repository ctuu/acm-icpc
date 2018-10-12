#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<string, string> mp;
    mp["purple"] = "Power";
    mp["green"] = "Time";
    mp["blue"] = "Space";
    mp["orange"] = "Soul";
    mp["red"] = "Reality";
    mp["yellow"] = "Mind";
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        mp.erase(s);
    }
    cout << mp.size() << endl;
    for(auto i: mp)
        cout << i.second << endl;
    return 0;
}