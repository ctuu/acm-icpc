#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> ar;
    array<int, 256> py;
    py.fill(-1);
    int n, k;
    cin >> n >> k;
    ar.resize(n);
    for (auto &x : ar)
    {
        cin >> x;
        if (py[x] == -1)
        {
            for (int j = max(0, x - k + 1); j <= x; ++j)
            {
                if (py[j] == -1 || py[j] == j)
                    for (int l = j; l <= x; ++l)
                        py[l] = j;
            }
        }
        cout << py[x] <<" ";
    }
    return 0;
}