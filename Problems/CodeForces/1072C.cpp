#include <iostream>
#include <cmath>
#include <array>
#include <vector>
using namespace std;
const int N = 1e5;
array<bool, N> ia;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a, b;
    ia.fill(0);
    cin >> a >> b;
    vector<int> va, vb;
    long long c = (sqrt((a + b) * 8 + 1) - 1) / 2;
    for (int i = c; i > 0; --i)
    {
        if (a >= i)
        {
            ia[i] = 1;
            va.push_back(i);
            a -= i;
        }
    }
    for (int i = 1; i <= c; ++i)
        if (!ia[i])
            vb.push_back(i);
    cout << va.size() << endl;
    for (auto i : va)
        cout << i << ' ';
    cout << endl;
    cout << vb.size() << endl;
    for (auto i : vb)
        cout << i << ' ';
    return 0;
}