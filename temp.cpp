#include <algorithm>
#include <array>
#include <iostream>
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
        int mm = 0, cm = 0;
        int n, tmp, mm1;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> tmp;
            if (mm != tmp)
            {
                mm1 = mm;
                mm = max(tmp, mm);
                cm = mm1 == mm ? cm : mm1;
            }
            if (mm == tmp)
                cm = mm;
        }
        cout << cm << " " << mm << endl;
    }
    return 0;
}