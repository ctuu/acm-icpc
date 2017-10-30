//Author: xiaowuga
#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define MAX INT_MAX
#define mem(s,ch) memset(s,ch,sizeof(s))
const long long N=100000; 
const long long mod=1e9+7; 
typedef long long LL;
typedef unsigned long long ull;
#define nc cout<<"nc"<<endl
#define sp " "
//组合数C(n,m)的公式是n!/(m!*(n-m)!)
//排列数A(n,m)的公式是n!/m!
//所以A(n,m)=C(n,m)*(n-m)!
//Lucas定理用于n,m很大但是mod的时候
vector<LL>fac,finv;
void init_fav_finv(int n){
    fac.resize(n); 
    finv.resize(n);
    fac[0]=1;
    for(int i=1;i<n;i++) fac[i]=fac[i-1]*i%mod;
    finv[1]=1;
    for(int i=2;i<n;i++) finv[i]=finv[mod%i]*(mod-mod/i)%mod;
    finv[0]=1;
    for(int i=1;i<n;i++) finv[i]=finv[i-1]*finv[i]%mod;
}
LL Comb(LL n,LL m){
    return fac[n]*finv[m]%mod*finv[n-m]%mod;
}
LL Perm(LL n,LL m){
    return fac[n]*finv[m]%mod;
}
LL Lucas(LL n,LL m){
    LL ans=1;
    while(n&&m){
        if(n<m) return 0;
        ans=(ans*Comb(n%mod,m%mod))%mod;
        n/=mod;
        m/=mod;
    }
    return ans;
}
int main() {
	ios::sync_with_stdio(false);cin.tie(0);
    init_fav_finv(500);
    cout<<Comb(5,2)<<sp<<Perm(5,2)<<endl;
	return 0;
}

