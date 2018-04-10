#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int l, n;
    cin >> l >> n;
    string s = string(l, 'z');
    n--;
    for (int i = l-1; i >= 0; --i)
    {
        int t = n % 26;
        n /= 26;
        s[i] = (char)'z' - t;
    }
    cout << s << endl;
    return 0;
}