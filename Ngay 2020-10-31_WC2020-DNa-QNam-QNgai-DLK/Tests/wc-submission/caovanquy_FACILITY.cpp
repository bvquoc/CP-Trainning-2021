#include<bits/stdc++.h>
using namespace std;

struct Work {
	long long s, d, r,kt;
};
int n,k;
 	
Work a[1000005];
long long f[1000005]; 

bool cmp(Work x,Work y)
{
		return x.kt<y.kt;
}

int main()
{
	cin >> n >> k;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i].s >> a[i].d >> a[i].r;
		a[i].kt=a[i].s+a[i].d+k;
	}
	sort(a+1,a+1+n,cmp);
	//cout << endl;
	//for (int i=1;i<=n;i++) cout << a[i].s << " " << a[i].kt << " " << a[i].r << endl;
	//cout << endl;
	for (int i=1;i<=n;i++)
	{	
		f[i] = f[i - 1];
		/*for (int j=0;j<i;j++)
		{
			if (a[i].s>=a[j].kt) 
				f[i] = max(f[i] ,f[j] + a[i].r);
		}*/
		int l=0;int r=i-1;
		while (l<r)
		{
			int mid=(l+r)/2;
			if (a[i].s<a[mid+1].kt) r=mid;
			else l=mid+1;
		}
		f[i] = max(f[i] ,f[l] + a[i].r);
		//cout << a[l].kt << endl;
	}
	cout << f[n];
}
