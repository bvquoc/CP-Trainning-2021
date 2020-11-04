#include<bits/stdc++.h>
using namespace std;

int n,m,l;
long long a[100005],f[100005];

int main()
{
	cin >> m >> n;
	for (int i=1;i<=n;i++) 
	{
		cin >> a[i];
		f[i]=f[i-1]+a[i];
	}
	for (l=1;l<=n;l++)
	{
		if (f[l]>=m) break;
	}
	for (int i=l+1;i<=n;i++)
	{
		if (f[i]-f[i-l]<m)
		{
			l++;
			continue;
		}
	}
	cout << l;
}
