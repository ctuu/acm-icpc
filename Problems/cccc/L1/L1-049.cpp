#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, sum = 0;
    cin >> n;
    array<int, 103> ar;
    array<vector<int>, 103> br;
    for (int i = 0; i < n; ++i)
    {
        cin >> ar[i];
        ar[i] *= 10;
        sum += ar[i];
    }
    for (int i = 1; i <= sum;)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!ar[j])
                continue;
            ar[j]--;
            if (!br[j].empty() && *br[j].rbegin() == i - 1)
            {
                ++i;
                ++sum;
            }
            br[j].push_back(i);
            ++i;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (i)
            cout << endl;
        cout << "#" << i + 1 << endl;
        for (int j = 0; j < br[i].size(); ++j)
        {
            if (j % 10)
                cout << " ";
            else if (j)
                cout << endl;
            cout << br[i][j];
        }
    }
    return 0;
}