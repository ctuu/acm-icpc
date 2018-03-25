#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<string> sl;
    string t;
    while (cin >> t && t != ".")
        sl.push_back(t);
    int si = sl.size();
    if (si < 2)
        cout << "Momo... No one is for you ..." << endl;
    else if (si < 14)
        cout << sl[1] << " is the only one for you..." << endl;
    else
        cout << sl[1] << " and " << sl[13] << " are inviting you to dinner..." << endl;
    return 0;
}