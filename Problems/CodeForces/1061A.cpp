#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    cout << (s/n) + (s%n?1:0) << endl;
    return 0;
}