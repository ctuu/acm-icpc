#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string i;
    vector<string> name;
        cin >> i;
    do
    {
        name.push_back(i);
        cin >> i;
    }while (i != ".");
    if (name.size() > 13)
        cout << name[1] << " and " << name[13]  << " are inviting you to dinner...";
    else if (name.size()>1)
        cout << name[1] << " is the only one for you...";
    else
        cout << "Momo... No one is for you ...";
    return 0;
}
