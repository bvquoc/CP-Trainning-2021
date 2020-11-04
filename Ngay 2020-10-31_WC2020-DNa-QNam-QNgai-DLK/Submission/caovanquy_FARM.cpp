#include<bits/stdc++.h>
using namespace std;
	
int n,k,q,p;
vector <int> mang;
bool FREE[100005];

bool kt(int x)
{
	for (int j=x+1;j<=x+k-1;j++) 
	{
		if (j>n) break;
		if (FREE[j]==true) return 1;
	}
	for (int j=x-k+1;j<=x-1;j++)
	{
		if (j<1) break;
		if (FREE[j]==true) return 1;
	}
	return 0;
}
pair <int,int> a[10005];
int main()
{
	cin >> n >> k >> q >> p;
	for (int i=1;i<=n;i++) 
	{
		int w;
		cin >> w;
		a[i]={w,i};
	}
	int m;
	if (q%p==0) m=q/p;
	else m=(q/p)+1;
	sort(a+1,a+1+n);
	for (int i=n;i>=1;i--)
	{
		if (kt(a[i].second)==0) 
		{
			mang.push_back(a[i].first);
			FREE[a[i].second]=true;
		}
		if (mang.size()==m) break;
	}
	long long kq=0;
	int i=0;
	while (q>0)
	{
		if (q-p>0) kq+=mang[i]*p;
		else kq+=mang[i]*q;
		i++;
		q-=p;
	}
	cout << kq;
}
