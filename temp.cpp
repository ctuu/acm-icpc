#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int si = s.size();
    for (int i = 0; i < si; ++i)
        cout << s.substr(i, si) << endl;
    return 0;
}