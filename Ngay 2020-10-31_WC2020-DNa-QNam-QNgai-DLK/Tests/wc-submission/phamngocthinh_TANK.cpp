#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
typedef long long ll;
int n;
ll M;
const int N=100005;
ll a[N],S[N];
void read()
{
	S[0]=0;
	cin>>M>>n;
	FOR(i,1,n) cin>>a[i];
	FOR(i,1,n) S[i]=S[i-1]+a[i];
}
bool check(int k)
{
	FOR(i,k,n)
		if((S[i]-S[i-k])<M) return false;
	return true;
}
void solve()
{
	int l=1,r=n,ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid; 
			r=mid-1;
		}
		else l=mid+1;
	}
	cout<<ans;
}
int main()
{
//	freopen("TANK.inp","r",stdin);
	read();
	solve();
	return 0;
}
