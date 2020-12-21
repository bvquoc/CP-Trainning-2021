#include<bits/stdc++.h>

using namespace std;

#define task "GIFT11"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define zs(v) ((int)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define CNTBIT __builtin_popcountll
#define ALL(v) (v).begin(),(v).end()
#define endl '\n'

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;

const int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
const int dxx[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};

const ll mod=998244353;
const int base=311;
const int N=2005;

int n,sum[N],odd[N];

void sub2()
{
    int s=0;
    for(int i=1;i<=n;++i) s=(sum[i]+s)%11;

    ll ans=1;

    if(s!=0)
    {
        cout<<0<<endl;
    }
    else
    {
        for(int i=1;i<=n;++i) ans=(ans*i)%mod;
        cout<<ans<<endl;
    }
}

ll dp[(1<<20)+5][12];
ll oddsum[N];

void add(ll &a, ll b)
{
    a=(a+b)%mod;
}
void hack()
{
    dp[0][0]=1;

    for(int mask=1;mask<(1<<n);++mask)
    {
        int cur=0;
        for(int i=1;i<=n;++i) if(BIT(mask,i-1))
        {
            if(odd[i]) cur=1-cur;
        }
        oddsum[mask]=cur;
    }

    for(int mask=0;mask<(1<<n)-1;++mask)
    {
        for(int i=1;i<=n;++i) if(BIT(mask,i-1)==0)
        {
            int nmask=mask+(1<<(i-1));

            for(int j=0;j<11;++j)
            {
                if(oddsum[mask]==0)
                {
                    add(dp[nmask][(j+sum[i])%11],dp[mask][j]);
                }
                else
                {
                    add(dp[nmask][(j-sum[i]+11*11)%11],dp[mask][j]);
                }
            }
        }
    }

    cout<<dp[(1<<n)-1][0]<<endl;

    for(int mask=0;mask<(1<<n);++mask)
    for(int j=0;j<11;++j) dp[mask][j]=0;
}
ll f[N][1100][12];
ll fact[N];

void sub3()
{
    for(int i=0;i<=n;++i)
    for(int j=0;j<=n;++j)
    for(int k=0;k<11;++k)
    {
        f[i][j][k]=0;
    }

    f[0][0][0]=1;

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=(n+1)/2;++j)
        {
            for(int k=0;k<11;++k)
            {
                add(f[i+1][j][k],f[i][j][k]);
                add(f[i+1][j+1][(k+sum[i+1])%11],f[i][j][k]*(j+1)%mod);
            }
        }
    }

    int num=(n+1)/2;

    ll s=0;

    for(int i=1;i<=n;++i)
    {
        s+=sum[i];
    }

    fact[0]=1;
    for(int i=1;i<=n;++i)
    {
        fact[i]=fact[i-1]*i%mod;
    }

    ll ans=0;

    for(int k=0;k<11;++k)
    {
        if(k-(s-k)%11==0) add(ans,f[n][num][k]*fact[n-num]%mod);
    }

    cout<<ans<<endl;
}
void gogo()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        string s;
        cin>>s;

        int sumodd=0, sumeven=0;

        for(int j=1;j<=zs(s);++j)
        {
            if(j%2==1) sumodd=(sumodd+s[j-1]-'0')%11;
            else sumeven=(sumeven+s[j-1]-'0')%11;
        }

        sum[i]=(sumodd-sumeven+11)%11;
        odd[i]=(zs(s)%2==1);
    }

//    sub3();

    if(n<=20) hack();
    else
    {
        int ok=1;
        for(int i=1;i<=n;++i)
        {
            ok&=(!odd[i]);
        }
        if(ok) sub2();
        else
        {
            int ok1=1;
            for(int i=1;i<=n;++i)
            {
                ok1&=(odd[i]==1);
            }
            if(ok1) sub3();
            else cout<<0<<endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }

    int t;
    cin>>t;
    while(t--) gogo();

    return 0;
}







