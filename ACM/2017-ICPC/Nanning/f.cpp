#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int dp[maxn],ans[maxn];
int main()
{
    int n,temp=0;
    while(cin>>n) {
        if(n<0) continue;
        else {
            if(n>=10000) {
                for(int i=0;i<5;i++) {
                    ans[temp+i]=n%10000;
                }
                temp+=5;
            }
            else {ans[temp]=n;temp++;}
        }
    }
    int len=0;
    dp[0]=ans[0];
    for(int i=1;i<temp;i++) {
        if(ans[i]>=dp[len]) {
            dp[++len]=ans[i];
        }
        else {
            int x=upper_bound(dp,dp+len,ans[i])-dp;
            dp[x]=ans[i];
        }
    }
    cout<<len+1<<endl;
    return 0;
}