#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int N = 1e4 + 7;
array<int, N> p;
int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}
void joint(int a, int b)
{
    int i = find(a);
    int j = find(b);
    p[i] = j;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while (cin >> n && n && cin >> m)
    {
        for (int i = 0; i < N; ++i)
            p[i] = i;
        int a, b;
        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b;
            joint(a, b);
        }
        for (int i = 1; i <= n; ++i)
            find(i);
        set<int> st;
        for (int i = 1; i <= n; ++i)
            st.insert(p[i]);
        cout << st.size() - 1 << endl;
    }
    return 0;
}