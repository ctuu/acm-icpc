//逆向拓扑
#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
#define N 30007
#define INF 0x3f3f3f3f
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<vector<int>> gr;
        gr.resize(n);
        array<int, N> indge;
        indge.fill(0);
        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b;
            a--;
            b--;
            swap(a, b);
            gr[a].push_back(b);
            ++indge[b];
        }
        priority_queue<int> bfs;
        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if (!indge[i])
                bfs.push(i);
        while (!bfs.empty())
        {
            int tmp = bfs.top();
            bfs.pop();
            for (auto i : gr[tmp])
            {
                --indge[i];
                if (!indge[i])
                    bfs.push(i);
            }
            ans.push_back(tmp);
        }
        for (int i = n - 1; i >= 0; --i)
        {
            if (i != n - 1)
                cout << " ";
            cout << ans[i] + 1;
        }
        cout << endl;
    }
    return 0;
}