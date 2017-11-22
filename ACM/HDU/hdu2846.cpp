#include <algorithm>
#include <array>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int CHARSET = 26, BASE = 'a', MAX_NODE = 530005;
array<int, MAX_NODE> ist;
struct Trie
{
    int tot, root;
    int child[MAX_NODE][CHARSET];
    int flag[MAX_NODE];
    Trie()
    {
        memset(child[1], 0, sizeof(child[1]));
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
                flag[tot] = 0;
            }
            if (ist[*cur] != id)
                ++flag[*cur];
            ist[*cur] = id;
        }
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
    cin >> n;
    ist.fill(0);
    for (int t = 0; t < n; ++t)
    {
        cin >> s;
        int si = s.size();
        for (int i = 0; i < si; ++i)
            e.insert(s.substr(i, si).c_str(), t + 1);
    }
    cin >> n;
    for (int t = 0; t < n; ++t)
    {
        cin >> s;
        cout << e.query(s.c_str()) << endl;
    }
    return 0;
}