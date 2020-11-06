#include<bits/stdc++.h>
using namespace std;
ifstream f;
ofstream g;
long long k,l[5000000],s[5000000];
int sole[5000000];
bool kiemtrasochinhphuong(long long n)
{
long long x=sqrt(n);
return x*x==n;
}
int main()
{
	f.open("square.inp");
	g.open("square.out");
	cin>>k;
	sole[1]=1;
	for (int i=2;i<=1e6;i++)
	{
		sole[i]=sole[i-1]+2;
	}
	s[1]=1;
	for (int i=2;i<=1e6;i++) s[i]=s[i-1]+sole[i];
	l[0]=k+0;
	for (int i=1;i<=1e6;i++)
	{
		l[i]=k+s[i];
	}
	int ok=0;
	for (int i=0;i<=1e6;i++) 
	if (kiemtrasochinhphuong(l[i])==1)
	{
		cout<<sqrt(l[i]);
		ok=1;
		break;
	}
	if (ok==0) cout<<"none";
	f.close();
	g.close();
	return 0;
}
