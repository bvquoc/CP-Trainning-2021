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
const int N=5000010;
int f[N];
vector<int> e;
int F(int x)
{
    if(x<=N-10) return f[x];
    int s=(x-5000001)/50000+1;
    return s+f[x-50000*s];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("ODDCOIN.inp","r",stdin);
    freopen("ODDCOIN.out","w",stdout);
    int t;cin>>t;
    e.pb(1);e.pb(3);e.pb(5);
    e.pb(10);e.pb(30);e.pb(50);
    e.pb(100);e.pb(300);e.pb(500);
    e.pb(1000);e.pb(3000);e.pb(5000);
    e.pb(10000);e.pb(30000);e.pb(50000);
    reset(f,127);
    int oo=f[0];
    f[0]=0;
    forinc(i,0,N-10) if(f[i]!=oo)
    forv(x,e) if(i+x<=N-10) f[i+x]=min(f[i+x],f[i]+1);
    while(t--)
    {
        int x,n;
        cin>>x>>n;
        if(!x) {cout<<F(n)<<"\n";continue;}
        int ans=1e9;
        forinc(i,0,min(1000000,n/x)) ans=min(ans,i+F(n-x*i));
        cout<<ans<<"\n";
    }
}
