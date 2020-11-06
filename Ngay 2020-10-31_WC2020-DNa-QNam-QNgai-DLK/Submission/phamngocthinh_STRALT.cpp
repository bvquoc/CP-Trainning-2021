#include<bits/stdc++.h>
using namespace std;
string S;
bool ktkt(char x)
{
	return ('a'<=x && x<='z');
}
string xlc(string CC)
{
	string hh="";
	for(int i=CC.length()-1;i>=0;i--) hh=hh+CC[i];
	return hh;
}
string xll(string CC)
{
	string hh="";
	for(int i=CC.length()-2;i>=0;i--) hh=hh+CC[i];
	return hh;
}
void solve()
{
	stack <string> St;
	int n=S.length();
	S=" "+S;// cout<<S<<endl;
	for(int i=1;i<=n;i++)
	{
	//	cout<<i<<" "<<S[i]<<endl;
	//	if(i>1) cout<<St.top()<<endl;
		if(S[i]!=')' && S[i]!=']')
		{	
			string str="";str=str+S[i];
			St.push(str);
		}
		else
		{
			if(S[i]==')')
			{	string ch="";
				int so=0,mu=1;
				while(St.top()!="(") { ch=St.top()+ch; St.pop(); } //cout<<ch<<endl;
				St.pop();
				while(!St.empty() && '0'<=St.top()[0] && St.top()[0]<='9') { so=(int)(St.top()[0]-'0')*mu+so; mu=mu*10; St.pop(); }
				string xau="";
				for(int i=1;i<=so;i++) xau=xau+ch;
				St.push(xau);
			}
			else
			{
				if(St.top()=="*")
				{
					string ch="";
					St.pop();
					while(St.top()!="[") { ch=St.top()+ch; St.pop(); }
					St.pop();
					string xau=ch;
					xau=xau+xll(ch);
					St.push(xau);
				}
				else
				{
					string ch="";
					while(St.top()!="*") { ch=St.top()+ch; St.pop(); }
					St.pop(); St.pop();
					string xau=ch;
					xau=xau+xlc(ch);
					St.push(xau);
				}
			}
		}
	}
	int res=0;
	string ans="";
	for(int i=1;i<=n;i++)  if(S[i]=='('||S[i]=='[') res++;
	cout<<res<<endl;
	while(!St.empty())
	{
	 ans=St.top()+ans; St.pop();
}
	cout<<ans;
}
int main()
{
//	freopen("STRALT.inp","r",stdin);
	cin>>S;
	solve();
	return 0;
}
