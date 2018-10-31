#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n - 1; ++i)
        if (s[i] != s[i + 1])
        {
            cout << "YES" << endl;
            cout << s[i] << s[i + 1] << endl;
            return 0;
        }
    cout << "NO" << endl;
    return 0;
}