#include <iostream>
#include <array>
#include <deque>
using namespace std;
const int N = 2007;
array<array<char, N>, N> mz;
array<array<bool, N>, N> v;
int n, m;
int d[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
bool chk(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m && mz[x][y] == '.' && !v[x][y];
}
struct Dot
{
    int x, y, l, r;
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (auto &i : v)
        i.fill(0);
    int r, c, x, y;
    cin >> n >> m >> r >> c >> x >> y;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> mz[i][j];
    r--;
    c--;
    deque<Dot> st;
    st.push_front({r, c, x, y});
    v[r][c] = 1;
    while (!st.empty())
    {
        auto cur = st.front();
        st.pop_front();
        for (int i = 0; i < 4; ++i)
        {
            int cx = cur.x + d[i][0];
            int cy = cur.y + d[i][1];
            int cl = cur.l - (i == 2);
            int cr = cur.r - (i == 3);
            if ((i < 2 || (cl >= 0 && cr >= 0)) && chk(cx, cy))
            {
                if(i < 2)
                    st.push_front({cx, cy, cl, cr});
                else
                    st.push_back({cx, cy, cl, cr});
                v[cx][cy] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            ans += v[i][j];
    cout << ans << endl;
    return 0;
}
