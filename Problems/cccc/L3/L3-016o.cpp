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
// array<int, N> ar;
map<int, int> ids;
map<int, int> ar;
set<int> node;
void add(int c, int r)
{
    tree[c] = MP(-1,-1);
    if(c < r)
    {
        if(tree[r].first == -1)
            tree[r].first = c;
        else
            add(c, tree[r].first);
    }   
    else
    {
        if(tree[r].second == -1)
            tree[r].second = c;
        else
            add(c, tree[r].second);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, root;
    cin >> n >> root;
    node.insert(root);
    tree[root] = MP(-1, -1);
    for (int i = 1; i < n; ++i)
    {
        int t;
        cin >> t;
        node.insert(t);
        add(t, root);
    }
    ar[root] = 0;
    ids[root] = 0;
    queue<PII> qu;
    qu.push(MP(root, 0));
    while (!qu.empty())
    {
        auto cu = qu.front();
        int id = cu.second;
        qu.pop();
        int l = tree[cu.first].first;
        int r = tree[cu.first].second;
        int lid = 2 * id + 1;
        int rid = 2 * id + 2;
        if (l != -1)
        {
            ar[l] = ar[cu.first] + 1;
            ids[l] = lid;
            qu.push(MP(l, lid));
        }
        if (r != -1)
        {
            ar[r] = ar[cu.first] + 1;
            ids[r] = rid;
            qu.push(MP(r, rid));
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        bool fl = 0;
        string ts;
        vector<string> vec;
        cin >> a;
        getline(cin, ts);
        stringstream ssin(ts);
        while (ssin >> ts)
            vec.push_back(ts);
        // for(auto i: vec)
        //     cout << i <<" ";
        // cout << endl;
        if (node.count(a) == 0)
            fl = 1;
        else if (vec[2] == "root")
        {
            if (a != root)
                fl = 1;
        }
        else if (vec[3] == "siblings")
        {
            b = stoi(vec[1]);
            if (node.count(b) == 0)
                fl = 1;
            else if ((ids[a] + 1) / 2 != (ids[b] + 1) / 2)
                fl = 1;
        }
        else if (vec[2] == "parent")
        {
            b = stoi(vec[4]);
            if (node.count(b) == 0)
                fl = 1;
            else if ((ids[b] + 1) / 2 - 1 != ids[a])
                fl = 1;
        }
        else if (vec[2] == "left")
        {
            b = stoi(vec[5]);
            if (node.count(b) == 0)
                fl = 1;
            else if (tree[b].first != a)
                fl = 1;
        }
        else if (vec[2] == "right")
        {
            b = stoi(vec[5]);
            if (node.count(b) == 0)
                fl = 1;
            else if (tree[b].second != a)
                fl = 1;
        }
        else if (vec[3] == "on")
        {
            b = stoi(vec[1]);
            if (node.count(b) == 0)
                fl = 1;
            else if (ar[a] != ar[b])
                fl = 1;
        }
        if (fl)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}