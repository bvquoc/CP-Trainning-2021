#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;

template <typename T>
inline void Read(T& x) {
	bool Neg=false;
	char c;
	for (c=getchar();c<'0' || c>'9';c=getchar()) if (c=='-') Neg=!Neg;
	x=c-'0';
	for (c=getchar();c>='0' && c<='9';c=getchar()) x=x*10+c-'0';
	if (Neg) x=-x;
}
template <typename T>
inline void Write(T x) {
	if (x<0) { putchar('-'); x=-x; }
	T p=1;
	for (T temp=x/10;temp>0;temp/=10) p*=10;
	for (;p>0;x%=p,p/=10) putchar(x/p+'0');
}

#define int long long

const int N=400005, mod=1000003;
int n, m, a[N];
int f1[2003][2003], f[N];
int catalan[N], fact[N], re_fact[N];

inline int pw(int a, int b) {
	if (b==0) return 1;
	int cur=pw(a,b/2);
	if (b%2==0) return (cur*cur)%mod;
	return ((cur*cur)%mod*a)%mod;
}
inline int C(int n,int k) {
	if (k>n) return 0;
	return ((fact[n]*re_fact[k])%mod*re_fact[n-k])%mod;
}

void Solve_Catalan() {
	fact[0]=1;
	for (int i=1;i<=2*n;i++) fact[i]=(fact[i-1]*i)%mod;
	re_fact[2*n]=pw(fact[2*n],mod-2);
	for (int i=2*n;i>=1;i--) re_fact[i-1]=(re_fact[i]*i)%mod;
	catalan[0]=1;
	for (int i=1;i<=n;i++) {
		int cur=(fact[i]*re_fact[i+1])%mod;
		catalan[i]=(C(2*i,i)*cur)%mod;
	}
}
int dp1(int l, int r) { //Sub n<=200 O(n^3)
	if (l>r) return 1;
	if (f1[l][r]!=-1) return f1[l][r];
	int cur=0;
	for (int i=r-1;i>=l;i-=2)
		if (a[r]-a[i]<=m)
			cur=((dp1(l,i-1)*dp1(i+1,r-1))%mod+cur)%mod;
	f1[l][r]=cur;
	return cur;
}
int dp(int r) { //Sub n<=2000 O(n^2)
	if (r==0) return 1;
	if (f[r]!=-1) return f[r];
	int cur=0;
	for (int i=r-1;i>=1;i-=2)
	if (a[r]-a[i]<=m) {
		int tmp=((r-1)-(i+1)+1)/2;
		cur=((dp(i-1)*catalan[tmp])%mod + cur)%mod;
	}
	f[r]=cur;
	return cur;
}
// Sol: 
int32_t main(void) {
	FastIO;
	freopen("MINE.INP","r",stdin);
	freopen("MINE.OUT","w",stdout);
	Read(n); Read(m);
	for (int i=1;i<=2*n;i++) Read(a[i]);
	if (n<=200) { //Sub n<=200 O(n^3)
		n=2*n;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				f1[i][j]=-1;
		Write(dp1(1,n));
		return 0;
	}
	Solve_Catalan();
	if (n<=2000) { //Sub n<=2000 O(n^2)
		for (int i=1;i<=2*n;i++) f[i]=-1;
		Write(dp(2*n));
		return 0;
	}
	Write(catalan[n]); //sub m=1000000
	return 0;
}