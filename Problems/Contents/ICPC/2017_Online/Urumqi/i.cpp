#include<cstring>
#include<cstdio>
#define min(x,y) (x<y?x:y)
const int maxn = 2e4+10;
const int maxm = 5e4+10;

struct st{
  int v,nex;
}edge[maxm];

int hed[maxn],vis[maxn],low[maxn],dfn[maxn],belon[maxn],stack[maxn];
int in[maxn],out[maxn];
int n,m,e,top,cnt,num,sum1,sum2;

void init(){
    memset(hed,-1,sizeof(hed));
    memset(vis,0,sizeof(vis));
    memset(dfn,0,sizeof(dfn));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    e=1;
    top=num=cnt=0;
}

void add(int u,int v){
    edge[e].v=v,edge[e].nex=hed[u],hed[u]=e++;
}

void targan(int u){     //缩点
    dfn[u]=low[u]=++num;
    stack[top++]=u;
    vis[u]=1;
    for(int i=hed[u];~i;i=edge[i].nex){
        int v = edge[i].v;
        if(!dfn[v]){
            targan(v);
            low[u]=min(low[u],low[v]);
        }else if(vis[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u]){
        cnt++;
        int x;
        do{
            x=stack[--top];
            vis[x]=0;
            belon[x]=cnt;
        }while(x!=u);
    }
}

int main()
{
    int t;scanf("%d",&t);
    while(t--){
        init();
        scanf("%d%d",&n,&m);
        int mm = m;
        while(m--){
            int u,v;scanf("%d%d",&u,&v);
            add(u,v);
        }
        for(int i=1;i<=n;i++){
            if(!dfn[i])targan(i);
        }
        if(cnt==1){
            printf("0\n");
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j = hed[i];~j;j=edge[j].nex){
                int v = edge[j].v;
                if(belon[i]!=belon[v]){
                    out[belon[i]]=1;       //记录出入度的情况
                    in[belon[v]]=1;
                }
            }
        }
        sum1=sum2=0;
        for(int i=1;i<=cnt;i++){
            if(in[i]==0)sum1++;    //分别统计出入度为0的个数
            if(out[i]==0)sum2++;
        }
        if(sum1<sum2)sum1=sum2;     //答案就是为0的大的一方
        printf("%d\n",sum1);
    }

    return 0;
}