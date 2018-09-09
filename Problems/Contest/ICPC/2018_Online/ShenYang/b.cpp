#include <algorithm>
#include <array>
#include <cstring>
#include <iostream>
#include <map>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
const int N = 100 + 7;

map<char, int> mp;

string rpn(string s)
{
    stringstream stm;
    mp['+'] = 1;
    mp['-'] = 1;
    mp['*'] = 2;
    mp['d'] = 3;
    mp['('] = 0;
    mp[')'] = 0;
    stm.clear();
    stack<char> s1;
    string op = "";
    int si = s.size();
    for (int i = 0; i < si; ++i)
    {
        if (strchr("+-*d", s[i]) != NULL)
        {
            if (s[i] == '-')
            {
                if (i == 0 || strchr("-+*", s[i - 1]) != NULL)
                {
                    stm << "0|";
                    s1.push(s[i]);
                    continue;
                }
            }
            while (!s1.empty() && mp[s1.top()] >= mp[s[i]])
            {
                char top = s1.top();
                s1.pop();
                stm << top;
            }
            s1.push(s[i]);
        }
        else if(s[i] == '(')
            s1.push('(');
        else if (s[i] == ')')
        {
            while (!s1.empty())
            {
                char top = s1.top();
                s1.pop();
                if (top == '(')
                    break;
                stm << top;
            }
        }
        else
        {
            stm << s[i];
            if (i == si - 1 || strchr("+-*d)", s[i + 1]) != NULL)
                stm << "|";
        }
    }

    while (!s1.empty())
    {
        char top = s1.top();
        s1.pop();
        stm << top;
    }
    return stm.str();
}

pair<long long, long long> calc(string &out)
{
    stringstream stm;
    int si = out.size();
    stack<long long> cmax, cmin;
    stm.clear();
    string num;
    for (int i = 0; i < si; ++i)
    {
        char &c = out[i];
        if (strchr("+-*d|", c) == NULL)
            stm << c;
        else if (c == '|')
        {
            num = "";
            stm >> num;
            if (num != "")
            {
                cmax.push(stoll(num));
                cmin.push(stoll(num));
            }
            stm.clear();
        }
        else
        {
            long long t2 = cmax.top();
            cmax.pop();
            long long t1 = cmax.top();
            cmax.pop();
            long long t4 = cmin.top();
            cmin.pop();
            long long t3 = cmin.top();
            cmin.pop();

            switch (c)
            {
            case '*':
                cmax.push(max(t1 * t2, max(t3 * t4, max(t1 * t4, t3 * t2))));
                cmin.push(min(t1 * t2, min(t3 * t4, min(t1 * t4, t3 * t2))));
                break;
            case '-':
                cmax.push(max(t1 - t4, t3 - t2));
                cmin.push(min(t1 - t4, t3 - t2));
                break;
            case '+':
                cmax.push(max(t1 + t2, t3 + t4));
                cmin.push(min(t1 + t2, t3 + t4));
                break;
            case 'd':
                cmax.push(t1 * t2);
                cmin.push(t3);
                break;
            }
        }
    }
    long long t1 = cmax.top();
    long long t2 = cmin.top();
    t1 = max(t1, t2);
    t2 = min(t1, t2);
    return {t2, t1};
}

int main()
{
    string s;
    while (cin >> s)
    {
        string out = rpn(s);
        // cout << out << endl;
        auto ans = calc(out);
        cout << ans.first << " " << ans.second << endl;
    }
    return 0;
}