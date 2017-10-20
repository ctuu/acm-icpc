#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    char c;
    cin >> n >> c;
    int k = (n - 2) / 2;
    string str(k * 2, '*');
    str.insert(k, 2, c);
    for (int i = 0; i < k; ++i)
        cout << str << endl;
    string str2(n, c);
    cout << str2 << endl
         << str2 << endl;
    for (int i = 0; i < k; ++i)
        cout << str << endl;
    return 0;
}