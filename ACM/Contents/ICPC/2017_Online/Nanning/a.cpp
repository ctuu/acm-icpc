#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <sstream>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    array<array<double, 5>, 5> a;
    for (int i = 1; i < 5; ++i)
        for (int j = 1; j < 5; ++j)
            cin >> a[i][j];
    string lin;
    stringstream foo;
    vector<int> va;
    getline(cin, lin);
    getline(cin, lin);
    foo.clear(), foo.str(lin);
    int tmp;
    while (foo >> tmp)
        va.push_back(tmp);
    double ans = 1.0;
    int si = va.size();
    for (int i = 0; i < si - 1; ++i)
        ans *= a[va[i]][va[i + 1]];
    cout << setprecision(8) << fixed << ans << endl;
    getline(cin, lin);
    va.clear();
    foo.clear(), foo.str(lin);
    while (foo >> tmp)
        va.push_back(tmp);
    ans = 1.0;
    si = va.size();
    for (int i = 0; i < si - 1; ++i)
        ans *= a[va[i]][va[i + 1]];
    cout << setprecision(8) << fixed << ans << endl;
    int x1;
    cin >> x1;
    double k = a[x1][x1], q = 1.0, f = 1;
    for (int i = 0; i < 100; ++i)
    {
        f *= k;
        q += f;
    }
    cout << setprecision(8) << fixed << q << endl;
    cin >> x1;
    k = a[x1][x1], q = 1.0, f = 1;
    for (int i = 0; i < 100; ++i)
    {
        f *= k;
        q += f;
    }
    cout << setprecision(8) << fixed << q << endl;
    return 0;
}