#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int fint(string &s)
{
    string ar[3] = {"ggg", "aaa", "ooo"};
    int res = 0;
    for (int i = 0; i < 9; ++i)
        if (s.find(ar[i % 3]) != string::npos)
        {
           s.erase(s.find(ar[i%3]), 3); 
           ++res;
        }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >>t;
    while (t--)
    {
        string s;
        cin >> s;
        int sum = 0;
        sum += fint(s);
        if (s.size() > 3)
        {
            string tmp = s;
            int si = tmp.size(), mam = 0;
            char ch[3] = {'g', 'a', 'o'};
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < si; ++j)
                    if (tmp[j] == ch[i])
                    {
                        tmp.erase(j, 1);
                        --j;
                    }
                mam = max(mam, fint(tmp));
                tmp = s;
            }
            sum += max(mam, 1);
        }
        cout << sum << endl;
    }
    return 0;
}