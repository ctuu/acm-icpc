//Author: xiaowuga
#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define MAX INT_MAX
#define mem(s,ch) memset(s,ch,sizeof(s))
const long long N=100000; 
const long long mod=1e9+7; 
typedef long long LL;
typedef int II;
typedef unsigned long long ull;
#define nc cout<<"nc"<<endl
#define sp " "
LL n,m;
vector<pair<int,int> >G[N];
LL in[N],dp[N];
void init(){
    for(II i=0;i<=n;i++) G[i].clear();
    mem(in,0);
    mem(dp,0);
}
void topo(){
    queue<LL>q;
    for(II i=1;i<=n;i++){
        if(!in[i]) q.push(i);
    }
    while(!q.empty()){
        LL u=q.front();q.pop();
        for(II i=0;i<G[u].size();i++){
            LL v=G[u][i].first,w=G[u][i].second;
            dp[v]=max(dp[v],dp[u]+w);
            in[v]--;
            if(!in[v]) q.push(v);
        }
    }
}
int main() {
	ios::sync_with_stdio(false);cin.tie(0);
    II T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        init();
        for(II i=0;i<m;i++){
            LL x,y,z;
            cin>>x>>y>>z;
            LL a=max(x,y),b=min(x,y);
            G[a].push_back(make_pair(b,z));
            in[b]++;
        }        
        topo();
        LL ans=0;
        for(II i=1;i<=n;i++){
            ans=max(ans,dp[i]); 
        }
        cout<<ans<<endl;
    }
	return 0;
}
