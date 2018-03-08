#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, temp;
        array<set<int>>, 3005 > gr;
        for (int i = 1; i <= n; ++i)
            for (j = i + 1; j <= n; ++j)
            {
                cin >> temp;
                if （temp)
                    {
                        gr[j].insert(i);
                        gr[i].insert(j);
                    }
            }
        bool ans = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                for (int k = j + 1; k <= n; ++k)
                {
                    
                    set_intersection(gr[i].begin(), gr[i].end(), gr[j].begin(), gr[j].end(), inserter(c, c.begin()));
                }
    }
    return 0;
}