#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
#define k 30
bool a[k];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a = "abbbb";
    cout << a.rfind("bbbb") << " " << a.size() << " " << endl;
    cout << a.substr(0, 1);
    return 0;
}