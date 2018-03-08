#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    int n, m;
    cin >> n >> m;
    cin >> s >> t;
    vector<int> a, b;
    int minm = INF;
    for (int i = 0; i <= m - n; ++i)
    {
        b.clear();
        int ct = 0;
        for (int j = 0; j < n; ++j)
            if (t[i + j] != s[j])
            {
                ct++;
                b.push_back(j + 1);
            }
        if (minm > ct)
        {
            minm = ct;
            a = b;
        }
    }
    cout << minm << endl;
    for (auto i: a)
    cout << i << " ";
    return 0;
}