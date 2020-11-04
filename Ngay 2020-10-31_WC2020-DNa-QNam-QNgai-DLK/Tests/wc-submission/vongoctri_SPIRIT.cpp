#include <bits/stdc++.h>
#define fi "SPIRIT.INP"
#define fo "SPIRIT.OUT"
#define For(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
int a,b,c;

void sub1()
{
	int res=0;
	while(a<b)
	{
		if((a+2) %c ==0) a++;
		else a+=2;
		res++;
	}
	cout<<res;
}
int tknp(int u)
{
	int dau=0; int cuoi=1e9/c;
	while(dau+1<cuoi)
	{
		int g=(dau+cuoi)/2;
		if(c*g > u) cuoi=g; else dau=g;
	}
	if(c*cuoi < u) return cuoi;
	if(c*dau < u) return dau;
}
void solve()
{
	if(c%2==0)
	{
		int res=0;
		if(a%2==0) { res++; a++;}
		if(b%2==0) { res++; b--;}
		res=res+(b-a)/2;
		cout<<res;
	}
	else
	{
		int i=tknp(a)+1;		int j=tknp(b);
		int res=0;
		
		int bl=(j-i+1)/2; int bc=(j-i+1)/2;
		
		if((j-i+1)%2==1)
			if(i%2==0) bc++; else bl++;
			
		if(a%2==0) res=res+(b-a)/2 +bc;
		else res=res+(b-a)/2 +bl;
		
		cout<<res;
	}
}

int main()
{
//	freopen(fi,"r",stdin);
//	freopen(fo,"w",stdout);
	ios_base :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>a>>b>>c;
	//if(c==2) cout<<(b-a)/2;else
	solve();
}
