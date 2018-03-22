#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int n;
    cin >> n;
    cin >> s;
    int ct = n;
    for(int i = 0;i < n-1; ++i)
    {
        if(s[i] ==  'U' && s[i+1] == 'R')
        {
            i++;
            ct--;
        }
        else if(s[i] ==  'R' && s[i+1] == 'U')
        {
            i++;
            ct--;
        }
    }
    cout << ct << endl;
    return 0;
}