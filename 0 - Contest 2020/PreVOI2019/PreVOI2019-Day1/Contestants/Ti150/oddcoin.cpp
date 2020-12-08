#include <bits/stdc++.h>
#define int long long

using namespace std;

int q, x, t;
int cur[]={1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};
int hic[]={0, 1, 2, 1, 2, 1, 2, 3, 2, 3};

int get(int g)
{
	int ok=g/100000;
	int ax=g%100000;
	ok*=2;
	while(ax)
	{
		ok+=hic[ax%10];
		ax/=10;
	}
	return ok;
}

signed main()
{
	freopen("oddcoin.inp", "r", stdin);
	freopen("oddcoin.out", "w", stdout);
	cin>>q;
	for(int i=1; i<=q; i++)
	{
		int x, t, ans=100000000;
		cin>>x>>t;
		int mmax=t/x;
		for(int naisu=mmax; naisu>=max(0ll, mmax-50000); naisu--)
		{
			ans=min(ans, get(t-x*naisu)+naisu);
		}
		cout<<ans<<'\n';
	}
}