//Rochy'.'
#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define fl(i,a,b) for(int i=a;i<b;++i)
#define fa(i,a) for(auto (i):(a))
#define F first
#define S second
#define all(a) a.begin(),a.end()
#define vi vector <int>
#define ii pair <int,int>
#define pb push_back
using namespace std;
template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));
if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar()))x=x*10+c-48;if(nega)x=-x;}
template <typename T> inline void writep(T x){if(x>9)writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}
template <typename R, typename D> inline void Min(R &a, D b){if(a>b) a=b;}
template <typename D, typename R> inline void Max(D &a, R b){if(a<b) a=b;}
const int N=2003,NN=200005,mod=1000003;
int n,m,a[NN+NN],dp[N+N][N+N][2];
int power(int a,int b){
	int c=1;for(;b;b>>=1,a=1ll*a*a%mod)if(b&1)c=1ll*c*a%mod;
	return c;
}
void special(){
	int gtn=1;
	fo(i,1,n) gtn=1ll*gtn*i%mod;
	int gtn1=1ll*gtn*(n+1)%mod;
	int gtnn=gtn1;
	fo(i,n+2,n+n) gtnn=1ll*gtnn*i%mod;
	cout<<1ll*(1ll*gtnn*power(gtn,mod-2))*power(gtn1,mod-2)%mod;
	exit(0);
}
void remain(int &a){
	if(a>=mod) a-=mod;
}
int main(){
	ios_base::sync_with_stdio(NULL);
	cin. tie(NULL); cout. tie(NULL);
	freopen("Mine.inp" , "r", stdin);
	freopen("Mine.out", "w", stdout);
	cin>>n>>m;
	fo(i,1,n+n)cin>>a[i];
	if(a[1]+m>=a[n+n]){
		special();
	}
	return 0;
}