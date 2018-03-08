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
    int n, mn = 0;
    string len;
    set<int> st;
    cin >> n >> len;
    if (len[0] <= 'z' && len[0] >= 'a')
        st.insert(len[0] - 'a');
    mn = st.size();
    for (int i = 1; i < n; ++i)
    {
        if (len[i] <= 'z' && len[i] >= 'a')
        {
            if (len[i] != len[i - 1])
                st.insert(len[i] - 'a');
            mn = max(mn, (int)st.size());
        }
        else
            st.clear();
    }
    cout << mn;
    return 0;
}