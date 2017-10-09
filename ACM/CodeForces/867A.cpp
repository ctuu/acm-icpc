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
    int n;
    string le;
    cin >> n;
    cin >> le;
    if (*le.begin() =='F' || *le.begin() == *le.rbegin())
        cout << "NO";
    else
        cout << "YES";
    return 0;
}