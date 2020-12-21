//--------HUNGPOGBA---------
#include <bits/stdc++.h>
#define HUNGPOGBA "GIFF11"
#define memset(f,a) memset(f,(a),sizeof(f))
#define forr(i,a,b) for(int i=(a);i<=(b);++i)
#define ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();++it)
#define F first
#define S second
#define mp make_pair
#define ALL(a) (a).begin(),(a).end()
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)

using namespace std;

typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> ii ;

const int maxn=2000+5;
const ll maxc=1e9+7;

int t,n,a[maxn] ;
int f[maxn][maxn],g[maxn][maxn] ;
int numDigit[maxn],c[2][maxn] ;
#define SUM_MOD(x,y,mod) ((x)+(y)>=mod?(x)+(y)-mod:(x)+(y))
#define DIFF_MOD(x,y,mod) ((x)-(y)<0?(x)-(y)+mod:(x)-(y))
const int speNum=11 ;
const int mod= 998244353 ;

int dp[maxn][maxn][speNum+5] ;
int gt[maxn] ;

void solve()
{
    cin>>n ;
    int numOdd=0 ;
    forr(i,1,n)
    c[0][i]=c[1][i]=0 ;
    forr(i,1,n)
    {
        cin>>a[i] ;
        vector<int> digit ;
        int x=a[i] ;
        for(;x>0;x/=10) digit.push_back(x%10) ;
        numDigit[i]=(int)digit.size()  ;
        for(int j=0;j<digit.size();++j)
        {
            c[(j+1)&1][i]=SUM_MOD(c[(j+1)&1][i],digit[j],speNum) ;
        }
        if(numDigit[i]&1) ++numOdd ;
    }


    forr(i,0,n)
    forr(j,0,n)
    forr(k,0,speNum-1)
    dp[i][j][k]=0 ;

    dp[0][0][0]=1 ;
    forr(i,0,n)
    {
        forr(j,0,i)
        {
            forr(k,0,speNum-1)
            if(dp[i][j][k])
            {

               int x=SUM_MOD(k,DIFF_MOD(c[1][i+1],c[0][i+1],speNum),speNum) ;
               dp[i+1][j+1][x]=SUM_MOD(dp[i+1][j+1][x],dp[i][j][k],mod) ;
               int y=SUM_MOD(k,DIFF_MOD(c[0][i+1],c[1][i+1],speNum),speNum);
               dp[i+1][j][y]=SUM_MOD(dp[i+1][j][y],dp[i][j][k],mod) ;
            }
        }
    }





    forr(i,0,n)
    forr(j,0,numOdd)
    {
        g[i][j]=-maxc ;
        f[i][j]=maxc ;
    }

    g[0][0]=f[0][0]=0 ;


    forr(i,0,n)
    {
        forr(j,0,numOdd)
        {
            f[i+1][j]=min(f[i+1][j],f[i][j]+ ((j+1)&1) );
            f[i+1][j+1]=min(f[i+1][j+1],f[i][j]+((j+1)&1)) ;

            g[i+1][j]=max(g[i+1][j],g[i][j]+ ((j+1)&1) ) ;
            g[i+1][j+1]=max(g[i+1][j+1],g[i][j]+((j+1)&1)) ;
        }
    }

    int ans=0 ;
    forr(i,0,n)
    if(g[n][numOdd]>=i && f[n][numOdd]<=i && dp[n][i][0]>0)
       {
           if(i-(numOdd+1)/2<0 || n-i-numOdd/2<0) continue ;
           int tmp=1LL*gt[i-(numOdd+1)/2]*gt[n-i-numOdd/2]%mod ;
           tmp=1LL*tmp*gt[numOdd/2]%mod*dp[n][i][0]%mod*gt[(numOdd+1)/2]%mod ;
           ans=SUM_MOD(ans,tmp,mod) ;
       }
    cout<<ans <<"\n" ;


}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(HUNGPOGBA".inp", "r", stdin);
    freopen(HUNGPOGBA".out", "w", stdout);
    cin>>t ;
    gt[0]=1 ;
    forr(i,1,2000)
    gt[i]=1LL*gt[i-1]*i%mod ;
    while(t--)
        solve() ;
    return 0;
}
//-----------CODE MY DREAM------------
