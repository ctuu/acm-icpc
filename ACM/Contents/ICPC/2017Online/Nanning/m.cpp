#include <iostream>
#include <algorithm>
#include <array>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
array<int, 1200000> ar;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    double alp;
    cin >> n >> alp;
    string lin;
    stringstream foo;
    vector<int> se;
    getline(cin, lin);
    int ma = 0;
    while (getline(cin, lin))
        {
            ++ma;
            se.clear();
            foo.clear(), foo.str(lin);
            int tmp;
            while (foo >> tmp)
                se.push_back(tmp);
            int si = se.size();
            for (int i = 0; i < (1 << si); i++)
            {
                int fl = 0;
                for (int j = 0; j <si; j++)
                    if (i & (1 << j))
                        fl += 1 << (se[j] - 1);
                ++ar[fl];
            }
        }
    int ans = 0;
    for (int i = 1; i < 1<< n ; ++i)
        if (alp <= (double)ar[i] / (double)ma)
            ++ans;
    cout << ans;
    return 0;
}