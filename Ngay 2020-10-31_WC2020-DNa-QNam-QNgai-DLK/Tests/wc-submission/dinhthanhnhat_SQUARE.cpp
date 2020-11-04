#include<bits/stdc++.h>
using namespace std;
long long k , sang , c ,s;
int main()
{
	cin >> k;
	if(k==0)
	{
		cout << 0;
		return 0;
	}

	if (k > 0 ) sang = 1 ;k=abs(k);
	for(long long  c=sqrt(k); c>= 1; c--)
	{
		if(k % c == 0)
		{
			long long s = k / c;
			if((c + s) % 2==0)
			{
                long long bs2=(c+s)/2;
				long long bs=s-bs2;
				if(sang==0)
                    cout<<bs;
				else cout<<bs2;
				return 0;
			}
		}
	}
	cout << "none";
}
