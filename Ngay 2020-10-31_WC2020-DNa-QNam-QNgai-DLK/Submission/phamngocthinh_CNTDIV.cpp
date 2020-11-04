#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(ll n)
{
	ll res=0;
	ll m=n*(n+1)*(n+2);
	ll so=sqrt(m);
	for(int i=1;i<=sqrt(so);i++)
		if(so%i==0) res++;
	ll gg=sqrt(so);
	if(gg*gg==so) res=res*2 - 1;
	else res=res*2;
	if(so*so==m) res=res*2 - 1;
	else res=res*2;
	res=res*2 - 1;
	cout<<res<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("CNTDIV.inp","r",stdin);
	int q;
	ll n;
	cin>>q;
	{
		cin>>n;
		solve(n);
	}
	return 0;
}
