#include<bits/stdc++.h>
using namespace std;
ifstream f;
ofstream g;
int test;
long long n,k;
int main()
{
	f.open("candies.inp");
	g.open("candies.out");
	cin>>test;
	for (int i=1;i<=test;i++)
	{
		cin>>n>>k;
		if (n%2==0 && k%2==0) cout<<abs(n-k)<<"\n";
		else cout<<abs(n+k)<<"\n";
	}
	f.close();
	g.close();
	return 0;
}
