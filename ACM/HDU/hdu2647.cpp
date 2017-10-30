#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
#define N 10002
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    while (cin >> n >> m)
    {
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
        queue<int> bfs;
        array<int, N> levl;
        levl.fill(0);
        for (int i = 0; i < n; ++i)
            if (!indge[i])
                bfs.push(i);
        vector<int> rst;
        while (!bfs.empty())
        {
            int tmp = bfs.front();
            bfs.pop();
            for (auto i : gr[tmp])
            {
                --indge[i];
                levl[i] = max(levl[i], levl[tmp] + 1);
                if (!indge[i])
                    bfs.push(i);
            }
            rst.push_back(tmp);
        }
        if (rst.size() != n)
            cout << "-1" << endl;
        else
        {
            long long base = 888, ans = 0;
            for (int i = 0; i < n; ++i)
                ans += base + levl[i];
            cout << ans << endl;
        }
    }
    return 0;
}