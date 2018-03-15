#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x,y;
    string s;
    cin >> n;
    while(n--)
    {
        cin >> s >> x >> y;
        if(x < 15 || x > 20 || y < 50 || y > 70)
            cout << s << endl;
    }
    return 0;
}