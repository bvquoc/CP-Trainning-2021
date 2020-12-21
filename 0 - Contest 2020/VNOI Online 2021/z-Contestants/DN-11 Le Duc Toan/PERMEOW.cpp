#include<bits/stdc++.h>

using namespace std;

#define task "PERMEOW"
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

const ll mod=1000000007; /// 998244353
const int base=311;
const int N=200005;

int n,a[N],b[N];

void fuck()
{
    int ans=0;
    do
    {
        int tam=0;
        for(int i=1;i<=n;++i)
        {
            if(a[i]!=i) ++tam;
        }

        ans=(ans+max(0,tam-1))%mod;

        int ok=1;

        for(int i=1;i<=n;++i) ok&=(a[i]==b[i]);

        if(ok) break;
    }
    while(next_permutation(a+1,a+n+1));

    cout<<ans;
}
void sub1()
{
    int ans=0;
    for(int i=1;i<=n;++i) ans+=(a[i]!=i);

    ans=max(0,ans-1);

    cout<<ans;
}
void sub2()
{
    ll ans=1;
    for(int i=1;i<=n;++i) ans=(ans*i)%mod;

    ans=(ans*max(1,n-2))%mod;
    ans=(ans+1)%mod;

    cout<<ans;
}
//ll dp[2005][2005];
//ll sum[2005][2005];
//void sub3()
//{
//    dp[0][0]=1;
//    for(int i=1;i<=n;++i)
//    {
//        for(int j=0;j<=i;++j)
//        {
//            dp[i][j]=dp[i-1][j];
//            if(j) dp[i][j]=(dp[i][j]+(i-1)*(j-1)%mod)%mod;
//        }
//    }
//
//    ll ans=0;
//    for(int j=0;j<=n;++j) ans=(ans+dp[n][j])%mod;
//
//    cout<<ans;
//}
void gogo()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i) cin>>b[i];

//    sub3();
//    cout<<endl;
//    fuck();
    if(n<=10) fuck();
    else
    {
        int ok=1;
        for(int i=1;i<=n;++i) ok&=(a[i]==b[i]);

        if(ok) sub1();
        else
        {
            int ok1=1;
            for(int i=1;i<=n;++i) ok1&=(a[i]==i);
            for(int i=1;i<=n;++i) ok1&=(b[i]==n-i+1);

            if(ok1) sub2();
//            else sub3();
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
    gogo();
}







