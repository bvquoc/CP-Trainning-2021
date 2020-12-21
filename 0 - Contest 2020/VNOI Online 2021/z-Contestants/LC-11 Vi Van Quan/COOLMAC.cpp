///WizardAP
#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define Nothing "COOLMAC"
#define ft first
#define sd second
using namespace std;
using ii =pair<int,int>;
using LL = long long;
const int inf=1e9;
bool cmp(ii x,ii y)
{
    return (x.sd<y.sd||(x.sd==y.sd&&x.ft<y.ft));
}
int n,m;
ii q[100005];
int LIMIT=1e5+5;
LL dp[100005];
int cnp(int poo)
{
    int lim=max(q[poo].ft,LIMIT);
    int l=1,r=poo-1,ans=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if (q[mid].sd>=lim)
        {
            r=mid-1;
            ans=mid;
        }
        else l=mid+1;
    }
    return ans;
}
namespace sub1
{
int f[1000005];
void update(int l,int r)
{
    for (int i=LIMIT; i<=100000; i++)
        f[i]=1;
    for (int i=LIMIT; i<=100000; i++)
        f[i]+=f[i-1];
}
int Get(int l,int r)
{
    return f[r]-f[l-1];
}
void solve()
{
    update(LIMIT,100000);
    int Sum=100000-LIMIT+1;
    int res=1e9;
    for (int mask=0; mask<(1<<m); mask++)
    {
        int NSUM=0,cnt=0;
        for (int i=0; i<m; i++)
            if (((mask>>i)&1)==1)
            {

                NSUM+=Get(q[i+1].ft,q[i+1].sd),cnt++;
            }
        if (Sum-NSUM<=0) res=min(res,cnt);
    }
    cout<<(res==inf ? -1 : res)<<"\n";
}
}

signed main()
{
    FastIO;
    freopen(Nothing".inp","r",stdin);
    freopen(Nothing".out","w",stdout);
    cin>>m;
    for (int i=1; i<=m; i++)
    {
        cin>>q[i].ft>>q[i].sd;
    }
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        LIMIT=min(x,LIMIT);
    }
    for (int i=0; i<=n; i++) dp[i]=inf;
    if (n<=10&&m<=16)   sub1::solve();
    else
    {

        sort(q+1,q+1+m,cmp);
        for (int i=1; i<=m; i++)
            if (q[i].sd<LIMIT) continue;
            else
            {
                int chosen=cnp(i);
                //    cout<<chosen<<"\n";
                if (q[i].ft<LIMIT) dp[i]=1;
                else
                    dp[i]=dp[chosen]+1;
                // cout<<dp[i]<<"\n\n";
            }
        LL res=inf;
        for (int i=1; i<=m; i++)
            if (q[i].sd==100000) res=min(res,dp[i]);
        cout<<(res == inf ?-1 : res);
    }
    return 0;
}
