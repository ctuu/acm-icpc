#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int mm=1111;
int f[mm],v[mm];
int i,j,k,n,m,c,ans,t,cs=0;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<=m;++i)f[i]=0;
        f[0]=1,c=m;
        for(i=0;i<n;++i)
            scanf("%d",&v[i]),c-=v[i];
        sort(v,v+n);
        ans=(c>=0);
        if(v[0]<=m)
        for(i=n-1;i>=0;--i)
        {
            if((c=c+v[i])>=0)
                for(j=max(0,c-v[i]+1);j<=c;++j)ans+=f[j];
            for(j=m;j>=v[i];--j)f[j]+=f[j-v[i]];
        }
        printf("%d %d\n",++cs,ans);
    }
    return 0;
}