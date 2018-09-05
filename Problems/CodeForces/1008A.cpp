#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int si = s.size();
    bool liv = 0;
    string tk = "aeiou";
    liv = tk.find(s[0]) == string::npos ? 0 : 1;
    for (int i = 1; i < si; ++i)
    {
        bool res = tk.find(s[i]) == string::npos ? 0 : 1;
        if (liv == 0 && res == 0 && s[i - 1] != 'n')
        {
            cout << "NO" << endl;
            return 0;
        }
        liv = res;
    }
    if (liv == 0 && s[si - 1] != 'n')
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}