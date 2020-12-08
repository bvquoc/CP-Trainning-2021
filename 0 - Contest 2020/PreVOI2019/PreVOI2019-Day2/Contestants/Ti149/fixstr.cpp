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
#include<cstring>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define maxn 1000005
#define maxm 100005
#define pi 3.1415926535897
#define inf 6969696969696969696
#define mod (ll)1000000009
#define base 31
#define FLN "fixstr"
#define pii pair <int, int>
#define one first
#define two second
#define all(n) n.begin(),n.end()

string s;
int n,m;
int res[maxn];
vector <pair <int,pii> > V;
char cmd;
int ct1,ct2;

class seg
{
	public:
	int st[4*maxn];
	int d[4*maxn];
	void reset(int id, int l, int r)
	{
		d[id]=0;
		if (l==r)
		{
			st[id]=res[l];
			return;
		}
		int mid=(l+r)/2;
		reset(2*id,l,mid);
		reset(2*id+1,mid+1,r);
		st[id]=min(st[2*id],st[2*id+1]);
	}
	void lazy(int id, int l, int r)
	{
		st[id]+=d[id];
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
	int gett(int id, int l, int r, int u, int v)
	{
		lazy(id,l,r);
		if (r<u || v<l) return inf;
		if (u<=l && r<=v) return st[id];
		int mid=(l+r)/2;
		return min(gett(2*id,l,mid,u,v),gett(2*id+1,mid+1,r,u,v));
	}
} it;

void input()
{
	cin>>s;
	cin>>m; n=s.size();
	return;
}

void sub2()
{
	int dem=0;
	for (int i=0; i<s.size(); i++)
	{
		if (s[i]=='(') dem++;
		else dem--;
		res[i+1]=dem;
	}
	it.reset(1,1,n);
	for (int ii=1; ii<=m; ii++)
	{
		cin>>cmd;
		if (cmd=='C')
		{
			cin>>ct1;
			if (s[ct1-1]=='(') 
			{
				it.updt(1,1,n,ct1,n,-2);
				s[ct1-1]=')';
			}
			else 
			{
				it.updt(1,1,n,ct1,n,2);
				s[ct1-1]='(';
			}
		}
		else
		{
			cin>>ct1>>ct2;
			int l=0,r,sum;
			if (ct1>1) l=it.gett(1,1,n,ct1-1,ct1-1);
			r=it.gett(1,1,n,ct2,ct2);
			sum=it.gett(1,1,n,ct1,ct2);
			r-=l; sum-=l;
//			cout<<r<<" "<<sum<<" ";
			sum=min(0ll,sum);
			r-=sum;
			r=abs(r);
			cout<<r-sum<<"\n";
		}
	}
}

void sub1()
{
	for (int i=0; i<s.size(); i++)
	{
		if (s[i]=='(') res[i]=1;
		else res[i]=-1;
	}
	for (int ii=1; ii<=m; ii++)
	{
		cin>>cmd;
		if (cmd=='C') 
		{
			cin>>ct1; ct1--;
			V.push_back({ii,{1,ct1}});
			res[ct1]=0-res[ct1];
		}
		else if (cmd=='U')
		{
			cin>>ct1;
			for (int i=0; i<s.size(); i++)
			{
				if (s[i]=='(') res[i]=1;
				else res[i]=-1;
			}
			if (!V.empty())
			{
				for (int i=V.size()-1; i>=0; i--)
				{
					if (V[i].one>=ct1) continue;
					if (V[i].two.one==1)
					{
						res[V[i].two.two]=0-res[V[i].two.two];
					}
					else ct1=min(ct1,V[i].two.two);
				}
			}
			V.push_back({ii,{2,ct1}});
		}
		else 
		{
			cin>>ct1>>ct2; ct1--; ct2--;
			int cnt=0,dem=0;
			for (int i=ct1; i<=ct2; i++)
			{
				dem+=res[i];
				if (dem<0) 
				{
					dem++;
					cnt++;
				}
			}
			cout<<cnt+dem<<"\n";
		}
//	for (int i=0; i<s.size(); i++) 
//	if (res[i]==1) cout<<"("; else cout<<")"; 
//	cout<<endl;
	}
}

void ezclap()
{
	if (n<=1000 && m<=1000)
	{
		sub1();
		return;
	}
	sub2();
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
//	int tt;
//	cin>>tt;
//	for (int i=1; i<=tt; i++)
	{
		input();
		ezclap();
		output();
	}
	return 0;
}



