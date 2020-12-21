#include<bits/stdc++.h>
using namespace std;
#define Soloz "coolmac"
#define F first
#define S second
#define pb push_back
typedef long long ll;
#define fore(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();++it)

template<class T> inline void Write(T x){if(x<0){putchar('-');x*=-1;}if(x>9) Write(x/10);putchar(x%10+'0');}
template<class T>inline void Read(T &x){char c;for(c=getchar();(c>'9'||c<'0')&&c!='-';c=getchar());
T y;if(c=='-')x=0,y=-1;else x=c-'0',y=1;for(c=getchar();c>='0'&&c<='9';c=getchar())x=x*10+c-'0';x*=y;}

mt19937 Rand(time(0));
#define endl "\n"
#define al(a) ((a).begin(),(a).end())
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define ep emplace_back
int m,n;
const int LIM=1e5+1;
const int maxn=1e5+5;
const int mod=1e9+7;
struct Data
{
    int L,R;
}t[LIM+15];
int T[LIM+15];
int a[maxn];


bool Cmp(Data x, Data y)
{
    if(x.L==y.L)
        return x.R<y.R;
    return x.L<y.L;
}

struct SegmentTree
{
    int t[maxn<<2],id[maxn<<2];

    void init(int node, int l, int r)
    {
        if(l==r)
        {
            t[node]=a[l];
            id[l]=node;
            return ;
        }
        int mid=(l+r)>>1;
        init(node<<1,l,mid);
        init(node<<1|1,mid+1,r);
        t[node]=min(t[node<<1],t[node<<1|1]);
    }

    void up(int x, int  val)
    {
        int node=id[x];
        a[x]=min(a[x],val);
        t[node]=min(t[node],val);
        while(node)
        {
            int par=node>>1;
            t[par]=min(t[par<<1],t[par<<1|1]);
            node=par;
        }
    }

    int get(int node, int l, int r, int L, int R)
    {
        if(r<L || l>R)
            return mod;
        if(L<=l && r<=R)
            return t[node];
        int mid=(l+r)>>1;
        int LE=get(node<<1,l,mid,L,R);
        int RI=get(node<<1|1,mid+1,r,L,R);
        return min(LE,RI);
    }
}IT;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Soloz".inp","r",stdin);
    freopen(Soloz".out","w",stdout);
    int limMin=1e5+1;
    cin>>m;
    FOR(i,1,m){
        cin>>t[i].L>>t[i].R;
        ++t[i].L;
        ++t[i].R;
    }
    cin>>n;
    FOR(i,1,n){
        cin>>T[i];
        ++T[i];
        limMin=min(limMin,T[i]);
    }
    FOR(i,1,maxn-1)
    a[i]=1e9+7;
    sort(t+1,t+m+1,Cmp);
    for(int i=1;i<=m;++i)
    {
        if(t[i].L<=limMin && t[i].R>=limMin)
            a[t[i].R]=1;
    }
    IT.init(1,1,LIM);
    for(int i=1;i<=m;++i)
    {
        if(t[i].L<=limMin && t[i].R>=limMin)
            continue;
        if(t[i].R<limMin)
            continue;
        int val=IT.get(1,1,LIM,t[i].L,t[i].R);
        ++val;
        IT.up(t[i].R,val);
    }
    int val=IT.get(1,1,LIM,LIM,LIM);
    if(val==mod)
        cout<<"-1";
    else
        cout<<val;
    return 0;
}
