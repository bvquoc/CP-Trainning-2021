#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long k,ok = 1,s,n,a;
	cin >> k;
	if(k == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	if(k < 0)
	{
		ok = 0;
		k = abs(k);
	}
	for(int i = sqrt(k); i >= 1; i--)
	{
		if(k % i == 0)
		{
			s = k / i;//cout<<s<<" "<<i<<endl;
			if(((i + s) % 2)==0)
			{
				n = (i + s) / 2;
				a = s - n;
				//cout<<n<<" "<<s<<" "<<i<<" "<<a<<endl;
				cout << ((ok) ? n : a);
				return 0;
			}
		}
	}
	cout << "none";
}
