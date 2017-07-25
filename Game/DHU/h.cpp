#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> numb;
        numb.resize(n);
        for (auto &i: numb)
            cin >> i;
        sort(numb.begin(),numb.end());
        int aver = numb[0];
        for (int i = 1; i < n; ++i)
            aver = (aver + numb[i]) / 2;
        cout << aver << endl;
    }
    return 0;
}