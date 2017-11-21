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
    bool flag[MAX_NODE];
    Trie()
    {
        memset(child[1], 0, sizeof(child[1]));
        flag[1] = false;
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
                flag[tot] = false;
            }
        }
        flag[*cur] = true;
    }
    bool query(const char *str)
    {
        int *cur = &root;
        for (const char *p = str; *p && *cur; ++p)
            cur = &child[*cur][*p - BASE];
        return (*cur && flag[*cur]);
    }
};
Trie e;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    e.insert("asfg");
    cout << e.query("asfg") << " " << e.query("asf") << endl;
    return 0;
}