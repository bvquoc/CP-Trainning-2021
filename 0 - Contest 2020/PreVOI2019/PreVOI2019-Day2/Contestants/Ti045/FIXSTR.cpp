#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)#define onbit(x,i) (x|(1<<(i-1)))#define offbit(x,i) (x&~(1<<(i-1)))
const int N=1e6+10;
int n,m,t[4*N],mem[4*N],bit[N],a[N],sum[N],ans[N],C[N];
pii e[N];
vector<int> ke[N];
string s;
void upd(int i,int x)
{
    for(;i<=n;i+=i&-i) bit[i]+=x;
}
int get(int i)
{
    int g=0;
    for(;i;i-=i&-i) g+=bit[i];
    return g;
}
void build(int s,int l,int r)
{
    if(l==r)
    {
        t[s]=sum[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*s,l,mid);
    build(2*s+1,mid+1,r);
    t[s]=min(t[2*s],t[2*s+1]);
}
void tran(int s)
{
    if(!mem[s]) return;
    t[2*s]+=mem[s];
    t[2*s+1]+=mem[s];
    mem[2*s]+=mem[s];
    mem[2*s+1]+=mem[s];
    mem[s]=0;
}
void update(int s,int l,int r,int u,int v,int x)
{
    if(l>v||r<u) return;
    if(l>=u&&r<=v)
    {
        t[s]+=x;
        mem[s]+=x;
        return;
    }
    tran(s);
    int mid=(l+r)/2;
    update(2*s,l,mid,u,v,x);
    update(2*s+1,mid+1,r,u,v,x);
    t[s]=min(t[2*s],t[2*s+1]);
}
int Min(int s,int l,int r,int u,int v)
{
    if(l>v||r<u) return 1e9;
    if(l>=u&&r<=v) return t[s];
    tran(s);
    int mid=(l+r)/2;
    return min(Min(2*s,l,mid,u,v),Min(2*s+1,mid+1,r,u,v));
}
void Swap(int u)
{
    if(C[u])
    {
        int v=C[u];
        a[v]=-a[v];
        upd(v,2*a[v]);
        update(1,1,n,v,n,2*a[v]);
    }
}
void DFS(int u)
{
    Swap(u);
    if(e[u].fi)
    {
        int L=get(e[u].fi-1),R=get(e[u].se);
        int mi=Min(1,1,n,e[u].fi,e[u].se);
        if(mi<L) ans[u]=L+R-2*mi;
        else ans[u]=R-L;
    }
    forv(v,ke[u]) DFS(v);
    Swap(u);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("FIXSTR.inp","r",stdin);
    freopen("FIXSTR.out","w",stdout);
    char c=getchar();
    while(c!='('&&c!=')') c=getchar();
    while(c=='('||c==')') s+=c,c=getchar();
    forv(x,s)
    {
        a[++n]=((x=='(')?1:-1);
        sum[n]=sum[n-1]+a[n];
    }
    forinc(i,1,n) upd(i,a[i]);
    build(1,1,n);
    m=in;
    forinc(i,1,m)
    {
        char it=getchar();
        while(it<'A'||it>'Z') it=getchar();
        if(it=='U')
        {
            int x=in;
            ke[x-1].pb(i);
        }
        else
        {
            ke[i-1].pb(i);
            if(it=='C') C[i]=in;
            else e[i]={in,in};
        }
    }
    DFS(0);
    forinc(i,1,m) if(e[i].fi) cout<<ans[i]<<"\n";
}
