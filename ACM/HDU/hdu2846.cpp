#include <algorithm>
#include <array>
#include <cstring>
#include <cstdio>
// #include <iostream>
#include <vector>
using namespace std;
const int CHARSET = 26, BASE = 'a', MAX_NODE = 200005;
array<bool, MAX_NODE> ist;
struct Trie
{
    int tot, root, child[MAX_NODE][CHARSET];
    int flag[MAX_NODE];
    Trie()
    {
        memset(child[1], 0, sizeof(child[1]));
        flag[1] = 0;
        root = tot = 1;
    }
    void insert(const char *str, int id)
    {
        int *cur = &root;
        for (const char *p = str; *p; ++p)
        {
            cur = &child[*cur][*p - BASE];
            if (*cur == 0)
            {
                *cur = ++tot;
                memset(child[tot], 0, sizeof(child[tot]));
                flag[tot] = 0;
            }
            if (!ist[*cur])
                ++flag[*cur];
            ist[*cur] = 1;
        }
        // flag[*cur] = true;
    }
    int query(const char *str)
    {
        int *cur = &root;
        for (const char *p = str; *p && *cur; ++p)
            cur = &child[*cur][*p - BASE];
        return flag[*cur];
    }
};
Trie e;
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    int n;
    string s;
    cin >> n;
    for (int t = 0; t < n; ++t)
    {
        ist.fill(0);
        cin >> s;
        int si = s.size();
        for (int i = 0; i < si; ++i)
            e.insert(s.substr(i, si).c_str(), t);
    }
    cin >> n;
    for (int t = 0; t < n; ++t)
    {
        cin >> s;
        cout << e.query(s.c_str()) << endl;
    }
    return 0;
}