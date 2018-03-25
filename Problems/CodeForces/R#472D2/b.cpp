#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int n, m;
array<array<char, 53>, 53> ar;
array<array<int, 53>, 53> br;
array<bool, 53> mr, mc;
set<int> gr, gc;
vector<int>asd;
void find(int x, int y)
{
    gr.insert(x);
    gc.insert(y);
    mr[x] = 1;
    mc[y] = 1;
    for (int k = 0; k < m; ++k)
        if (ar[x][k] == '#' && !(mr[x] && mc[k]))
            find(x, k);
    for (int k = 0; k < n; ++k)
        if (ar[k][y] == '#' && !(mr[k] && mc[y]))
            find(k, y);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (auto &i : br)
        i.fill(0);
    mr.fill(0);
    mc.fill(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            cin >> ar[i][j];
            if (ar[i][j] == '.')
                br[i][j] = 0;
            else
                br[i][j] = 1;
        }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (ar[i][j] == '#' && !(mr[i] && mc[j]))
            {
                find(i, j);
                for (auto x : gr)
                    for (auto y : gc)
                        br[x][y] = !br[x][y];
                gr.clear();
                gc.clear();
            }
        }
    }
    // for(int i = 0; i < n; ++i, cout << endl)
    //     for(int j = 0; j < m;++j)
    //         cout << br[i][j] <<" " ;
    bool fl = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(br[i][j] == 1)
                fl = 1;
    if (fl)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}