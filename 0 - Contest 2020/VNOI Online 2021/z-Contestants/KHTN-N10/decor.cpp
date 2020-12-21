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
#define FILE_IN "decor.inp"
#define FILE_OUT "decor.out"
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
int onc[500001],inc[500001];
int rep[500001];
int arr[500001];
int cur;
char c;
int n,m,i,j,k,t,t1,u,v,a,b,l,r,mid;
vector<int> gt[500001];
void dfs(int x)
{
	rep[x]=i;
	onc[i]+=arr[x];
	for (int g : gt[x]) if (!rep[g]) dfs(g);
}
int check (int x)
{
//	cout<<"check "<<x<<endl;
	for (int i=1;i<=n;i++) inc[i]=0;
	cur=0;
	for (int i=1;i<=n;i++)
	{
//		cout<<"nowat "<<i<<endl;
		int u=rep[i];
		cur-=min(onc[u],inc[u]);
		inc[u]++;
		cur+=min(onc[u],inc[u]);
		if (i-x>=1)
		{
			u=rep[i-x];
		cur-=min(onc[u],inc[u]);
		inc[u]--;
		cur+=min(onc[u],inc[u]);
		}
//		cout<<"cur= "<<cur<<endl;
		if ((i>=x)and(cur+k>=x)) return i;
	}
	return 0;
}
int main()
{
	ofile;
	fio;
	cin>>n;
	cin>>m;
	cin>>k;
	for (i=1;i<=n;i++)
	{
		cin>>c;
		arr[i]=c-48;
	}
	for (i=1;i<=m;i++)
	{
		cin>>u>>v;
		gt[u].push_back(v);
		gt[v].push_back(u);
	}
	for (i=1;i<=n;i++)
	{
		if (!rep[i]) dfs(i);
	}
	l=0;
	r=n;
	while(l<r)
	{
		mid=(l+r)/2+1;
		if (check(mid)) l=mid;
		else r=mid-1;
	}
	if (l==0) cout<<-1;
	else
	{
		u=check(l);
		cout<<u-l+1<<' '<<u;
	}
}