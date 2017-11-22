#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> num;
    int n;
    cin >> n;//容量
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        num.push_back(tmp);
    }
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                cout << num[j] << " ";
        cout << endl;
    }
    return 0;
}