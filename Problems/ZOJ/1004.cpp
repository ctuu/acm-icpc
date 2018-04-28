#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <vector>
using namespace std;
set<string> ans;
void dfs(stack<char> st, queue<char> qu, string ori, string s)
{
    while (ori != "")
    {
        st.push(ori[0]);
        ori = ori.substr(1);
        s += "i ";
        while (!st.empty() && !qu.empty() && st.top() == qu.front())
        {
            dfs(st, qu, ori, s);
            st.pop();
            qu.pop();
            s += "o ";
        }
    }
    while (!st.empty() && !qu.empty() && st.top() == qu.front())
    {
        st.pop();
        qu.pop();
        s += "o ";
    }
    // cout << s << endl;
    if (st.empty() && qu.empty())
    {
        ans.insert(s);
        return;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    while (cin >> a >> b)
    {
        ans.clear();
        queue<char> qu;
        for (auto i : b)
            qu.push(i);
        stack<char> st;
        string s = "";
        dfs(st, qu, a, s);
        cout << "[" << endl;
        for (auto i : ans)
            cout << i << endl;
        cout << "]" << endl;
    }
    return 0;
}