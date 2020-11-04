#include<bits/stdc++.h>
using namespace std;
ifstream f;
ofstream g;
int a,b,c;
int main()
{
	f.open("spirit.inp");
	g.open("spirit.out");
	cin>>a;
	cin>>b;
	cin>>c;
	int a1=a;
	int b1=b;
	int d=a1/c+1;
	int res=0;
	while (a1 < b1)
	{
		if (a1+2==d*c) 
		{
			a1=a1+1;
			res++;
		}
		else if(a1>d*c)
		{
			a1=a1+2;
			res++;
			d++;
		}
		else
		{
			a1=a1+2;
			res++;
		}
	}
	cout<<res;
	f.close();
	g.close();
	return 0;
}
