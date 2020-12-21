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
#define FILE_IN "socks.inp"
#define FILE_OUT "socks.out"
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
vector<int> gt[500001];
int used[500001];
int cnt[5];
int sz[500001];
int cnt1[500001];
int mk[500001];
int cnt2,cnt3;
int n,m,i,j,k,t,t1,u,v,a,b;
void solve1()
{
	cnt[0]=0;
	for (i=1;i<=n;i++) cnt[0]+=mk[i];
	
		if (cnt[0]<=1) cout<<0<<endl;
		else cout<<1<<endl;
	for (i=1;i<=m;i++)
	{
		cin>>u;
		if (mk[u]==0)
		{
			mk[u]=1;
			cnt[0]++;
		}
		else
		{
			mk[u]=0;
			cnt[0]--;
		}
		if (cnt[0]<=1) cout<<0<<endl;
		else cout<<1<<endl;
	}
}
void dfsSub2(int x)
{
	used[x]=t;
	for (int g : gt[x]) if (!used[g]) dfsSub2(g);
}
void solve2()
{
	cnt[1]=0;
	cnt[2]=0;
	cnt[3]=0;
	cnt[4]=0;
	for (i=1;i<=n;i++) if (gt[i].size()==3)
	{
		used[i]=4;
		t=4;
		for (int g : gt[i])
		{
			t--;
			dfsSub2(g);
		}
		break;
	}
	for (i=1;i<=n;i++) cnt[used[i]]+=mk[i];
	
		if (cnt[1]+cnt[2]+cnt[3]+cnt[4]<=1) cout<<0<<endl;
		else if ((cnt[1])and(cnt[2])and(cnt[3])) cout<<2<<endl;
		else cout<<1<<endl;
		
	for (i=1;i<=m;i++)
	{
		cin>>u;
		if (mk[u]==0)
		{
			mk[u]=1;
			cnt[used[u]]++;
		}
		else
		{
			mk[u]=0;
			cnt[used[u]]--;
		}
		if (cnt[1]+cnt[2]+cnt[3]+cnt[4]<=1) cout<<0<<endl;
		else if ((cnt[1])and(cnt[2])and(cnt[3])) cout<<2<<endl;
		else cout<<1<<endl;
	}
}
void dfsSub3(int x)
{
	used[x]=1;
	sz[x]=mk[x];
	for (int g : gt[x]) if (!used[g])
	{
		dfsSub3(g);
		sz[x]+=sz[g];
		if (sz[g]) cnt1[x]++;
	}
	if (sz[1]-sz[x]) cnt1[x]++;
}
int solve_n2()
{
	for (int i=1;i<=n;i++) 
	{
		used[i]=0;
		cnt1[i]=0;
		sz[i]=0;
	}
	dfsSub3(1);
	int u=0;
	for (int i=1;i<=n;i++) if ((cnt1[i]<=1)and(mk[i])) u++;
//	cout<<"sz: ";
//	for (int i=1;i<=n;i++) cout<<sz[i]<<' ';
//	cout<<"u= "<<u<<' ';
	return (u+1)/2;
}
void solve3()
{
	for (i=1;i<=n;i++) cnt[0]+=mk[i];
	
		if (cnt[0]<=1) cout<<0<<endl;
		else
		cout<<solve_n2()<<endl;
		
	for (i=1;i<=m;i++)
	{
		cin>>u;
		if (mk[u]==0)
		{
			mk[u]=1;
			cnt[0]++;
		}
		else
		{
			mk[u]=0;
			cnt[0]--;
		}
		if (cnt[0]<=1) cout<<0<<endl;
		else
		cout<<solve_n2()<<endl;
	}
}
int main()
{
	ofile;
	fio;
	cin>>n>>m;
	for (i=1;i<=n;i++) cin>>mk[i];
	for (i=1;i<n;i++)
	{
		cin>>u>>v;
		gt[u].push_back(v);
		gt[v].push_back(u);
	}
	for (i=1;i<=n;i++) if (gt[i].size()<=2) cnt2++; else if (gt[i].size()==3) cnt3++;
	if (cnt2==n) solve1();
	else if ((cnt2==n-1)and(cnt3==1)) solve2();
	else if (n*m<=1000000) solve3();
}