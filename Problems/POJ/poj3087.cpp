#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, n;
    cin >> T;
    for(int t = 0; t < T;)
    {
        int ans = 0;
        cin >> n;
        string a, b, c;
        vector<string> ra,rb;
        cin >> a >> b >> c;
        map<string, bool> vis;
        while(++ans)
        {
            string tmp;
            for(int i = 0; i < n; ++i)
            {
                tmp += b[i];
                tmp += a[i];
            }
            if(tmp == c)
                break;
            if(vis[tmp])
            {
                ans = -1;
                break;
            }
            vis[tmp] = 1;
            a = tmp.substr(0,n);
            b = tmp.substr(n, 2 * n - 1);
            // cout << tmp << " "<< a << " " << b << endl;
        }
        cout << ++t << " " << ans << endl;
    }
    return 0;
}