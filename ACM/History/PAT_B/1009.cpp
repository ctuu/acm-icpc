#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string letter, line;
    vector<string> sens;
    getline(cin, line);
    stringstream ss(line);
    while (ss >> letter)
        sens.push_back(letter);
    for (auto i = sens.rbegin(); i < sens.rend(); ++i)
    {
        if (i != sens.rbegin())
            cout << " ";
        cout << *i;
    }
    return 0;
}
