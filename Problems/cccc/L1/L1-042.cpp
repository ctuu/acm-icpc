#include <algorithm>
#include <array>
#include <iostream>
#include <regex>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    array<char, 10> ar;
    for (auto &i : ar)
        cin >> i;
    for (int i = 6; i < 10; ++i)
        cout << ar[i];
    cout << "-";
    for (int i = 0; i < 2; ++i)
        cout << ar[i];
    cout << "-";
    for (int i = 3; i < 5; ++i)
        cout << ar[i];
    return 0;
}