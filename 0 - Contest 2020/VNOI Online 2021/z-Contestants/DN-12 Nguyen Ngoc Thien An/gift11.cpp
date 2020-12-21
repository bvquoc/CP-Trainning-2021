#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")

using namespace std;

#define X first
#define Y second
#define ll long long
#define ld double
#define up_b upper_bound
#define low_b lower_bound
#define pb push_back
#define mp make_pair

typedef pair<int,int> pii;

const int mod=998244353;
const int N=1e5;


pii origin;
void operator-=(pii &A, pii B) {
    A.X -= B.X;
    A.Y -= B.Y;
}
bool ccw(pii O, pii A, pii B) {
    A -= O, B -= O;
    return A.X * B.Y > A.Y * B.X;
}
bool cmp(pii A, pii B) { return ccw(origin, A, B); }

ll Power(int x,int y)
{
    ll ans=1;
    for (ll t=x;y;y>>=1)
    {
        if (y&1) ans=(ans*t);
        t=(t*t);
    }
    return ans;
}
int Rev(int x)
{
    return Power(x,mod-2);
}
int a[N+5];
int hv[N+5];
int ok[N+5];
pii p[N+5];
int m,n;
ll ans=0;
pii val(int x)
{
    pii d=mp(0,-1);
    while (x)
    {
        d.Y=-d.Y;
        d.X=(d.X+d.Y*(x%10)+11)%11;
        x/=10;
    }
    return d;
}
void vet(int d)
{
    if (d>n)
    {
//        for (int i=1;i<=n;i++) cout<<hv[i]<<' ';cout<<endl;
        int s=0;
        int r=-1;
        for (int i=1;i<=n;i++)
        {
            s=(s+r*p[hv[i]].X+11)%11;
            r*=p[hv[i]].Y;
            r=-r;
        }
        if (!s) ans++;
        return;
    }
    for (int i=1;i<=n;i++)
    {
        if (ok[i]) continue;
        hv[d]=i;
        ok[i]=1;
        vet(d+1);
        ok[i]=0;
    }
}
void sub1()
{
    ans=0;
    vet(1);
    cout<<ans<<"\n";
}
void sub2()
{
    int res=0;
    for (int i=1;i<=n;i++) res=(res+11+p[i].X)%11;
    if (res) cout<<0;
    else
    {
        ll ans=1;
        for (int i=1;i<=n;i++) ans=(ans*i)%mod;
        cout<<ans;
    }
}
int f[2005][1005][11];
void sub3()
{
    int k=ceil(1.0*n/2);
    for (int i=1;i<=n;i++)
    for (int j=0;j<=k;j++)
    for (int t=0;t<=10;t++) f[i][j][t]=0;
    f[0][0][0]=1;
//    for (int i=1;i<=n;i++)
    for (int i=1;i<=n;i++)
    for (int j=0;j<=min(k,i);j++)
    for (int t=0;t<=10;t++)
    {
        if (j) f[i][j][t]=(f[i][j][t]+f[i-1][j-1][(t-p[i].X+11)%11])%mod;
        f[i][j][t]=(f[i][j][t]+f[i-1][j][(t+p[i].X)%11])%mod;
    }
    int res=f[n][k][0];
//    cout<<n<<' '<<k<<' '<<res<<endl;
    ll T=1;
    for (int i=1;i<=k;i++)
    {
        T=(1ll*T*i)%mod;
        if (i==k) res=(1ll*res*T)%mod;
        if (i==n-k) res=(1ll*res*T)%mod;
    }
    cout<<res<<"\n";

}
int main()
{
    freopen("gift11.inp","r",stdin);
    freopen("gift11.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;

    while (T--)
    {

        cin>>n;
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=1;i<=n;i++)
            p[i]=val(a[i]);
//        for (int i=1;i<=n;i++)
//            cout<<p[i].X<<' '<<p[i].Y<<endl;
        if (n<=8) { sub1();continue;}
        int sum=0;
        for (int i=1;i<=n;i++) sum+=p[i].Y;
        if (sum==-n) {sub2();continue;}
        if (sum==n) {sub3();continue;}
    }
}
