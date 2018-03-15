#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int chk(int n)
{
    set<int> t;
    n += 10000;
    for (int i = 0; i < 4; ++i)
    {
        t.insert(n % 10);
        n /= 10;
    }
    return t.size();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int y, n, ct = 0;
    cin >> y >> n;
    for (int i = y; i < 4000; ++i)
    {
        if (chk(i) == n)
        {
            cout << ct << " " << setw(4) << setfill('0') << i << endl;
            break;
        }
        ++ct;
    }
    return 0;
}