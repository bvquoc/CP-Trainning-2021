#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define ll long long
#define ld double
#define up_b upper_bound
#define low_b lower_bound
#define mp make_pair
#define pb push_back

typedef pair<int,int> pii;

const int oo=1e9;
const int mod=1e9+7;
const int N=2e5;

template<class T> void ckmax(T &a,T b) {a=max(a,b);}
template<class T> void ckmin(T &a,T b) {a=min(a,b);}

ll Power(int x,int y)
{
    ll ans=1;
    for (ll t=x;y;y>>=1)
    {
        if (y&1) ans=(ans*t)%mod;
        t=(t*t)%mod;
    }
    return  ans;
}
ll Rev(int x)
{
    return Power(x,mod-2);
}
int a[N+5],b[N+5];
ll f[N+5];
ll gt[N+5];
int n;
void calcf()
{
    f[1]=0;
    gt[0]=1;
    for (int i=1;i<=n;i++) gt[i]=(gt[i-1]*i)%mod;
    for (int i=2;i<=n;i++)
        f[i]=(f[i-1]*i+(gt[i-1]*((1ll*i*(i-1)/2)%mod)))%mod;
}
int fw[N+5];
void update(int x)
{
    for (;x<=n;x+=x&-x) fw[x]++;
}
int get(int x)
{
    int ans=0;for (;x;x-=x&-x) ans+=fw[x];return ans;
}
ll calc(int p[])
{
    for (int i=1;i<=n;i++) fw[i]=0;
    ll ans=0;
    ll sum=0;
    for (int i=1;i<=n-1;i++)
    {
        update(p[i]);
        ll x=p[i]-get(p[i]);
        ans=(ans+gt[n-i]*((sum*x)%mod)+(f[n-i]*x)%mod+gt[n-i]*((x*(x-1)/2)%mod))%mod;
//        cout<<x<<' '<<gt[n-i]<<' '<<f[n-i]<<' '<<sum<<' '<<ans<<endl;
        sum=(sum+x)%mod;
    }
    return ans;
}
int ok[N+5];
int hv[N+5];
ll res=0;
void vet(int d)
{
    if (d>6)
    {
        for (int i=1;i<=n;i++) cout<<hv[i]<<' ';
        for (int i=1;i<=n;i++) fw[i]=0;
        ll ans=0;
        for (int i=n;i>=1;i--)
        {
            ans=(ans+get(hv[i]))%mod;
            update(hv[i]);
        }
        res+=ans;
        cout<<"  "<<ans<<' '<<res<<"\n";
        return;
    }
    for (int i=1;i<=n;i++)
    {
        if (ok[i]) continue;
        ok[i]=1;
        hv[d]=i;
        vet(d+1);
        ok[i]=0;
    }
}
int main()
{
    freopen("PERMEOW.inp","r",stdin);
    freopen("PERMEOW.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    calcf();
    ll ans=(calc(b)-calc(a)+mod)%mod;
    for (int i=1;i<=n;i++) fw[i]=0;
    for (int i=n;i>=1;i--)
    {
        ans=(ans+get(b[i]))%mod;
        update(b[i]);
    }
//    cout<<calc(b)<<endl;
    cout<<ans<<endl;
//    cout<<calc(b)<<' '<<calc(a)<<' '<<ans<<endl;
//    vet(1);

}

