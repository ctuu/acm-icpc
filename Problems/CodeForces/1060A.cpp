#include <iostream>
using namespace std;
int main()
{
    int n;
    int a = 0, b = 0;
    string s;
    cin >> n >> s;
    for (auto i : s)
        if (i == '8')
            b++;
        else
            a++;
    cout << min(b, n / 11) << endl;
    return 0;
}