#include <algorithm>
#include <array>
// #include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int CHARSET = 26, BASE = 'a', MAX_NODE = 200005;
array<bool, MAX_NODE> ist;
struct Trie
{
    int tot, root;
    // int child[MAX_NODE][CHARSET];
    vector<array<int, CHARSET>> child;
    int flag[MAX_NODE];
    Trie()
    {
        // memset(child[1], 0, sizeof(child[1]));
        array<int, CHARSET> tmp;
        tmp.fill(0);
        child.push_back(tmp);
        child.push_back(tmp);
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
                array<int, CHARSET> tmp;
                child.push_back(tmp);
                // printf("%s  %d %d\n",p, tot,child.size());
                // cout << p << " "<< tot << " " << child.size() << endl;
                child[tot].fill(0);
                // memset(child[tot], 0, sizeof(child[tot]));
                flag[tot] = 0;
            }
            // printf("!!!\n");
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    // char s[23];
    cin >> n;
    // scanf("%d", &n);
    for (int t = 0; t < n; ++t)
    {
        ist.fill(0);
        cin >> s;
        // scanf("%s", s);
        // int si = strlen(s);
        int si = s.size();
        for (int i = 0; i < si; ++i)
            e.insert(s.substr(i, si).c_str(), t);
    }
    // scanf("%d", &n);
    cin >> n;
    for (int t = 0; t < n; ++t)
    {
        cin >> s;
        // scanf("%s", s);
        // printf("%d\n", e.query(s));
        cout << e.query(s.c_str()) << endl;
    }
    return 0;
}