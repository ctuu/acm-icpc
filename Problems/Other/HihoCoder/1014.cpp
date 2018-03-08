#include <algorithm>
#include <array>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int CHARSET = 26, BASE = 'a', MAX_NODE = 100000;
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
    void insert(const char *str)
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
            ++flag[*cur];
        }
    }
    int query(const char *str)
    {
        int *cur = &root;
        for (const char *p = str; *p && *cur; ++p)
            cur = &child[*cur][*p - BASE];
        if (*cur)
            return flag[*cur];
        else
            return 0;
    }
};
Trie e;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n;
    string str;
    for (int i = 0; i < n; ++i)
    {
        cin >> str;
        e.insert(str.c_str());
    }
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> str;
        cout << e.query(str.c_str()) << endl;
    }
    return 0;
}