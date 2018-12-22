#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        int f = n / m;
        for(int i = 0; i < m - 1; ++i)
            cout << string(f, (char)'a'+i);
        cout << string(n - (m-1)*f, (char)'a' + m - 1);
        cout << endl;
    }
    return 0;
}
