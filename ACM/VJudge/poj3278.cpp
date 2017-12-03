#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, ans = 0;
    cin >> n >> k;
    bool vis[400000] = {0};
    queue<pair<int,int> > qu;
    vis[n] = 1;
    qu.push(make_pair(n, 0));
    while(!qu.empty())
    {
        pair<int,int> tp = qu.front();
        qu.pop();
        if(tp.first == k)
        {
            ans = tp.second;
            break;
        }
        if(!vis[tp.first-1]&& tp.first > 0)
        {
            vis[tp.first-1] = 1;
            qu.push(make_pair(tp.first-1, tp.second+1));
        }
        if(!vis[tp.first+1] && tp.first <= 100000)
        {
            vis[tp.first+1] = 1;
            qu.push(make_pair(tp.first+1, tp.second+1));
        }
        if(!vis[2*tp.first] && tp.first <= 50000)
        {
            vis[2*tp.first] = 1;
            qu.push(make_pair(2*tp.first, tp.second+1));
        }
    }
    cout << ans<<endl;
    return 0;
}