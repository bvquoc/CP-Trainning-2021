#include <bits/stdc++.h>
#define fi "CANDIES.INP"
#define fo "CANDIES.OUT"
#define loop(i,l,r) for(int i=(int)l ; i<=(int)r ; i++)
using namespace std;

const int N=1e6+1;

long vt;
long long t,n,k;
long long f[N],l[N];

void xdbang()
{
	f[0]=0;
	f[1]=1;
	f[2]=1;
	loop(i,3,1e6)
	{
		f[i]=f[i-1]+f[i-2];
		if (f[i]>1e6)
		{
			vt=i;
			break;
		}
	}
}

long cnp(long x,long y,long value)
{
	long d=x;
	long c=y;
	while (d+1<c)
	{
		long g=(d+c)/2;
		if (f[g]<=value) d=g; else c=g;
	}
	if (f[c]<=value) return f[c];
	if (f[d]<=value) return f[d];
	return 0;
}

void xuly()
{
	l[1]=f[1];
	l[2]=f[2];
	loop(i,3,n)
	{
		long u=cnp(1,vt,i);
		if (u==i)
		{
			l[i]=1;
			//cout<<i<<' '<<u<<' '<<l[i]<<endl;
			continue;
		}
		l[i]=l[u]+l[i-u];
		//cout<<i<<' '<<u<<' '<<l[i]<<endl;	
	}
	long long res=0;
	loop(i,1,n)
		if (l[i]>=k) res+=l[i];
		
	cout<<res<<endl;
}

void doc()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen(fi,"r",stdin);
	//freopen(fo,"w",stdout);
	cin>>t;
	xdbang();
	//cout<<cnp(1,vt,5);
	//loop(i,1,10) cout<<f[i]<<endl;
	loop(i,1,t)
	{
		cin>>n>>k;
		xuly();
	}
}

int main()
{
	doc();
	return 0;
}
