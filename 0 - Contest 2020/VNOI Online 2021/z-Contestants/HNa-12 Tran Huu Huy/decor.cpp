#include<bits/stdc++.h>
using namespace std;
#define Soloz "decor"
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
int n,m,k;
const int maxn=5e5+5;
int a[maxn],mcd[maxn];
string s;
vector < int > adj[maxn];
void sub1()
{
    int l=0,r=n+1;
    while(r-l>1)
    {
        int mid=(r+l)>>1;
        int check=0;
        FOR(i,1,n-mid+1)
        {
            int L=i;
            int R=i+mid-1;
            if(mid-mcd[R]+mcd[L-1]<=k)
            {
                l=mid;
                check=1;
                break;
            }
        }
        if(check==0)
            r=mid;
    }
    FOR(i,1,n-l+1)
    {
        int L=i;
        int R=i+l-1;
        if(l-mcd[R]+mcd[L-1]<=k)
        {
            cout<<L<<" "<<R;
            exit(0);
        }
    }
    cout<<"-1";
}

int dd[maxn];
int numhave=0;
vector < int > tplt[maxn];
int vallt[maxn];
int Callt[maxn];
int numlt=0;
int type[maxn];
void dfs(int u,int cnt)
{
    dd[u]=1;
    tplt[cnt].ep(u);
    numhave=numhave+s[u-1]-'0';
    for(auto v : adj[u])
    {
        if(dd[v])
            continue;
        dfs(v,cnt);
    }
}

int ANSW[maxn];

void sub2()
{
    for(int i=1;i<=n;++i)
    {
        if(dd[i]==1)
            continue;
        ++numlt;
        numhave=0;
        dfs(i,numlt);
        for(auto v : tplt[numlt])
            type[v]=numlt;
        vallt[numlt]=numhave;
    }
    for(int i=1;i<=numlt;++i)
        sort(tplt[i].begin(),tplt[i].end());
    int l=0,r=n+1;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        int check=0;
        for(int i=1;i<=n-mid+1;++i)
        {
            int L=i;
            int R=i+mid-1;
            for(int i=1;i<=numlt;++i)
                Callt[i]=vallt[i];
            int SUM=0;
            for(int j=L;j<=R;++j)
            {
                int depen=type[j];
                if(Callt[depen]>0)
                {
                    ++SUM;
                    Callt[depen]--;
                }
            }
            if(mid-SUM<=k)
            {
                l=mid;
                ANSW[mid]=L;
                break;
                check=1;
            }
        }
        if(check==0)
            r=mid;
    }
    if(l==0)
    {
        cout<<"-1";
        exit(0);
    }
    cout<<ANSW[l]<<" "<<ANSW[l]+l-1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Soloz".inp","r",stdin);
    freopen(Soloz".out","w",stdout);
    cin>>n>>m>>k;
    cin>>s;
    FOR(i,1,n) a[i]=s[i-1]-'0';
    FOR(i,1,n) mcd[i]=mcd[i-1]+a[i];
    if(m==0)
        sub1();
    FOR(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        adj[u].ep(v);
        adj[v].ep(u);
    }
    sub2();
    return 0;
}
