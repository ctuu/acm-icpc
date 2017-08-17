#include <iostream>
#include <algorithm>
#include <array>
#include <iomanip>
#include <set>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int a = 1; a < 21; ++a)
    {
        cout << setw(2) << a << ": ";
        set<int> te;
        for (int b = 1; b <= a + 2; ++b)
        {
            // cout << a << "mod " << b << ": " << a % b << endl;
            te.insert(a % b);
        }
        for (auto i : te)
            cout << setw(2) << i << " ";
        cout << endl;
    }
    return 0;
}