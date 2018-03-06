#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define LL long long
LL bfs(LL n)
{
    queue<LL> m;
    m.push(1);
    while(!m.empty())
    {
        LL i = m.front();
        if(i % n == 0)
            return i;
        m.pop();
        m.push(i * 10);
        m.push(i * 10 + 1);
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    LL n;
    while(cin >> n && n)
        cout << bfs(n)<<endl;
    return 0;
}