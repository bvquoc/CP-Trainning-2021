#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	long long sum=0,m; int kq,i,l,n; 
	cin>>m>>n;
	l=1;
	for (i=1;i<=n;i++)
	{
		cin>>a[i]; sum+=a[i];
		while (l<i&&sum-a[l]>m)
		{
			sum-=a[l]; l++;
		}
		kq=max(kq,i-l+1);
	}
	cout<<kq;
}
