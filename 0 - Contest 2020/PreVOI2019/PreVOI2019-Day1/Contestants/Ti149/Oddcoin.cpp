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
#define mn 100005
#define pi 3.1415926535897
#define inf 696969696969696
#define mod (ll)1000000009
#define base 31
#define FLN "oddcoin"
#define pii pair <int, int>
#define one first
#define two second
#define all(n) n.begin(),n.end()

int q,x,t;
vector <int> V;
int f[3000005];

int dp2(int n)
{
	if (n==0) return 0;
	if (f[n]!=inf) return f[n];
	for (int i=V.size()-1; i>=0; i--)
	{
		if (V[i]<=n) f[n]=min(f[n],dp2(n-V[i]) + 1);
	}
	return f[n];
}

void sub2(int x, int y)
{
	V.clear();
	V.push_back(1);
	V.push_back(10);
	V.push_back(100);
	V.push_back(1000);
	V.push_back(10000);
	V.push_back(3);
	V.push_back(30);
	V.push_back(300);
	V.push_back(3000);
	V.push_back(30000);	
	V.push_back(5);
	V.push_back(50);
	V.push_back(500);
	V.push_back(5000);
	V.push_back(50000);
	V.push_back(x);
	sort(all(V));
	for (int i=0; i<=y; i++) 
	{
		f[i]=inf;
//		cerr<<i<<endl;
	}
	cout<<dp2(y)<<"\n";
}

void input()
{
	cin>>q;
	return;
}

void ezclap()
{
	for (int ii=1; ii<=q; ii++)
	{
		cin>>x>>t;
		sub2(x,t);
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


