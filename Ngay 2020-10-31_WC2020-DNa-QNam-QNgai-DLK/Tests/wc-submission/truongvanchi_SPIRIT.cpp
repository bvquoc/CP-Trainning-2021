#include <bits/stdc++.h>
#define fi "SPIRIT.INP"
#define fo "SPIRIT.OUT"
#define loop(i,l,r) for(int i=(int)l ; i<=(int)r ; i++)
using namespace std;

long long a,b,c;

void doc()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen(fi,"r",stdin);
//	freopen(fo,"w",stdout);
	cin>>a>>b>>c;
}

long soboi(long long c,long long a,long long b)
{
	long v=a-1;
	long u=b-(b%c);
	return (u-v)/c-1;
}

void xuly()
{
	long long dem=0;
	if (c%2 ==0)
	{
		if (a%2==1 && b%2==1) cout<<(b-a)/2;
		if (a%2==1 && b%2==0) cout<<(b-a)/2 +1;
		if (a%2==0 && b%2==0) cout<<(b-a-2)/2 +2;
	} else 
	{
		if (c>b) cout<<(b-a+1)/2; else 
		if (c>a) 
		{
			long d=(c+1-a+1)/2;
			
		}
	}
}

bool kta(long long a,long long b)
{
	if ((a/b)*b == a) return true;
	return false;
}

void xuly1()
{
	if (c%2 ==0)
	{
		if (a%2==1 && b%2==1) cout<<(b-a)/2;
		if (a%2==1 && b%2==0) cout<<(b-a)/2 +1;
		if (a%2==0 && b%2==1) cout<<(b-a)/2 +1;
		if (a%2==0 && b%2==0) cout<<(b-a-2)/2 +2;
		return;
	}
	long long d=0;
	while (a<b)
	{
		if (kta(a+2,c))
		{
			a=a+1;
			d++;
		} else 
		{
			a=a+2;
			d++;
		}
	}
	cout<<d;
}

int main()
{
	doc();
	xuly1();
	return 0;
}
