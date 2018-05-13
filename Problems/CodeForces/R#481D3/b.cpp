#include <iostream>
#include <array>
#include <regex>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    string s2 = regex_replace(s, regex("x{3,}"), "xx");
    cout << s.size() - s2.size() << endl;
    return 0;
}