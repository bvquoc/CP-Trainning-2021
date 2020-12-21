#include <bits/stdc++.h>

using namespace std;
const int N=2e5+5;
#define TASK "PERMEOW"
#define ll long long
const int mod=1e9+7;
int n;
int a[N],b[N];
bool T1=true,T2=true;
int ans=0;
int gt[N],igt[N];
void inp()
{
    cin>>n;
    for(int i=1; i<=n; ++i)
        cin>>a[i];
    for(int i=1; i<=n; ++i)
        cin>>b[i];
}
void subTask()
{
    for(int i=1; i<=n; ++i)
    {
        T1&=(a[i]==b[i]);
        T2&=((a[i]==i)&&(a[i]==b[n-i+1]));
    }
}
void add(int &x,int y)
{
    x+=y;
    if(x>=mod)
        x-=mod;
}
struct BinaryIndexTree
{
    int t[N];
    void init()
    {
        fill(t+1,t+n+1,0);
    }
    int Get(int x)
    {
        int res=0;
        for(; x<=n; x+=x&(-x))
            res+=t[x];
        return res;
    }
    void Update(int x)
    {
        for(; x; x-=x&(-x))
            ++t[x];
    }
} BIT;
int calc()
{
    int res=0;
    BIT.init();
    for(int i=1; i<=n; ++i)
    {
        add(res,BIT.Get(a[i]+1));
        BIT.Update(a[i]);
    }
    return res;
}
int pw(int x,int m)
{
    if(m==0)
        return 1;
    if(m==1)
        return x;
    int res=pw(x,m>>1);
    res=1ll*res*res%mod;
    return 1ll*res*pw(x,m&1)%mod;
}
void giaithua()
{
    gt[0]=1;
    for(int i=1; i<=n; ++i)
        gt[i]=1ll*gt[i-1]*i%mod;
    igt[n]=pw(gt[n],mod-2);
    for(int i=n-1; i>=0; --i)
        igt[i]=1ll*igt[i+1]*(i+1)%mod;
}
int Ckn(int n,int k)
{
    return 1ll*(1ll*gt[n]*igt[n-k]%mod)*igt[k]%mod;
}
/*struct Sub2
{
    int f[2005][2005],g[2005];
    void solve()
    {
        g[0]=0;
        for(int i=1; i<=n; ++i)
        {
            for(int x=1; x<=i; ++x)
            {
                add(f[i][x],1ll*g[i-1]*(i-x)%mod);
                add(g[i],f[i][x]);
            }
        }
        cout<<g[n];
    }
} sub2;*/
bool check()
{
    for(int i=1; i<=n; ++i)
    {
        if(a[i]>b[i])
            return false;
        if(a[i]<b[i])
            return true;
    }
    return true;
}
void trau()
{
    while(check())
    {
        add(ans,calc());
        if(!next_permutation(a+1,a+n+1))
            break;
    }
    cout<<ans<<'\n';
}
void solve()
{
    if(T1)
    {
        cout<<calc();
        return;
    }
    if(n<=10)
    {
        trau();
        return;
    }
    giaithua();
    ans=0;
    for(int i=1; i<=n; ++i)
        for(int x=1; x<=n; ++x)
            for(int j=min(n-x,i-1); j>=1; --j)
            {
                if((i-1-j)>x-1)
                    break;
                int res=1ll*j*Ckn(n-x,j)%mod;
                res=1ll*res*Ckn(x-1,(i-1-j))%mod;
                res=1ll*res*gt[i-1]%mod;
                res=1ll*res*gt[n-i]%mod;
                add(ans,res);
                //cout<<i<<' '<<x<<' '<<j<<' '<<res<<'\n';
            }
    cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    inp();
    subTask();
    solve();
    return 0;
}
