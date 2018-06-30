#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
const int N = 4e5 + 7;
array<bool, N> ar;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ar.fill(1);
    for (int i = 0; i < 26; ++i)
    {
        if (k <= 0)
            break;
        char p = (char) i + 'a';
        for (int j = 0; j < n; ++j)
        {
            if (k <= 0)
                break;
            if (s[j] == p)
            {
                ar[j] = 0;
                k--;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        if (ar[i])
            cout << s[i];
    return 0;
}