#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,k;
struct dt{
	int l,r,c;
	int id;
	dt(int ll = 0, int rr = 0, int iid = 0)
	{
		id=iid;
		l=ll;
		r=rr;
	}
}X[N];
int L[N];
bool cmp(dt a, dt b)
{
	return ((a.r<b.r)||(a.r==b.r&&a.l<b.l));
}
void doc()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int s,d,r;
		cin>>s>>d>>r;
		d+=s+k;
		X[i].l=s;
		X[i].r=d;
		X[i].c=r;
	}
	sort(X+1,X+1+n,cmp);
//	for(int i=1;i<=n;i++)cout<<X[i].c<<"\t";
}
void xuly()
{
	for(int i=1;i<=n;i++)L[i]=X[i].c;
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=1;j--)if(X[i].l>=X[j].r)L[i]=max(L[i],L[j]+X[i].c);
	}
	int kq=-1;
	for(int i=1;i<=n;i++)kq=max(kq,L[i]);
	cout<<kq;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen("FACILITY.INP","r",stdin);
//	freopen("FACILITY.OUT","w",stdout);
	doc();
	xuly();
	return 0;
}
