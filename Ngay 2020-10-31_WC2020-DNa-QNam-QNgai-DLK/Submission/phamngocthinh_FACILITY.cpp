#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
const int N=1e6+5;
typedef long long ll;
ll F[N];
int n,k;
struct fa
{
	int s,e;
	ll t;
}a[N];
void read()
{
	cin>>n>>k;
	FOR(i,1,n)
	{
		cin>>a[i].s>>a[i].e>>a[i].t;
		a[i].e=a[i].s+a[i].e;
	}
}
bool cmp(fa aa,fa bb)
{
	return aa.e<bb.e || (aa.e==bb.e && aa.s<bb.s);
}
int SB(int l,int r,int x)
{
	int ans=0;
	while(l<=r)
	{
		int g=(l+r)/2;
		if(a[g].e<=x)
		{
			ans=g; l=g+1;
		}
		else r=g-1;
	}
	return ans;
}
void solve()
{
	sort(a+1,a+n+1,cmp);
	F[0]=0;
	for(int i=1;i<=n;i++)
	{
		int z=SB(1,i-1,a[i].s-k);
		F[i]=max(F[i-1],a[i].t+F[z]);
	//	cout<<i<<" "<<F[i]<<endl;
	}
	cout<<F[n];
}
int main()
{
//	freopen("FA.inp","r",stdin);
	read();
	solve();
	return 0;
}
