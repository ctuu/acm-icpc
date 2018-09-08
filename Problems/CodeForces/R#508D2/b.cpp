// #include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n <= 2)
    {
        cout << "No" << endl;
        return 0;
    }
    vector<int> o, e;
    for (int i = 1; i <= n; ++i)
        if (i % 2)
            o.push_back(i);
        else
            e.push_back(i);
    cout << "Yes" << endl;
    cout << o.size();
    for (auto i : o)
        cout << " " << i;
    cout << endl;
    cout << e.size();
    for (auto i : e)
        cout << " " << i;
    cout << endl;
    return 0;
}