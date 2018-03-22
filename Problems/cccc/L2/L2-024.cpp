#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int N = 10000;
array<int, N> p, sz;
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
void join(int a, int b)
{
    int i = find(a);
    int j = find(b);
    if (i == j)
        return;
    if (sz[i] < sz[j])
        swap(i, j);
    p[j] = i;
    sz[j] += sz[i];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    cin >> n;
    set<int> aum;
    for (int i = 1; i <= N; ++i)
        p[i] = i;
    sz.fill(1);
    for (int i = 0; i < n; ++i)
    {
        cin >> m;
        vector<int> vec;
        for(int j = 0; j < m; ++j)
        {
            cin >> a;
            vec.push_back(a);
            aum.insert(a);
        }
        for (auto j : vec)
            for (auto k : vec)
                join(j, k);
    }
    set<int> st;
    int num = aum.size();
    for(auto i: aum)
        st.insert(find(i));
    cout << num << " " << st.size() << endl;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        int j = find(a);
        int k = find(b);
        if (j == k)
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
    return 0;
}