#include<stdio.h>
#include<string.h>
int dp[100010];
int tmp[100010];
int max(int a,int b){return a>b?a:b;}
int main()
{
    int n,tot,p,w,v,m,i,j,k;
    while(scanf("%d%d",&n,&tot)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&p,&m);
            memcpy(tmp,dp,sizeof(dp));//继承前面的
            for(j=0;j<m;j++)
            {
                scanf("%d%d",&w,&v);
                for(k=tot-p;k>=w;k--)//按照背包九讲的说法，先将附件进行1次01背包
                    tmp[k]=max(tmp[k],tmp[k-w]+v);
            }
            for(j=p;j<=tot;j++)//更新能更新的
                dp[j]=max(dp[j],tmp[j-p]);
        }
        printf("%d\n",dp[tot]);
    }
    return 0;
}