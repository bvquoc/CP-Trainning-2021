#include<bits/stdc++.h>
using namespace std;
#define int long long
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(i,x) for(auto &i:x)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r)
{
    return l+rng()%(r-l+1);
}
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
#define pii pair<int,int>
#define fi first
#define se second
#define batbit(i,x) (x|(1ll<<i))
#define getbit(i,x) ((x>>i)&1)

const int mn=5e5+10;
int n,m,k,cnt[mn],id[mn],dem[mn],lef,rig;
string s;

int root(int u)
{
    return id[u]<0?u:id[u]=root(id[u]);
}

void join(int u,int v)
{
    if((u=root(u))==(v=root(v)))
        return;
    if(id[u]>id[v])
        swap(u,v);
    id[u]+=id[v];
    id[v]=u;
    cnt[u]+=cnt[v];
}

bool check(int val)
{
    forinc(i,1,n) dem[root(i)]=0;
    int need=0;
    forinc(i,1,val-1)
    {
        dem[root(i)]++;
        if(cnt[root(i)]<dem[root(i)])
            need++;
    }
    forinc(i,val,n)
    {
        int pos=i-val;
        if(pos!=0)
        {
            dem[root(pos)]--;
            if(dem[root(pos)]>=cnt[root(pos)])
                need--;
        }
        if(dem[root(i)]>=cnt[root(i)])
            need++;
        dem[root(i)]++;
        if(need<=k)
        {
            lef=i-val+1,rig=i;
            return true;
        }
    }
    return false;
}

main()
{
    freopen("DECOR.INP","r",stdin);
    freopen("DECOR.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(id,-1,sizeof id);
    cin >> n >> m >> k >> s;
    s=' '+s;
    forinc(i,1,n) if(s[i]=='1')
        cnt[i]=1;
    forinc(i,1,m)
    {
        int u,v;
        cin >> u >> v;
        join(u,v);
    }
    int l=0,r=n,res=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            res=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    if(res==0) return cout <<-1,0;
    cout << lef << " " << rig << "\n";
}
