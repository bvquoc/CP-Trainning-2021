#include<bits/stdc++.h>
using namespace std;
int a,b,c;
void solve()
{
	int d=(a/c)+1,res=0;
	while(a<b)
	{
		if(a+2==c*d) {
			res++; a++;
		}
		else
		if(a+2>c*d)
		{
			res++; a+=2; d++;
		}
		else {
			res++; a+=2;
		}
	//	cout<<a<<" "<<res<<endl;
	}
	cout<<res;
}
int main()
{
//	freopen("SPIRIT.inp","r",stdin);
	cin>>a>>b>>c;
	solve();
	return 0;
}
