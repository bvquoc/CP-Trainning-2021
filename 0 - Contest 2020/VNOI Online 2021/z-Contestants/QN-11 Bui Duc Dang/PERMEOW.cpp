#include<bits/stdc++.h>
using namespace std;
const int M=2e5+2;
int n,a[M],b[M];
const long long mod=1e9+7;
long long sum[M],fa[M];
int main()
{
	freopen("PERMEOW.INP","r",stdin);
	freopen("PERMEOW.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	bool flag=true;
	for(int i=1;i<=n;++i)
	{
		cin>>b[i];
		if(a[i]!=b[i]) flag=false;
	}
	if(flag)
	{
		int res=0;
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				if(a[i]>a[j]) ++res;
		cout<<res;
	}
	else
	{
		for(int i=1;i<=n;++i)
			if(a[i]!=i&&b[i]!=n-i+1) flag=true;
		if(flag) cout<<0;
		else
		{
			fa[0]=1;
			for(int i=1;i<=n;++i) fa[i]=fa[i-1]*i%mod;
			for(int i=1;i<=n;++i)
				for(int j=1;j<=i;++j)
					sum[i]=(sum[i]+sum[i-1]+fa[i-1]*(i-j))%mod;
			cout<<sum[n];
		}
	}
	return 0;
}
