#include <bits/stdc++.h>
#define fi "TANK.INP"
#define fo "TANK.OUT"
#define loop(i,l,r) for(int i=(int)l ; i<=(int)r ; i++)
using namespace std;

const int N=1e6;

long n,m;
long a[N];
long long l[N];

void doc()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen(fi,"r",stdin);
	//freopen(fo,"w",stdout);
	cin>>m>>n;
	loop(i,1,n) cin>>a[i];
}

bool ktra(long x)
{
	loop(i,x,n) 
		if (l[i]-l[i-x]<m) return false;
	return true;
}

long cnp(long x,long y)
{
	long d=x;
	long c=y;
	while (d+1<c)
	{
		long g=(d+c)/2;
		if (ktra(g)==true) c=g; else d=g;
	}
	
	if (ktra(d)==true) return d;
	if (ktra(c)==true) return c;
	return 0;
}

void xuly()
{
	l[0]=0;
	loop(i,1,n) l[i]=l[i-1]+a[i];
	
	long u=cnp(1,n);
	if (u>0) cout<<u;
}

int main()
{
	doc();
	xuly();
	return 0;
}
