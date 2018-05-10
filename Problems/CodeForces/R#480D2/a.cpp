#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (auto i : s)
        if (i == 'o')
            a++;
        else
            b++;
    if (!a || b % a == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}