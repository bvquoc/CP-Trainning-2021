#include <bits/stdc++.h>
#define fi "CNTDIV.INP"
#define fo "CNTDIV.OUT"
#define For(i,a,b) for(int i=a; i<=b; i++)
#define ll long long
using namespace std;
ll n,q;

void solve()
{
	ll res=0;
	ll t=n*(n+1)*(n+2);
	ll tt=t*t;
	
	For(i,1,sqrt(tt))
		if(tt%i==0)
		{
			if((t%i)!=0 && i<t) res++;
			int x=tt/i;
			if(x!=i && (t%x)!=0 && x<t) res++;
		}
	cout<<res;
}

int main()
{
//	freopen(fi,"r",stdin);
//	freopen(fo,"w",stdout);
	ios_base :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>q;
	For(test,1,q)
	{
		cin>>n;
		solve();
	}
}
