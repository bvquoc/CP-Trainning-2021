#include <bits/stdc++.h>
#define fi "ALICEADD.INP"
#define fo "ALICEADD.OUT"
#define For(i,a,b) for(int i=a; i<=b; i++)
#define Ford(i,a,b) for(int i=a; i>=b; i--)
using namespace std;
int t;
string a,b,s;

void solve()
{
	while(a.size() > b.size()) b="0"+b;
	while(a.size() < b.size()) a="0"+a;
	int n=a.size();
	s="";
	int nho=0;
	
	Ford(i,n-1,0)
	{
		int x=a[i]-'0';
		int y=b[i]-'0';
		int z=(x+y+nho)%10;
		nho=(x+y+nho)/10;
		s=(char)(z+'0')+s;
	}
	if(nho>0) s=(char)(nho+'0')+s;
	cout<<s<<"\n";
}

int main()
{
//	freopen(fi,"r",stdin);
//	freopen(fo,"w",stdout);
	ios_base :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>t;
	For(test,1,t)
	{
		cin>>a>>b;
		solve();
	}
}
