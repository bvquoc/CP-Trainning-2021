/*
	Normie's Template v2.0
*/

// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;

// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>

// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;

//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//File I/O.
#define FILE_IN "coolmac.inp"
#define FILE_OUT "coolmac.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)

//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"

//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))

//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320

//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>

//Quick power of 2.
#define pow2(x) (ll(1)<<x)

//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)

//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;
//---------END-------//
int n,m,i,j,k,t,u,v,a,b,t1,tar;
vector<pii(int)> gt[100011];
int dis[100011];
vector<int> lay[100011];
int main()
{
	ofile;
	fio;
	for (i=0;i<=100000;i++) gt[i].push_back({i+1,0});
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>u>>v;
		gt[v+1].push_back({u,1});
	}
	tar=100000;
	cin>>m;
	for (i=1;i<=m;i++)
	{
		cin>>u;
		tar=min(tar,u);
	}
	for (i=0;i<=100001;i++) dis[i]=1e9;
	dis[100001]=0;
	lay[0].push_back(100001);
	for (t=0;t<=100005;t++)
	{
		for (i=0;i<lay[t].size();i++)
		{
			u=lay[t][i];
			for (pii(int) g : gt[u]) if ((dis[g.fi]==1e9)and(g.se==0)) 
			{
				dis[g.fi]=t;
				lay[t].push_back(g.fi);
			}
		}
		for (i=0;i<lay[t].size();i++)
		{
			u=lay[t][i];
			for (pii(int) g : gt[u]) if ((dis[g.fi]==1e9)and(g.se==1)) 
			{
				dis[g.fi]=t+1;
				lay[t+1].push_back(g.fi);
			}
		}
	}
	if (dis[tar]==1e9) cout<<-1; else cout<<dis[tar];
}