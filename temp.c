#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int dp[102][1002];
int main(){
    int T;scanf("%d",&T);
    while(T--){
            int N,M,L;scanf("%d%d%d",&N,&M,&L);
            memset(dp,-1,sizeof(dp));
            for(int i=0;i<=L;i++) dp[0][i]=0;
            for(int i=0;i<N;i++) {
                    int time,value;
                    scanf("%d%d",&time,&value);
                    for(int j=M;j>=1;j--)
                        for(int k=L;k>=time;k--)
                            dp[j][k]=max(dp[j][k],dp[j-1][k-time]+value);
            }//for
            if(dp[M][L]<0) printf("0\n");
            else printf("%d\n",dp[M][L]);
    }
    return 0;
}
