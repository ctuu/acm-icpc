#include <array>
#include <iostream>
using namespace std;
array<array<array<int, 33>, 33>, 15> hg;
int d[6][2] = {-1, 0, 1, 0, 0, 1, 0, -1, -1, -1, 1, 1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (auto &i : hg)
        for (auto &j : i)
            j.fill(0);
    int ox = 15, oy = 15;
    hg[0][ox][oy] = 1;
    for (int i = 0; i < 14; ++i)
        for (int j = 0; j < 32; ++j)
            for (int k = 0; k < 32; ++k)
                for (int t = 0; t < 6; ++t)
                {
                    int cx = j + d[t][0];
                    int cy = k + d[t][1];
                    if (cx > 32 || cx < 0 || cy > 32 || cy < 0)
                        continue;
                    hg[i + 1][cx][cy] += hg[i][j][k];
                }
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        cout << hg[n][ox][oy] << endl;
    }
    return 0;
}