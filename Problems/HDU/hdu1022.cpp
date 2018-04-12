#include <algorithm>
#include <array>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n)
    {
        string s1, s2;
        vector<string> res;
        stack<char> stk;
        cin >> s1 >> s2;
        int q = 0;
        for (int i = 0; i < n; ++i)
        {
            stk.push(s1[i]);
            res.push_back("in");
            while (!stk.empty() && q < n && stk.top() == s2[q])
            {
                q++;
                stk.pop();
                res.push_back("out");
            }
        }
        if (!stk.empty())
        {
            cout << "No." << endl;
            cout << "FINISH" << endl;
            continue;
        }
        cout << "Yes." << endl;
        for (auto i : res)
            cout << i << endl;
        cout << "FINISH" << endl;
    }
    return 0;
}