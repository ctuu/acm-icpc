#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int t1 = 0;
    for (auto i : s)
        t1 += i == '1';
    string o(t1, '1');
    bool h2 = 0;
    for (auto i : s)
    {
        if (i == '2' && !h2)
        {
            cout << o;
            h2 = 1;
        }
        if (i != '1')
            cout << i;
    }
    if (s.find('2') == string::npos)
        cout << o;
    return 0;
}
