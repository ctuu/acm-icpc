#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    int p = 0, k = 0, c;
    for (int i = 0; i < n; ++i)
    {
        cin >> c;
        if (c <= p)
        {
            v.push_back(k);
            k = 0;
        }
        ++k;
        p = c;
    }
    v.push_back(k);

    cout << v.size() << endl;
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}