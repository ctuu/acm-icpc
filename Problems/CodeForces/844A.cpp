#include <iostream>
#include <algorithm>
#include <array>
#include <set>
#include <string>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int k;
    set<int> st;
    cin >> s >> k;
    for (auto i: s)
        st.insert(i - 'a');
    if (s.size() < k)
        cout << "impossible";
    else
        cout << max(k - (int)st.size(), 0);
    return 0;
}