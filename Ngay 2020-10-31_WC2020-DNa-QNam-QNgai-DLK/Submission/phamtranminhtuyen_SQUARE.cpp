#include<bits/stdc++.h>
using namespace std;
int k;
void doc()
{
	cin>>k;
}
bool scp(int k)
{
	int kp=round(sqrt(k));
	if(kp*kp==k)return true;
	else return false;
}
void xuly()
{
	int i=1;
	while(!scp(k))
	{
		k+=i;
		i+=2;
	}
	cout<<sqrt(k);
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen("SQUARE.INP","r",stdin);
//	freopen("SQUARE.OUT","w",stdout);
	doc();
	xuly();
	return 0;
}
