#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front

int n,k,a[300010],i,x[300010],m,ans,t;

signed main()
{
// 	 freopen("input.000","r",stdin);
//	freopen("output.000","w",stdout);
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin>>n>>k;
	for (i=1;i<n+1;i++) cin>>a[i];
	m=0;x[0]=0;
	for (i=1;i<n+1;i++) if (a[i]%k==0)
	{
		m++;x[m]=i;
	}
	if (m<2)
	{
		ans=(n*(n+1))/2;
		cout<<ans;return 0;
	}
	ans=0;
	for (i=2;i<m+1;i++) ans=ans+((x[i]-x[i-2])*(x[i]-x[i-2]-1))/2-((x[i]-x[i-1])*(x[i]-x[i-1]-1))/2;
	t=n-x[m-1];ans=ans+(t*(t+1))/2;
	cout<<ans;
}

