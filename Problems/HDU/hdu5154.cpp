#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
#define N 5000
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
            gr[b].push_back(a);
            ++indge[a];
        }
        queue<int> bfs;
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
                if (!indge[i])
                    bfs.push(i);
            }
            rst.push_back(tmp);
        }
        if (rst.size() == n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}