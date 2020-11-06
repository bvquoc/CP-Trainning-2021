#include<bits/stdc++.h>
using namespace std;

int i,j;
long long k,sl,sn,minl,minn;

int main()
{
	cin >> k;
	minl=1e12;
	minn=minl;
	if (k==0) cout << 0;
	else
	{
		bool kt;
		for (i=sqrt(abs(k));i>=1;i--)
		{
			if (abs(k)%i==0 && (i+(abs(k)/i))%2==0) 
			{
				kt=true;
				sl=(i+(abs(k)/i))/2;
				sn=sl-i;
				if (k>0) minl=min(minl,sl);
				else minn=min(minn,sn); 
			}
		}
		
		if (kt==false) cout << "none";
		else 
		{
			if (k>0) cout << minl;
			else cout << minn;
		}
	}
}


