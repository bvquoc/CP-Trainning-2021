#include <bits/stdc++.h>
#define fi "ALICEADD.INP"
#define fo "ALICEADD.OUT"
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l ; i>=(int)r ; i--)
using namespace std;

long test;
string a,b;

string tong(string x,string y)
{
	if (x.size()>y.size()) swap(x,y);
	
	while (x.size()<y.size()) x='0'+x;
	//cout<<x<<' '<<y;
	
	string s="";
	long sm=0;
	//rloop(i)
	rloop(i,x.size()-1,0)
	{
		long u=(x[i]-'0')+(y[i]-'0');
		u=u+sm;
		char v=(u%10)+'0';
		s=v+s;
		sm=u/10;
	}
	if (sm>0)
	{
		char v=sm+'0';
		s=v+s;
	}
	return s;
}

void doc()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen(fi,"r",stdin);
	//freopen(fo,"w",stdout);
	cin>>test;
	loop(i,1,test)
	{
		cin>>a>>b;
		cout<<tong(a,b)<<endl;
	}
//	cout<<tong("50","6");
}

int main()
{
	doc();
	return 0;
}
