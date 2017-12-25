#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    multimap<string, string> pn;
    set<string> name;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string str, num;
        int p;
        cin >> str >> p;
        name.insert(str);
        for (int j = 0; j < p; ++j)
        {
            cin >> num;
            pn.insert(make_pair(str, num));
        }
    }
    cout << name.size() << endl;
    for (auto str : name)
    {
        vector<string> tmp, tt;
        for (auto i = pn.equal_range(str).first; i != pn.equal_range(str).second; ++i)
            tmp.push_back(i->second);
        cout << str << " ";
        sort(tmp.begin(), tmp.end(), [](string a, string b) {
            return a.size() > b.size();
        });
        int t = tmp.size();
        for (int i = 0; i < t; ++i)
        {
            bool fl = 1;
            for(int j = 0; j < t && j != i; ++j)
            {
                auto ce = tmp[j].rfind(tmp[i]);
                if(tmp[j].size() ==  ce + tmp[i].size())
                {
                    fl = 0;
                    break;
                }
            }
            if(fl)
            tt.push_back(tmp[i]);
        }
        cout << tt.size();
        for (auto i : tt)
            cout << " " << i;
        cout << endl;
    }
    return 0;
}