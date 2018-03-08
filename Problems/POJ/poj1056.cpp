#include <algorithm>
#include <array>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int CHARSET = 2, BASE = '0', MAX_NODE = 100000;
struct Trie
{
    int tot, root, child[MAX_NODE][CHARSET];
    bool flag[MAX_NODE];
    Trie()
    {
        memset(child[1], 0, sizeof(child[1]));
        flag[1] = false;
        root = tot = 1;
    }
    bool insert(const char *str)
    {
        int *cur = &root;
        bool fl = 0;
        for (const char *p = str; *p; ++p)
        {
            cur = &child[*cur][*p - BASE];
            if (*cur == 0)
            {
                fl = 1;
                *cur = ++tot;
                memset(child[tot], 0, sizeof(child[tot]));
                flag[tot] = false;
            }
        }
        flag[*cur] = true;
        return fl;
    }
    bool query(const char *str)
    {
        int *cur = &root;
        for (const char *p = str; *p && *cur; ++p)
            cur = &child[*cur][*p - BASE];
        return (*cur && flag[*cur]);
    }
};

bool cmp(string a, string b)
{
    return a.size() > b.size();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    int t = 0;
    vector<string> sts;
    while (cin >> str)
    {
        if (str != "9")
            sts.push_back(str);
        else
        {
            Trie e;
            ++t;
            bool lfl = 1;
            sort(sts.begin(), sts.end(), cmp);
            cout << "Set " << t;
            int si = sts.size();
            for (int i = 0; i < si; ++i)
                if (!e.insert(sts[i].c_str()))
                {
                    lfl = 0;
                    break;
                }
            if (lfl)
                cout << " is immediately decodable" << endl;
            else
                cout << " is not immediately decodable" << endl;
            sts.clear();
        }
    }
    return 0;
}