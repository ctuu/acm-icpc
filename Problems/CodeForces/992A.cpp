#include <iostream>
#include <array>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    set<int> st;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        if (t != 0)
            st.insert(t);
    }
    cout << st.size() << endl;
    return 0;
}