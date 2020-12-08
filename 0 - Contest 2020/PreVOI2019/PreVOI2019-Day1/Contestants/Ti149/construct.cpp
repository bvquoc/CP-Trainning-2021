#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath> 
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
#include<iomanip>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define mn 1000005
#define pi 3.1415926535897
#define inf 6969696969696969696
#define mod (ll)1000000009
#define base 31
#define FLN "construct"
#define pii pair <int, int>
#define one first
#define two second
#define all(n) n.begin(),n.end()

int n,m;
int a[mn];
int pos[mn];
pii st[4*mn];
int d[4*mn];

void build(int id, int l, int r)
{
	d[id]=0;
	if (l==r)
	{
		st[id].one=a[l];
		st[id].two=l;
		return;
	}
	int mid=(l+r)/2;
	build(2*id,l,mid);
	build(2*id+1,mid+1,r);
	st[id]=min(st[2*id],st[2*id+1]);
}

void lazy(int id, int l, int r)
{
	st[id].one+=d[id];
	if (l!=r)
	{
		d[2*id]+=d[id];
		d[2*id+1]+=d[id];
	}
	d[id]=0;
}

void updt(int id, int l, int r, int u, int v, int k)
{
	lazy(id,l,r);
	if (r<u || v<l) return;
	if (u<=l && r<=v)
	{
		d[id]+=k;
		lazy(id,l,r);
		return;
	}
	int mid=(l+r)/2;
	updt(2*id,l,mid,u,v,k);
	updt(2*id+1,mid+1,r,u,v,k);
	st[id]=min(st[2*id],st[2*id+1]);
}

pii gett(int id, int l, int r, int u, int v)
{
	lazy(id,l,r);
	if (r<u || v<l) return {inf,inf};
	if (u<=l && r<=v)
	{
		return st[id];
	}	
	int mid=(l+r)/2;
	return min(gett(2*id,l,mid,u,v),gett(2*id+1,mid+1,r,u,v));
}

int cdt(int x, int y)
{
	deque <pair <pii,int> > st;
	st.push_back({{x,y},0});
	int cnt=0;
	while (!st.empty())
	{
		int l=st.back().one.one;
		int r=st.back().one.two;
		int tmp=st.back().two;
		st.pop_back();
		if (l>r) continue;
		pii dem=gett(1,1,n,l,r);
		if (l==r)
		{
//			cout<<l<<" "<<dem.one-tmp<<endl;
			cnt+=dem.one-tmp;
			continue;
		}
		cnt+=dem.one-tmp;
//		cout<<l<<" "<<r<<" "<<dem.one-tmp<<endl;
		st.push_back({{l,dem.two-1},dem.one});
		st.push_back({{dem.two+1,r},dem.one});
		
	}
	return cnt;
}

int brute(int l, int r)
{
	deque <int> st;
	st.clear();
	st.push_back(0);
	for (int i=l; i<=r; i++)
	{
		while (st.back()>a[i]) st.pop_back();
		pos[i]=st.back();
		st.push_back(a[i]);
	}
	st.clear();
	st.push_back(0);
	for (int i=r; i>=l; i--)
	{
		while (st.back()>=a[i]) st.pop_back();
		pos[i]=max(pos[i],st.back());
		st.push_back(a[i]);
	}
	int cnt=0;
	for (int i=l; i<=r; i++)
	{
		cnt+=a[i]-pos[i];
//		cout<<i<<" "<<pos[i]<<endl;
	}
	return cnt;
}

void input()
{
	cin>>n>>m;
	for (int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	return;
}

void ezclap()
{
	int cmd,x,y,z;
	for (int ii=1; ii<=m; ii++)
	{
		cin>>cmd;
		if (cmd==1)
		{
			cin>>x>>y>>z;
			for (int i=x; i<=y; i++) a[i]+=z;
		}
		else
		{
			cin>>x>>y;
			cout<<brute(x,y)<<"\n";
		}
	}
}

void output()
{
	return;
}

signed main()
{
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tt;
	cin>>tt;
	for (int i=1; i<=tt; i++)
	{
		input();
		ezclap();
		output();
	}
	return 0;
}


