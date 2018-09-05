#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n; ++i)
        v.push_back(i % 2);
    for (auto c : v)
        cout << c;
    cout << endl;
    return 0;
}