#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    string st;
    cin >> n >> st;
    for(int i = 1; i <= n; ++i)
    {
        if(n % i == 0)
        {
            string tt = st.substr(0, i);
            // tt.reserve();
            reverse(tt.begin(), tt.end());
            string tm = st.substr(i);
            // cout << tt <<" " << tm <<  endl;
            st = tt + tm;
            // st = st.substr(0, i) + st.substr(i);
        }
    }        
    cout << st << endl;
    return 0;
}