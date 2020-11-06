#include <bits/stdc++.h>
#define fi "STRALT.INP"
#define fo "STRALT.OUT"
#define For(i,a,b) for(int i=a; i<=b; i++)
#define Ford(i,a,b) for(int i=a; i>=b; i--)
using namespace std;
string s;

int so(string v)
{
	int res=0;
	For(i,0,v.size()-1)	res=res*10+(v[i]-'0');
	return res;
}
void solve()
{
	//stack <char> t;
	stack <string> t;
	For(i,0,s.size()-1)
	{
		if( s[i]==')' )
		{
			string x;
			while(!t.empty() && !( ("0"<=t.top()) && (t.top()<="9") )) 
			{
				if(t.top() != "(" ) x=t.top()+x;
				t.pop();
			}
			string v;
			while(!t.empty() && ("0"<=t.top()) && (t.top()<="9") )
			{
				v=t.top()+v; t.pop();
			}
			int k=so(v);
			For(i,1,k) t.push(x); 
				//For(i,0,x.size()-1) t.push(x[i]);
		}
		else if( s[i]==']')
		{
			if(t.top()=="*")
			{
				t.pop();
				string x;
				while(!t.empty() && t.top() != "[")
				{
					x=t.top()+x;	t.pop();
				}
				t.pop();
				string xx="";
				For(i,0,x.size()-2) xx=x[i]+xx;
				t.push(x);		//For(i,0,x.size()-1) t.push(x[i]);
				t.push(xx);		//Ford(i,x.size()-2,0) t.push(x[i]);
			}
			else
			{
				string x;
				while(!t.empty() && t.top() != "*")
				{
					x=t.top()+x;	t.pop();
				}
				t.pop(); t.pop();
				string xx="";
				For(i,0,x.size()-1) xx=x[i]+xx;
				t.push(x);		 //For(i,0,x.size()-1) t.push(x[i]);
				t.push(xx);		//Ford(i,x.size()-1,0) t.push(x[i]);
			}
		}
		else
		{
			string x;		x=x+s[i];		t.push(x);
		}
	}
	string tt="";
	while(!t.empty())
	{
		tt=t.top()+tt;		t.pop();
	}
	cout<<tt;
}
int main()
{
//	freopen(fi,"r",stdin);
//	freopen(fo,"w",stdout);
	ios_base :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>s;
	int res=0;
	For(i,0,s.size()-1) 
		if( (s[i]==')') || (s[i]==']') ) res++;
	cout<<res<<"\n";
	solve();
}
