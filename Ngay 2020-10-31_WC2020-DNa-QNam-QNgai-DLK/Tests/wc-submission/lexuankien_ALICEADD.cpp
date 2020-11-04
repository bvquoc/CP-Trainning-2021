#include<bits/stdc++.h>
using namespace std;
ifstream f;
ofstream g;
string s1,s2,s;
int t;

string cong(string a,string b)
{
	if (a.size()<b.size())
	for (int i=1;i<=b.size()-a.size();i++) a='0'+a;
	else 
	for (int i=1;i<=a.size()-b.size();i++) b='0'+b;
	string c="";
	int nho=0;	
	//cout<<nho;
	for (int i=a.size()-1;i>=0;i--)
	{
		int a1=int(a[i]-'0');
		int b1=int(b[i]-'0');
		int love;
		love=(a1+b1+nho)%10 ;
		//cout<<love;
		char kien=(char)(love+'0');
		c=kien+c;
		nho=(a1+b1+nho)/10;
	}
	if (nho>0) 
	{
		char kien=(char)(nho+'0');
		c=kien+c;
	}
	return c;
}
int main()
{
	f.open("aliceadd.inp");
	g.open("aliceadd.out");
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>s1;
		cin>>s2;
		//g<<s1<<" "<<s2<<" ";
		s=cong(s1,s2);
		cout<<s<<"\n";
	}
	f.close();
	g.close();
	return 0;
}
