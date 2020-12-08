#include <bits/stdc++.h>
#define int long long
using namespace std;

int gt[400005];
int dp[4005];
int cat[2005];
int t[4005];
int mod=1000003;
int n, m;

int binpow(int a, int b)
{
	int ans=1, cac=a;
	while(b)
	{
		if(b&1)
		{
			ans=(ans*cac)%mod;
		}
		b/=2;
		cac=(cac*cac)%mod;
	}
	return ans;
}

int C(int a, int b)
{
	return (gt[b]*binpow((gt[a]*gt[b-a])%mod, mod-2))%mod;
}

int bigcatalan(int a)
{
	return (C(a, 2*a)*binpow(a+1, mod-2))%mod;
}

void makecatalan()
{
	for(int i=0; i<=2000; i++)
	{
		cat[i]=bigcatalan(i);
	}
}

void sub1()
{
	makecatalan();
	for(int i=1; i<=2*n; i++)
	{
		cin>>t[i];
	}
	dp[2*n+1]=1;
	for(int i=2*n-1; i>=1; i-=2)
	{
		for(int j=i+1; j<=2*n; j+=2)
		{
			if(t[j]-t[i]<=m)
			{
				dp[i]+=dp[j+1]*cat[(j-1-i)/2];
			}
		}
		dp[i]%=mod;
	}
	cout<<dp[1];
}

signed main()
{
	freopen("mine.inp", "r", stdin);
	freopen("mine.out", "w", stdout);
	cin>>n>>m;
	gt[0]=1;
	for(int i=1; i<=400002; i++)
	{
		gt[i]=(gt[i-1]*i)%mod;
	}
	// cout<<C(5, 10);
	if(n>2000)
	{
		for(int i=1; i<=n; i++)
		{
			cin>>m;
		}
		cout<<bigcatalan(n);
	}
	else
	{
		sub1();
	}
}