///WizardAP
#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define Nothing "GIFT11"
#define sz(x) (int)x.size()
#define ft first
#define sd second
using namespace std;
using LL = long long;
using ii =pair<int,int> ;
const LL MOD=998244353;
const int ODD=1;
const int EVEN=0;
int a[2005];
int n;
bool dd[2005];
LL dp[205][3][50][1025];
ii tt[2005];
ii tach(int x)
{
    int type=1;
    int sum=0,dd=0;
    while(x!=0)
    {
        if (type==1) sum+=x%10;
        else sum-=x%10;
        type=1-type;
        dd++;
        x/=10;
    }
if (dd % 2==0) sum=-sum;
return {dd,sum};
}
LL F(int pos,int tf,int sum,int mask)
{
    if (pos==n) {
             return (sum % 11 ==0);
    }
        if (dp[pos][tf][sum][mask]!=-1) return dp[pos][tf][sum][mask];
    LL res=0;
    for (int i=1;i<=n;i++)
    if (((mask>>(i-1))&1)==0) {
            int ttf;
            int nsum=sum;
           if (tt[i].ft%2==ODD&&tf==ODD) ttf=EVEN,nsum-=tt[i].sd;
        if (tt[i].ft%2==EVEN&&tf==EVEN) ttf=EVEN,nsum+=tt[i].sd;
        if (tt[i].ft%2==EVEN&&tf==ODD) ttf=ODD,nsum-=tt[i].sd;
        if (tt[i].ft%2==ODD&&tf==EVEN) ttf=ODD,nsum+=tt[i].sd;
        res=(res+F(pos+1,ttf,nsum,mask|(1<<(i-1))))%MOD;
    }
    return dp[pos][tf][sum][mask]=res;
}
void solve()
{

    cin>>n;
    for (int i=1;i<=n;i++)
         {
              cin>>a[i];
              tt[i]=tach(a[i]);
         }
    memset(dp,-1,sizeof(dp));
    cout<<F(0,0,0,0)<<"\n";
}

signed main()
{
    FastIO;
    freopen(Nothing".inp","r",stdin);
    freopen(Nothing".out","w",stdout);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
