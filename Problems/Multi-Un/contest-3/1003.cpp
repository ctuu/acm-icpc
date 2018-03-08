#include<cstdio>
#include<iostream>
#include<sstream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<set>
#include<map>
#define INF 0x3f3f3f3f
#define eps 1e-8
using namespace std;
const int MAXN=110000;
int tr[MAXN<<2];
int sorted[MAXN],toleft[20][MAXN],val[20][MAXN];

void build(int l, int r, int dep, int rt)
{
    if(l==r)
    {
        return;
    }
    int mid=(l+r)>>1;
    int lnum=mid-l+1;
    for(int i=l; i<=r; i++)
    {
        if(val[dep][i]<sorted[mid])
        {
            lnum--;
        }
    }
    int lp=l,rp=mid+1;
    int cur_lnum=0;
    for(int i=l; i<=r; i++)
    {
        if(i==l)
        {
            toleft[dep][i]=0;
        }
        else
        {
            toleft[dep][i]=toleft[dep][i-1];
        }
        if(val[dep][i]<sorted[mid])
        {
            toleft[dep][i]++;
            val[dep+1][lp++]=val[dep][i];
        }
        else if(val[dep][i]>sorted[mid])
        {
            val[dep+1][rp++]=val[dep][i];
        }
        else
        {
            if(cur_lnum<lnum)
            {
                cur_lnum++;
                toleft[dep][i]++;
                val[dep+1][lp++]=val[dep][i];
            }
            else
            {
                val[dep+1][rp++]=val[dep][i];
            }
        }
    }
    build(l,mid,dep+1,rt<<1);
    build(mid+1,r,dep+1,rt<<1|1);
}

int query(int l, int r, int L, int R, int k, int dep, int rt)
{
    if(l==r)
    {
        return val[dep][l];
    }
    int lnum,cur_lnum,rnum,cur_rnum;
    int mid=(l+r)>>1;
    if(l==L)
    {
        lnum=toleft[dep][R];
        cur_lnum=0;
    }
    else
    {
        lnum=toleft[dep][R]-toleft[dep][L-1];
        cur_lnum=toleft[dep][L-1];
    }
    if(lnum>=k)
    {
        int newL=l+cur_lnum;
        int newR=l+lnum+cur_lnum-1;
        return query(l,mid,newL,newR,k,dep+1,rt<<1);
    }
    else
    {
        int rnum=R-L+1-lnum;
        int cur_rnum=L-l-cur_lnum;
        int newL=mid+cur_rnum+1;
        int newR=mid+cur_rnum+rnum;
        return query(mid+1,r,newL,newR,k-lnum,dep+1,rt<<1|1);
    }
}

int main()
{
    int cas;
    cin >> cas;
    while(cas--)
    {
        int n,k;
        cin >> n >> k;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&val[0][i]);
            sorted[i]=val[0][i];
        }
        sort(sorted,sorted+n);
        build(0,n-1,0,1);
        long long ans = 0;
        for (int l = 0; l < n; ++l)
            for(int r = l; r < n; ++r)
            {
                if (r - l + 1 < k)
                    continue;
                ans += query(0, n-1, l, r, k, 0, 1);
            }
        cout << ans << endl;
    }
    return 0;
}
