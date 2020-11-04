#include <bits/stdc++.h>
#define fi "TANK.INP"
#define fo "TANK.OUT"
#define For(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
const int N=1e6;
int n,m;
long long a[N],s[N];

bool kt(int len)
{
	For(i,1,n-len+1)
		if(s[i+len-1] - s[i-1] < m) return false;
	return true;
}

void solve()
{
	For(i,1,n) s[i]=s[i-1]+a[i];
	
	int d=1; int c=n;
	while(d+1<c)
	{
		int g=(d+c)/2;
		if(kt(g)) c=g; else d=g;
	}
	if(kt(d)) cout<<d;
	else cout<<c;
}
int main()
{
//	freopen(fi,"r",stdin);
//	freopen(fo,"w",stdout);
	ios_base :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>m>>n;
	For(i,1,n) cin>>a[i];
	solve();
}
