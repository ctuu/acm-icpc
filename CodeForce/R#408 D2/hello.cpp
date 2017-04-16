#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> no;
    no.resize(n);
    if (no.size() == n)
        cout << "ok" << endl;
    return 0;
}
