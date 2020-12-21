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
#define FILE_IN "gift11.inp"
#define FILE_OUT "gift11.out"
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
ll bow (ll a, ll x, ll p)
{
	if (!x) return 1;
	ll res=bow(a,x/2,p);
	res*=res;
	res%=p;
	if (x%2) res*=a;
	res%=p;
	return res;
}
ll arr[100001];
ll val[100001];
ll len[100001];
int dpo[2001][2001][11];
int dpe[2001][2001][11];
ll cnto,cnte;
ll n,m,i,j,k,t,t1,u,v,a,b,res,smod,gr1,gr2;
ll fac[4001],inv[4001];
int main()
{
	ofile;
	fio;
	fac[0]=1;
	inv[0]=1;
	for (i=1;i<=4000;i++)
	{
		fac[i]=fac[i-1]*i;
		fac[i]%=MOD;
		inv[i]=bow(fac[i],MOD-2,MOD);
	}
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		cnto=0; cnte=0;
		cin>>n;
		for (i=0;i<n;i++)
		{
			cin>>arr[i];
			val[i]=0;
			len[i]=0;
			for (j=0;j<10;j++)
			{
				u=(arr[i]/(ll)(pow(10,j)))%10;
				if (j%2==0) val[i]+=u; else val[i]+=11-u;
				val[i]%=11;
				if (u) len[i]=j+1;
			}
			if (len[i]%2) cnto++;
			else cnte++;
	//		cout<<arr[i]<<' '<<val[i]<<' '<<len[i]<<endl;
		}
	//	cout<<cnto<<' '<<cnte<<endl;
		for (j=0;j<=cnte;j++) for (k=0;k<11;k++)
		{
			dpe[0][j][k]=0;
		}
		dpe[0][0][0]=1;
		for (i=1;i<=n;i++) for (j=0;j<=cnte;j++) for (k=0;k<11;k++)
		{
			dpe[i][j][k]=dpe[i-1][j][k];
			if ((len[i-1]%2==0)and(j))
			{
				dpe[i][j][k]+=dpe[i-1][j-1][(k+11-val[i-1])%11];
				dpe[i][j][k]%=MOD;
			}
	//		if (i==n) cout<<"dpe "<<j<<' '<<k<<" : "<<dpe[i][j][k]<<endl;
		}
		for (j=0;j<=cnto;j++) for (k=0;k<11;k++)
		{
			dpo[0][j][k]=0;
		}
		dpo[0][0][0]=1;
		for (i=1;i<=n;i++) for (j=0;j<=cnto;j++) for (k=0;k<11;k++)
		{
			dpo[i][j][k]=dpo[i-1][j][k];
			if ((len[i-1]%2==1)and(j))
			{
				dpo[i][j][k]+=dpo[i-1][j-1][(k+11-val[i-1])%11];
				dpo[i][j][k]%=MOD;
			}
	//		if (i==n) cout<<"dpo "<<j<<' '<<k<<" : "<<dpo[i][j][k]<<endl;
		}
		smod=0;
		for (i=0;i<n;i++)
		{
			smod+=val[i];
			smod%=11;
		}
		res=0;
		gr1=cnto-cnto/2;
		gr2=cnto/2;
		if (cnto==0)
		{
			if (smod==0) res=fac[n];
			else res=0;
		}
		else
		{
		for (int modo=0;modo<11;modo++) for (int mode=0;mode<11;mode++) if (((modo+mode)*2+11-smod)%11==0)
		{
	//		cout<<"satisfy: "<<modo<<' '<<mode<<endl;
			for (i=0;i<=cnte;i++)
			{
	//			cout<<"n= "<<n<<endl;
	//			cout<<"gr1= "<<gr1<<endl;
	//			cout<<"gr2= "<<gr2<<endl;
	//			cout<<"cnto= "<<cnto<<endl;
	//			cout<<"i= "<<i<<endl;
	//			cout<<(gr1+cnto%2)-1<<endl;
				res+=
				(ll)dpe[n][i][mode]
				*(ll)dpo[n][gr1][modo]%MOD
				*fac[i+(gr1+1-cnto%2)-1]%MOD
				*inv[i]%MOD
				*inv[(gr1+1-cnto%2)-1]%MOD
				*fac[(cnte-i)+(gr2+cnto%2)-1]%MOD
				*inv[(cnte-i)]%MOD
				*inv[(gr2+cnto%2)-1]%MOD
				*fac[gr1]%MOD
				*fac[gr2]%MOD
				*fac[i]%MOD
				*fac[cnte-i]%MOD;
	//			cout<<dpe[n][i][mode]<<' '
	//			<<dpo[n][gr1][modo]%MOD<<' '
	//			<<fac[i+(gr1+1-cnto%2)-1]%MOD<<' '
	//			<<inv[i]%MOD<<' '
	//			<<inv[(gr1+1-cnto%2)-1]%MOD<<' '
	//			<<fac[(cnte-i)+(gr2+cnto%2)-1]%MOD<<' '
	//			<<inv[(cnte-i)]%MOD<<' '
	//			<<inv[(gr2+cnto%2)-1]%MOD<<' '
	//			<<fac[gr1]%MOD<<' '
	//			<<fac[gr2]%MOD<<' '
	//			<<fac[i]%MOD<<' '
	//			<<fac[cnte-i]%MOD<<endl;
				res%=MOD;
//				cout<<"newres= "<<res<<endl;
			}
		}
		}
		cout<<""<<res<<endl;
	}
}