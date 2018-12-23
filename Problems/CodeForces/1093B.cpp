#include <iostream>
#include <map>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        map<char, int> mpc;
        string s;
        cin >> s;
        for (auto i : s)
            mpc[i]++;
        if (mpc.size() == 1)
        {
            cout << "-1" << endl;
            continue;
        }
        for (auto c : mpc)
        {
            for (int i = 0; i < c.second; ++i)
                cout << c.first;
        }
        cout << endl;
    }
    return 0;
}
