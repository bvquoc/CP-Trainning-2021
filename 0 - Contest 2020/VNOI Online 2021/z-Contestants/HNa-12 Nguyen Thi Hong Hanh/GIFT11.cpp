#include <bits/stdc++.h>

using namespace std;
const int N=2005;
#define TASK "GIFT11"
#define ll long long
const int mod=998244353;
int T;
int n;
int val[N];
string a[N];
int ans=0;
int odd,even;
void inp()
{
    cin>>n;
    odd=even=0;
    for(int i=1; i<=n; ++i)
    {
        cin>>a[i];
        val[i]=0;
        for(int j=0; j<a[i].size(); ++j)
        {
            if(j&1)
                val[i]+=(a[i][j]-'0');
            else
                val[i]-=(a[i][j]-'0');
        }
        val[i]%=11;
        odd+=((a[i].size())&1);
        even+=(!((a[i].size())&1));
    }
}
void add(int &x,int y)
{
    x+=y;
    if(x>=mod)
        x-=mod;
}
struct Sub1
{
    int pos[11];
    int sum[2];
    bool check()
    {
        sum[0]=sum[1]=0;
        int i=0;
        for(int j=1; j<=n; ++j)
        {
            int id=pos[j];
            for(int k=0; k<a[id].size(); ++k)
            {
                sum[i&1]+=(a[id][k]-'0');
                ++i;
            }
        }
        return (sum[0]-sum[1])%11==0;
    }
    void solve()
    {
        ans=0;
        for(int i=1; i<=n; ++i)
            pos[i]=i;
        do
        {
            add(ans,check());
        }
        while(next_permutation(pos+1,pos+n+1));
        cout<<ans<<'\n';
    }
} sub1;
int gt[N];
void giaithua()
{
    gt[0]=1;
    for(int i=1; i<=2000; ++i)
        gt[i]=1ll*i*gt[i-1]%mod;
}
struct Sub2
{
    void solve()
    {
        int res=0;
        int i=0;
        for(int j=1; j<=n; ++j)
            res+=val[j];
        if(res%11)
        {
            cout<<0<<'\n';
            return;
        }
        cout<<gt[n]<<'\n';
    }
} sub2;
struct Sub3
{
    int f[2005][20];
    void init()
    {
        for(int i=0; i<=n; ++i)
            for(int x=0; x<=10; ++x)
                f[i][x]=0;
    }
    void solve()
    {
        int sum=0;
        init();
        for(int i=1; i<=n; ++i)
            sum+=val[i];
        sum=(sum%11+11)%11;
        f[0][0]=1;
        for(int i=1; i<=n; ++i)
            for(int j=i; j>=1; --j)
                for(int x=0; x<11; ++x)
                    add(f[j][((x+val[i])%11+11)%11],f[j-1][x]);
        int x=n/2;
        ans=0;
        for(int y=0; y<11; ++y)
            if(((sum-2*y)%11+11)%11==0)
                add(ans,((1ll*f[x][y]*gt[x]%mod)*gt[n-x])%mod);
        cout<<ans<<'\n';
    }
} sub3;
void solve()
{
    if(even==n)
    {
        sub2.solve();
        return;
    }
    if(n<=8)
    {
        sub1.solve();
        return;
    }
    sub3.solve();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    cin>>T;
    giaithua();
    while(T--)
    {
        inp();
        solve();
    }
    return 0;
}
