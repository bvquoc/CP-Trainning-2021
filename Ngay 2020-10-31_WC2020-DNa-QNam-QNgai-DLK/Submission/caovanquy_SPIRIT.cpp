#include<bits/stdc++.h>
using namespace std;

long long buoc(long long x,long long y)
{
	if ((y-x)%2==0) return (y-x)/2;
	return ((y-x)/2)+1;
}
int main()
{
	long long a,b,c;
	cin >> a >> b >> c;
	int i=1;	
	long long c1=1;
	long long tg=a;
	long long kq=0;
	for (i=1;c1<b;i++)
	{
		c1=c*i;
		if (a<c1 && c1<b)
		{
			//cout << tg << " ";
			kq+=buoc(tg,c1-1)+1;
			tg=c1+1;
			//cout << tg << " " << kq << endl;
		}
	}
	//cout << kq << endl;
	kq+=buoc(tg,b);
	cout << kq;
}
