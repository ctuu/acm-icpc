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
    string psw, bf;
    int n;
    array<string, 103> ar;
    cin >> psw >> n;
    for (int i = 0; i < n; ++i)
        cin >> ar[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            bf += ar[i] + ar[j];
    // cout << bf;
    if (bf.find(psw) < n*n*4)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}