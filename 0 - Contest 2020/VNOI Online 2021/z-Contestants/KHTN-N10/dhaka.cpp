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
#define FILE_IN "dhaka.inp"
#define FILE_OUT "dhaka.out"
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
ll n,m,i,j,k,t,t1,u,v,a,b,res=1e18;
struct cmp
{
	int operator()(const pair<ll,pair<int,int>> &a, const pair<ll,pair<int,int>> &b) const
	{
		return (a.fi>b.fi);
	}
};
priority_queue<pair<ll,pair<int,int>>,vector<pair<ll,pair<int,int>>>,cmp> pq;
bool used[100001][32];
ll dis[100001][32];
ll avail[100001];
vector<pair<ll,pair<int,int>>> gt[100001][32];
int main()
{
	ofile;
	fio;
	cin>>n>>m>>k>>t;
	for (i=1;i<=n;i++)
	{
		cin>>u;
		for (j=1;j<=u;j++)
		{
			cin>>v;
			avail[i]|=(1<<(v-1));
		}
	}
	for (i=1;i<=m;i++)
	{
		cin>>u>>v>>a;
//		cout<<u<<' '<<v<<' '<<a<<endl;
		for (j=0;j<(1<<k);j++)
		{
			gt[u][j].push_back({a,{v,j|(avail[v])}});
			gt[v][j].push_back({a,{u,j|(avail[u])}});
		}
	}
	for (i=1;i<=n;i++) for (j=0;j<(1<<k);j++) dis[i][j]=1e18;
	dis[1][avail[1]]=0;
	pq.push({0,{1,avail[1]}});
	while(pq.size())
	{
		auto pp=pq.top(); pq.pop();
//		cout<<"visit "<<pp.se.fi<<' '<<pp.se.se<<endl;
		if (!used[pp.se.fi][pp.se.se])
		{
			used[pp.se.fi][pp.se.se]=1;
		for (auto g : gt[pp.se.fi][pp.se.se])
		{
			if (dis[pp.se.fi][pp.se.se]+g.fi<dis[g.se.fi][g.se.se])
			{
				dis[g.se.fi][g.se.se]=dis[pp.se.fi][pp.se.se]+g.fi;
				pq.push({dis[pp.se.fi][pp.se.se]+g.fi,{g.se.fi,g.se.se}});
			}
		}
		}
	}
	for (i=1;i<=n;i++) for (j=0;j<(1<<k);j++)
	{
//		cout<<"dis "<<i<<' '<<j<<" = "<<dis[i][j]<<endl;
	}
	for (j=0;j<(1<<k);j++) if (__builtin_popcount(j)>=t) res=min(res,dis[n][j]);
	if (res==1e18) cout<<-1; else cout<<res;
}