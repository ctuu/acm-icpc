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
    cin >> s;
    int ct = 0;
    for(int c = 0; c < s.size(); ++c)
    {
        if(s[c] =='a'||s[c] =='e'||s[c]=='i'||s[c]=='o'||s[c]=='u'||s[c] =='1'||s[c] =='3'||s[c] =='5'||s[c] =='7'||s[c] =='9')
        ct++;
    }
    cout << ct;
    return 0;
}