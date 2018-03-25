#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <vector>
using namespace std;
#define MP(a, b) make_pair(a, b)
using PII = pair<int, int>;
map<int, PII> tree;
map<int, int> le;
map<int, int> fa;
void add(int c, int r)
{
    tree[c] = MP(-1, -1);
    if (c < r)
    {
        if (tree[r].first == -1)
            tree[r].first = c;
        else
            add(c, tree[r].first);
    }
    else
    {
        if (tree[r].second == -1)
            tree[r].second = c;
        else
            add(c, tree[r].second);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, root;
    set<int> ext;
    cin >> n >> root;
    fa[root] = -1;
    le[root] = 0;
    tree[root] = MP(-1, -1);
    ext.insert(root);
    for (int i = 1; i < n; ++i)
    {
        int c;
        cin >> c;
        ext.insert(c);
        add(c, root);
    }
    queue<PII> qu;
    qu.push(MP(root, 0));
    while (!qu.empty())
    {
        auto cp = qu.front();
        qu.pop();
        int cn = cp.first;
        int cl = cp.second;
        int lch = tree[cn].first;
        int rch = tree[cn].second;
        if (lch != -1)
        {
            le[lch] = cl + 1;
            fa[lch] = cn;
            qu.push(MP(lch, cl + 1));
        }
        if (rch != -1)
        {
            le[rch] = cl + 1;
            fa[rch] = cn;
            qu.push(MP(rch, cl + 1));
        }
    }
    // for(auto i: ext)
    //     cout << i <<" " << fa[i] << " " << le[i] << endl;
    cin >> m;
    string slen;
    for (int i = 0; i < m; ++i)
    {
        int a;
        cin >> a;
        bool fl = 1;
        getline(cin, slen);
        stringstream sin(slen);
        vector<string> vec;
        while (sin >> slen)
            vec.push_back(slen);
        // for(auto i: vec)
        //     cout << i << endl;
        if (vec[2] == "root" && a == root)
            fl = 0;
        else if (vec[3] == "siblings")
        {
            int b = stoi(vec[1]);
            if (ext.count(a) && ext.count(b) && fa[a] == fa[b])
                fl = 0;
        }
        else if (vec[2] == "parent")
        {
            int b = stoi(vec[4]);
            if (ext.count(a) && ext.count(b) && fa[b] == a)
                fl = 0;
        }
        else if (vec[2] == "left")
        {
            int b = stoi(vec[5]);
            if (ext.count(a) && ext.count(b) && tree[b].first == a)
                fl = 0;
        }
        else if (vec[2] == "right")
        {
            int b = stoi(vec[5]);
            if (ext.count(a) && ext.count(b) && tree[b].second == a)
                fl = 0;
        }
        else
        {
            int b = stoi(vec[1]);
            if (ext.count(a) && ext.count(b) && le[a] == le[b])
                fl = 0;
        }
        if (fl)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}