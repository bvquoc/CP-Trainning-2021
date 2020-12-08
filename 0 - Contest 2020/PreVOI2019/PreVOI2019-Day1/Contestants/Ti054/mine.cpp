#include<bits/stdc++.h>
using namespace std;
#define y1 A2Dalek
#define y0 Cyberman
#define yn RoseTyler
#define j1 JackHarkness
#define fs first
#define sd second
const int N=4e5;
const long long oo=1e6+3;
int du[]={-1,0,0,1};
int dv[]={0,-1,1,0};
const long long mod=1e6+3;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
long long sqr(long long x) {return x*x;}
int getbit(int state, int i) {return ((state>>i)&1);}

int n,m,a[N+5];
long long res,f[N+5],dp[N+5];
int main()
{
	freopen("mine.inp","r",stdin);
	freopen("mine.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin>>n>>m; n*=2;
    for (int i=1;i<=n;i++) cin>>a[i];
    f[0]=1;
    for (int i=2;i<=n;i+=2) for (int j=2;j<=i;j+=2) f[i]=(f[i]+f[j-2]*f[i-j]%mod)%mod;
    dp[0]=1;
    for (int i=2;i<=n;i+=2) for (int j=i-1;j>=1;j-=2) if (a[i]-a[j]<=m) dp[i]=(dp[i]+f[i-j-1]*dp[j-1]%mod)%mod;
    cout<<dp[n];
	return 0;
}
