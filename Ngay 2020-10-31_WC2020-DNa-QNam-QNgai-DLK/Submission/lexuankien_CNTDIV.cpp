#include<bits/stdc++.h>
using namespace std;
ifstream f;
ofstream g;
int q,n,l[1000010];
int main()
{
	f.open("cntdiv.inp");
	g.open("cntdiv.out");
	cin>>q;
	for (int i=1;i<=1e6+1;i++) l[i]=0;
	for (int i=1;i<=1e6;i++)
		for (int j=1;j<=1e6/i;j++)
		{
			l[i*j]++;
		}
	long long t;
	for (int i=1;i<=q;i++)
	{
		cin>>n;
		t=n*(n+1)*(n+2);
		cout<<(l[t]+2)/3;
	}
	f.close();
	g.close();
	return 0;
}
