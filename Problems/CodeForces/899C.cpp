#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> a, b;
    int n;
    cin >> n;
    if (n % 2)
    {
        int k = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (k < 2)
                a.push_back(i);
            else
                b.push_back(i);
            k = (k >= 3) ? 0 : k + 1;
        }
    }
    else
    {
        int k = 1;
        for (int i = 1; i <= n; ++i)
        {
            if (k < 2)
                a.push_back(i);
            else
                b.push_back(i);
            k = (k >= 3) ? 0 : k + 1;
        }
    }
    int ana = 0, anb = 0;
    for (auto i : a)
        ana += i;
    for (auto i : b)
        anb += i;
    cout << abs(ana - anb) << endl;
    cout << a.size();
    for (auto i : a)
        cout << " " << i;
    return 0;
}