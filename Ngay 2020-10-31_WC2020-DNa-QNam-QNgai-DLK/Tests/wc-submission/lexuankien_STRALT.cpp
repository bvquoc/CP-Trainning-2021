#include<bits/stdc++.h>
using namespace std;
ifstream f;
ofstream g;
stack<string> h;
string s;
int main()
{
	//ios_base :: sync_with_stdio(false);
	//cin.tie(0); cout.tie(0);
	f.open("stralt.inp");
	g.open("stralt.out");
	cin>>s;
	long long ans=0;
	s="!"+s;
	for (int i=0;i<s.size();i++)
	{
		string thinhngu="";
		thinhngu=thinhngu+s[i];
		h.push(thinhngu);
		if (s[i]==')')
		{
			ans++;
			h.pop();
			string love="";
			while (h.top()[0]!='(')
			{
				string o=h.top();
				h.pop();
				love=o+love;
			}
			h.pop();
			string kien="";
			while('0'<=h.top()[0] && h.top()[0]<='9') 
			{
				kien=h.top()+kien;
				h.pop();
			}
			int thinh=0;
			for (int j=0;j<kien.size();j++)
				thinh=thinh*10+(int)(kien[j]-'0');
			string love1="";
			for (int j=1;j<=thinh;j++) love1=love1+love;
			h.push(love1);
		}
		//if(s[i]==']') ans++;
		//h.push(thinhngu);
		else if (s[i]==']')
		{
			ans++;
			h.pop();
			string love="";
			if (h.top()=="*")
			{
				h.pop();
				while(h.top()[0]!='[')
				{
					love=h.top()+love;
					h.pop();
				}
				h.pop();
				string love1=love;
				for (int j=love.size()-2;j>=0;j--)
				{
					love1=love1+love[j];
				}
				//cout<<love1<<endl;
				h.push(love1);
			}
			else
			{
				while(h.top()[0]!='*')
				{
					love=h.top()+love;
					h.pop();
				}
				h.pop();
				h.pop();
				string love1=love;
				for (int j=love.size()-1;j>=0;j--)
					love1=love1+love[j];
				//cout<<love1<<endl;
				h.push(love1);
			}
		}
		
	}
	//cout<<ans<<"\n";
	/*s="";
	while(!h.empty())
	{
		s=h.top()+s;;
		h.pop();
	}*/
	//cout<<s<<"\n";
	//cout<<s<<endl;
/*	for (int i=0;i<s.size();i++)
	{
		string thinhngu="";
		thinhngu=thinhngu+s[i];
		h.push(thinhngu);
		if (s[i]==']')
		{
			h.pop();
			string love="";
			if (h.top()[0]=='*')
			{
				h.pop();
				while(h.top()!="[")
				{
					love=h.top()+love;
					h.pop();
				}
				h.pop();
				string love1=love;
				for (int j=love.size()-2;j>=0;j--)
				{
					love1=love1+love[j];
				}
				//cout<<love1<<endl;
				h.push(love1);
			}
			else
			{
				while(h.top()[0]!='*')
				{
					love=h.top()+love;
					h.pop();
				}
				h.pop();
				h.pop();
				string love1=love;
				for (int j=love.size()-1;j>=0;j--)
					love1=love1+love[j];
				//cout<<love1<<endl;
				h.push(love1);
			}
		}
	}*/
	cout<<ans<<"\n";
	s="";
	while(h.size()>1)
	{
		s=h.top()+s;;
		h.pop();
	}
	cout<<s;
	f.close();
	g.close();
	return 0;
}
