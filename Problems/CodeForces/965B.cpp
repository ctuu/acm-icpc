#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    array<array<char, 103>, 103> ar;
    array<array<int, 103>, 103> br;
    for (auto &i : br)
        i.fill(0);
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> ar[i][j];

    for (int i = 0; i < n; ++i)
    {
        int ct = 0;
        for (int j = 0; j < n; ++j)
        {
            if (ar[i][j] == '.')
                ++ct;
            else
            {
                // j += ct;
                ct = 0;
            }
            if (ct == k)
            {
                for (int l = j - k + 1; l <= j; ++l)
                    br[i][l]++;
                ct--;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        int ct = 0;
        for (int j = 0; j < n; ++j)
        {
            if (ar[j][i] == '.')
                ++ct;
            else
            {
                // j += ct;
                ct = 0;
            }
            if (ct == k)
            {
                for (int l = j - k + 1; l <= j; ++l)
                    br[l][i]++;
                ct--;
            }
        }
    }

    // for(int i = 0; i < n; ++i, cout << endl)
    //     for(int j = 0 ; j < n; ++j)
    //         cout << br[i][j] << " ";

    int mx = -1, ax, ay;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (br[i][j] > mx)
            {
                mx = br[i][j];
                ax = i;
                ay = j;
            }
    cout << ax+1 << " " << ay+1 << endl;
    return 0;
}