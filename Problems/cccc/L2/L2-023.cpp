#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int>> gr;
    int V, E, K, a, b, n;
    array<int, 503> c;
    cin >> V >> E >> K;
    gr.resize(V);
    for (int i = 0; i < E; ++i)
    {
        cin >> a >> b;
        gr[a - 1].push_back(b - 1);
        gr[b - 1].push_back(a - 1);
    }
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        set<int> st;
        for (int j = 0; j < V; ++j)
        {
            cin >> c[j];
            st.insert(c[j]);
        }
        bool fl = 0;
        if (st.size() != K)
            fl = 1;
        else
            for (int j = 0; j < V; ++j)
                for (auto k : gr[j])
                    if (c[k] == c[j])
                        fl = 1;
        if (fl)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}