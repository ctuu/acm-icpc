#include <iostream>
#include <algorithm>
#include <array>
#include <set>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    array<int, 102> ar;
    set<int> st;
    ar.fill(0);
    int n, tmp;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        ar[tmp]++;
        st.insert(tmp);
    }
    sort(ar.begin(), ar.end(), greater<int>());
    if (ar[0] == ar[1] && ar[2] == 0)
    {
        cout << "YES" << endl;
        for (auto i: st)
            cout << i << " ";
    }
    else
        cout << "NO";
    return 0;
}