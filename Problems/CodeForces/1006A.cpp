#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    v.resize(n);
    for(auto &i: v)
    {
        cin >> i;
        i = i % 2 ? i : i - 1;
    }
    for(auto i: v)
        cout << i << " ";
    cout << endl;
    return 0;
}