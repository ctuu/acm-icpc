#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
#define MP(a, b) make_pair(a, b)
using PII = pair<int, int>;
map<int, PII> tree;
void add(int cu, int r)
{
    if (cu > r)
    {
        if (tree[r].first != -1)
        {
            add(cu, tree[r].first);
            return;
        }
        tree[r].first = cu;
        tree[cu] = MP(-1, -1);
    }
    else
    {
        if (tree[r].second != -1)
        {
            add(cu, tree[r].second);
            return;
        }
        tree[r].second = cu;
        tree[cu] = MP(-1, -1);
    }
}
int root;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    cin >> n >> root;
    tree[root] = MP(-1, -1);
    for (int i = 1; i < n; ++i)
    {
        cin >> t;
        add(t, root);
    }
    int fl = 0;
    queue<int> qu;
    vector<int> ar;
    ar.push_back(root);
    cout << root;
    int a = tree[root].first;
    int b = tree[root].second;
    if (a != -1)
        qu.push(a);
    if (b != -1)
        qu.push(b);
    while (!qu.empty())
    {
        int cu = qu.front();
        qu.pop();
        ar.push_back(cu);
        cout << " " << cu;
        a = tree[cu].first;
        b = tree[cu].second;
        if (a != -1)
            qu.push(a);
        if (b != -1)
            qu.push(b);
    }
    for (int i = 1; i < n; ++i)
    {
        if (ar[i] < ar[(i + 1) / 2 - 1])
            fl = 1;
        ++i;
        if (i < n && ar[i] > ar[(i + 1) / 2 - 1])
            fl = 1;
    }
    cout << endl;
    if (fl)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}