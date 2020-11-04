#include<bits/stdc++.h>
using namespace std;
void xuly()
{
	int a,b,c;
	cin>>a>>b>>c;
	int dem=0;
	while(a<b)
	{
		if(a+2==b+1)
		{
			dem++;
			a++;
			continue;
		}
		if((a+2)%c==0)
		{
			a++;
			dem++;
			continue;
		}
		else 
		{
		a+=2;
		dem++;
		}	
	}
	cout<<dem;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen("SPIRIT.INP","r",stdin);
//	freopen("SPIRIT.OUT","w",stdout);
	xuly();
	return 0;
}
