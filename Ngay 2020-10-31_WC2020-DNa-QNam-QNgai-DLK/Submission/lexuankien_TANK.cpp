#include<bits/stdc++.h>
using namespace std;
ifstream f;
ofstream g;
int m,n,a[1000000];
long long t[4000000];

void build(int k,int l,int r)
{
	if (l>r) return ;
	if (l==r) 
	{
		t[k]=a[l];
		return ;
	}
	int mid=(l+r)/2;
	build(2*k,l,mid);
	build(2*k+1,mid+1,r);
	t[k]=t[2*k]+t[2*k+1];
}
long long getsum(int k,int l,int r,int u,int v)
{
	if (v<l || u>r) return 0;
	if (u<=l && v>=r)
	{
		return t[k];
	}
	int mid=(l+r)/2;
	long long s1=getsum(2*k,l,mid,u,v);
	long long s2=getsum(2*k+1,mid+1,r,u,v);
	return (s1+s2); 
}
int check(int x)
{
	long long love=1e15;
	for (int i=1;i<=n-x+1;i++)
	{
		long long s=getsum(1,1,n,i,i+x-1);
		love=min(love,s);
	}
	if (love>=m) return 1;
	else return 0;
}
int main()
{
	f.open("tank.inp");
	g.open("tank.out");
	cin>>m>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	int d=1;
	int c=n;
	while (d+1<c)
	{
		int mid=(d+c)/2;
		if (check(mid)==1) c=mid;
		else d=mid;
	}
	if (check(d)==1) cout<<d;
	else cout<<c;
	f.close();
	g.close();
	return 0;
}
