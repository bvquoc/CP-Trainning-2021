#include <bits/stdc++.h>
#define fi "STRALT.INP"
#define fo "STRALT.OUT"
#define loop(i,l,r) for(int i=(int)l ; i<=(int)r ; i++)
#define rloop(i,l,r) for(int i=(int)l ; i>=(int)r; i--)
using namespace std;

string s;

void doc()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen(fi,"r",stdin);
//	freopen(fo,"w",stdout);
	cin>>s;
}

string lap(string s,string u)
{
	long v=0;
	loop(i,0,u.size()-1)
	{
		v=v*10+u[i]-'0';
	}
	string x="";
	loop(i,1,v) x=x+s;
	return x;
}

string palile(string s)
{
	long u=s.size()-1;
	string x;
	x=s[s.size()-1];
	rloop(i,s.size()-2,0) x=s[i]+x+s[i];
	return x;
}

string palichan(string s)
{
	string x;
	rloop(i,s.size()-1,0) x=s[i]+x+s[i];
	return x;
}

void xuly()
{
	stack <string> q;
	long n=s.size();
	s='!'+s;
	long dem=0;
	loop(i,1,n)
	{
		if (s[i]==')')
		{
			string s2="";
			while (!q.empty() && q.top() != "(")
			{
				s2=q.top()+s2; q.pop();
			}
			if (!q.empty()) q.pop();
			string s1="";
			while (!q.empty() && q.top()>="0" && q.top()<="9")
			{
				s1=q.top()+s1;
				q.pop();
			} 
			dem++;
			s2=lap(s2,s1);
			q.push(s2);
		} else
		if (s[i]==']' && q.top()=="*")
		{
			string s2="";
			q.pop();
			while (!q.empty() && q.top()!="[")
			{
				s2=q.top()+s2; q.pop();
			}
			if (!q.empty())
			{
				dem++;
				s2=palile(s2);
				q.pop();
				q.push(s2);
			}
		} else 
		if (s[i]==']' && q.top()!="*")
		{
			string s2="";
			while(!q.empty() && q.top()!="*")
			{
				s2=q.top()+s2; q.pop();
			}
			if (!q.empty()) q.pop();
			if (!q.empty())
			{
				dem++;
				s2=palichan(s2);
				q.pop();
				q.push(s2);
			}
		} else
		if (s[i]!=')' && s[i]!=']') 
		{
			string v;
			v=s[i];
			q.push(v);
		}
	}
	cout<<dem<<endl;
	string s2;
	while (!q.empty())
	{
		s2=q.top()+s2;
		q.pop();
	}
	cout<<s2;
}

int main()
{
	doc();
	xuly();
	return 0;
}

