#include <bits/stdc++.h>
#define fi "FACILITY.INP"
#define fo "FACILITY.OUT"
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
using namespace std;

struct bg{
	long long be,en,value;
};

const int N=1e6;

long k,n;
long long dp[N+1];
bg a[N+1];



bool dk(bg a,bg b)
{
	return (a.en<b.en);
}

long cnp(long x,long y,long gt)
{
	long d=x;
	long c=y;
	while (d+1<c)
	{
		long g=(d+c)/2;
		if (a[g].en<=gt) d=g; else c=g;
	}
	if (a[c].en<=gt) return c;
	if (a[d].en<=gt) return d;
	return 0;
}

void xuly()
{
	sort(a+1,a+n+1,dk);
	dp[0]=0;
	loop(i,1,n)
	{
		long u=cnp(1,n,a[i].be);
		dp[i]=max(dp[i-1],a[i].value+dp[u]);
	}
	cout<<dp[n]<<endl;
}

void doc()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen(fi,"r",stdin);
	//freopen(fo,"w",stdout);
	cin>>n>>k;
	loop(i,1,n) 
	{
		cin>>a[i].be>>a[i].en>>a[i].value;
		a[i].en=a[i].be+a[i].en+k;	
	}
}

int main()
{
	doc();
	xuly();
	return 0;
}
