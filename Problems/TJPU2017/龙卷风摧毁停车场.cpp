#include <iostream>
#include <algorithm>
#include <array>
#include <string>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string n;
    char k;
    while (cin >> n >> k)
    {
        int ans = 0;
        int tmp = n.size();
        for (int i = 0; i < tmp -1; ++i)
        {
            if (n[i] == '0')
                n[i] = 'a';
            else
                break;
        }
        for (auto i : n)
        {
            if (i == k)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}