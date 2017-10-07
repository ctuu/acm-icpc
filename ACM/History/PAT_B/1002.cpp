#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string num;
    cin >> num;
    int to = 0;
    for (auto i: num)
        to += (int) i-'0';
    num = to_string(to);
    string no[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    bool flag = 0;
    for (auto i: num)
    {
        if (flag)
            cout << " ";
        flag = 1;
        cout << no[(int) i - '0'];
    }
    return 0;
}
