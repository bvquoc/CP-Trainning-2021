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
#define mn 400005
#define pi 3.1415926535897
#define inf 6969696969696969696
#define mod (ll)1000003
#define base 31
#define FLN "mine"
#define pii pair <int, int>
#define one first
#define two second
#define all(n) n.begin(),n.end()

int n,m;
int a[mn];
int f[205][205][205];

int dp(int u, int v, int p)
{
	if (u>2*n) return (v==0);
	if (a[u]-a[p]>m) return 0;
	if (f[u][v][p]!=-1) return f[u][v][p];
	f[u][v][p]=0;
	int t=p;
	if (v>0) 
	{
		f[u][v][p]+=dp(u+1,v-1,t);
		f[u][v][p]%=mod;
	}
	else t=u+1;
	f[u][v][p]+=dp(u+1,v+1,t);
	f[u][v][p]%=mod;
	return f[u][v][p];
}

void input()
{
	cin>>n>>m;
	for (int i=1; i<=2*n; i++) cin>>a[i];
	return;
}

void ezclap()
{
	if (a[2*n]-a[1]<=m && n>200)
	{
		cout<<n*(n-1)/2 + 1;
		return;
	}
	for (int i=0; i<=2*n; i++)
	{
		for (int j=0; j<=2*n; j++)
		{
			for (int k=0; k<=2*n; k++)
			{
				f[i][j][k]=-1;
			}
		}
	}
	cout<<dp(1,0,1);
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
// 	int tt;
//	cin>>tt;
//	for (int i=1; i<=tt; i++)
	{
		input();
		ezclap();
		output();
	}
	return 0;
}


