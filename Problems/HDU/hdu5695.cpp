#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
#define N 100000
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
            cin >> a >> b;//以a为基底，排名越前约束越少
            a--;
            b--;
            gr[a].push_back(b);
            ++indge[b];
        }
        priority_queue<int> bfs;
        for (int i = 0; i < n; ++i)
            if (!indge[i])
                bfs.push(i);
        vector<int> rst;
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
            rst.push_back(tmp);
        }
        long long ans = 0, mim = INF;
        for (auto i : rst)
        {
            mim = min(mim, (long long)(i + 1));
            ans += mim;
        }
        cout << ans << endl;
    }
    return 0;
}