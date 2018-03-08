#include<cstdio>
#define MOD 1000000007
typedef long long ll;
ll n;
ll pow(ll a,ll b){
    ll r=1,base=a%MOD;
    while(b){
        if(b&1) r*=base , r%=MOD;
        base*=base;
        base%=MOD;
        b>>=1;
    }
    return r;
}
int main()
{
    while(scanf("%lld",&n)!=EOF)
    {
        printf("%lld\n",(pow(2,n)-1)%MOD);
    }
}