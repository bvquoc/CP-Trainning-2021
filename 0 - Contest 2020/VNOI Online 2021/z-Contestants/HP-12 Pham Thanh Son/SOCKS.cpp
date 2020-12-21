#include<bits/stdc++.h>
using namespace std;
#define int long long
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){ return rng()%(r-l+1)+l;}
#define pii pair<int,int>
#define fi first
#define se second
#define getbit(i,x) ((x>>i)&1ll)
#define tatbit(i,x) (x&~(1ll<<i))
#define batbit(i,x) (x|(1ll<<i))

const int maxn=5e5+5;

int n,q;
int a[maxn];
int Q[maxn];
vector<int> ad[maxn];

int SUB1=1,RED=0;

int pd[20][maxn],h[maxn];
int st[maxn],ed[maxn],id;

int sl,MEM[maxn],R[5];
int ROOT;
void dfs(int u,int par){
    st[u]=ed[u]=++id;

    forinc(i,1,19) pd[i][u]=pd[i-1][pd[i-1][u]];

    for(auto &v:ad[u]) if(v!=par){
        if(u==ROOT){
          //  cout<<ROOT<<" "<<v<<" "<<u<<"\n";
            sl++;
        }
        pd[0][v]=u;
        MEM[v]=sl;
        h[v]=h[u]+1;
        dfs(v,u);
    }
    ed[u]=id;
}

int LCA(int u,int v){
    if(h[u]<h[v]) swap(u,v);
    fordec(i,19,0){
        if(h[u]-(1ll<<i)>=h[v]) u=pd[i][u];
    }
    if(u==v) return u;
    fordec(i,19,0){
        if(pd[i][u]!=pd[i][v]) u=pd[i][u],v=pd[i][v];
    }
    return pd[0][u];
}

bool cmp(int a,int b) {return st[a]<st[b];}

main(){
    freopen("SOCKS.inp","r",stdin);
    freopen("SOCKS.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>n>>q;
    forinc(i,1,n){
        cin>>a[i];
        if(a[i]) RED++;
    }

    forinc(i,1,n-1){
        int u,v;
        cin>>u>>v;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }
    forinc(i,1,q) cin>>Q[i];
    forinc(i,1,n){
        if(ad[i].size()>2) SUB1=0;
    }

    if(SUB1){
        forinc(i,1,q){
            if(RED>=2) cout<<1<<"\n";
            else cout<<0<<"\n";
            a[Q[i]]=1-a[Q[i]];
            if(a[Q[i]]==0) RED--;
            else RED++;
        }
    }else{
        forinc(i,1,n) if(ad[i].size()==3) ROOT=i;
        dfs(ROOT,0);

        forinc(i,1,n) if(a[i]) R[MEM[i]]++;
        forinc(i,1,q){
            int A=R[1],b=R[2],c=R[3];
            if(A>=1&&b>=1&&c>=1) cout<<2<<"\n";
            else if((A>=1&&b>=1)||(A>=1||c>=1)||(c>=1||b>=1)||(A>=2)||(b>=2)||(c>=2)) cout<<1<<"\n";
            else cout<<0<<"\n";
            int tmp=Q[i];
            if(a[tmp]==0) R[MEM[tmp]]++;
            else R[MEM[tmp]]--;
            a[tmp]=1-a[tmp];
        }
    }

}
