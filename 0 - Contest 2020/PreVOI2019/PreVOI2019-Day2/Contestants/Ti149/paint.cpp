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
#define ld long double
#define maxn 1000005
#define maxm 100005
#define pi 3.1415926535897
#define inf 6969696969696969696
#define mod (ll)1000000009
#define base 31
#define FLN "paint"
#define pii pair <int, int>
#define one first
#define two second
#define all(n) n.begin(),n.end()

int n;
int rt[maxn],par[maxn];
int vs[50];
int clr[maxn],cnt=0;
int cmd,l,r;
char x,y;
int node=-1;

int root(int u)
{
	deque <int> st;
	st.push_back(u);
	int top=u;
	while (top!=rt[top])
	{
		st.push_back(rt[top]);
		top=rt[top];
	}
	while (!st.empty())
	{
		rt[st.back()]=top;
		st.pop_back();
	}
	return top;
}

void input()
{
	cin>>n;
	return;
}

void ezclap()
{
	for (int i=1; i<=n; i++)
	{
		cin>>cmd;
		if (cmd==1)
		{
			cin>>x;
			l=x-96;
//			cout<<x<<" "<<l<<endl;
			if (!vs[l]) 
			{
				vs[l]=++cnt;
				clr[vs[l]]=l;
				rt[vs[l]]=vs[l];
			}
			par[++node]=vs[l];
		}
		else
		{
			cin>>x>>y;
			l=x-96; r=y-96;
			if (!vs[l]) continue;
			if (!vs[r]) 
			{
				vs[r]=++cnt;
				clr[cnt]=r;
				rt[cnt]=cnt;
			}
			rt[vs[l]]=rt[vs[r]];
			vs[l]=0;
		}
	}
}

void output()
{
//	cout<<node<<endl;
	for (int i=0; i<=node; i++)
	{
//		cout<<i<<endl;
		int tmp=root(par[i]);
		cout<<(char)(clr[tmp] +96);
	}
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



