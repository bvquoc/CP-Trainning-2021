#include <bits/stdc++.h>
#define fi "FACILITY.INP"
#define fo "FACILITY.OUT"
#define For(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
const int N=1e6+11;
struct tt{long long s,t,gt;};
int n,k;
tt a[N];
long long L[N]; //gt max thu dc khi xet toi ng i

bool dk( tt x, tt y)
{
	if(x.t==y.t && x.s==y.s) return(x.gt>y.gt);
	if(x.t==y.t) return(x.s<y.s);
	return(x.t<y.t);
}
int tknp(int d, int c, int x)
{
	while(d+1<c)
	{
		int g=(d+c)/2;
		if(a[g].t > x) c=g; else d=g;
	}
	if(a[c].t <= x) return c;
	if(a[d].t <= x) return d;
}
void solve()
{
	sort(a+1,a+n+1,dk);
	//For(i,1,n) cout<<a[i].s<<" "<<a[i].t<<" "<<a[i].gt<<"\n";
	L[1]=a[1].gt;
	For(i,2,n)
	{
		int j=tknp(0,i-1,a[i].s);
		L[i]=max(L[i-1],L[j]+a[i].gt);
	}
	cout<<L[n];
}

int main()
{
//	freopen(fi,"r",stdin);
//	freopen(fo,"w",stdout);
	ios_base :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>k;
	For(i,1,n) cin>>a[i].s>>a[i].t>>a[i].gt;
	For(i,1,n) a[i].t=a[i].s+a[i].t+k;
	solve();
}
