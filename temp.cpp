#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;

struct test
{
    vector<array<int, 26>> child;

    void cr()
    {
        array<int, 26> a;
        child.push_back(a);
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    test e;
    array<int, 26> b;
    e.child.push_back(b);
    cout << e.child.size() << endl;
    e.cr();
    cout << e.child.size() << endl;
    return 0;
}