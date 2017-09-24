#include <iostream>
#include <algorithm>
#include <array>
#include <set>
#include <vector>
#include <string>
using namespace std;
int main()
{
    stringstream foo;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> se;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        se.push_back(tmp);
    }
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                cout << se[j] << " ";
        cout << endl;
    }
    return 0;
}