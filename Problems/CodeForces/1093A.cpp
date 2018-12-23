#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int s;
        cin >> s;
        cout << (s / 7 + (s % 7?1:0)) << endl;
    }
    return 0;
}