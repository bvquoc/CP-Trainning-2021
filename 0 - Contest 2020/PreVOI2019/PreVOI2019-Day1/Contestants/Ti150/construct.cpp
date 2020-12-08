#include <bits/stdc++.h>
#define int long long
using namespace std;

int tests, n, m;
int bit[110005][2];
int a[110005], temp[110005];

void update(int pos, int val, int type)
{
	while(pos<=n+5)
	{
		bit[pos][type]+=val;
		pos+=pos&-pos;
	}
}

int getp(int pos, int type)
{
	// cout<<pos<<endl;
	int res=0;
	while(pos)
	{
		res+=bit[pos][type];
		pos-=pos&-pos;
	}
	return res;
}

int getr(int l, int r, int type)
{
	// cout<<l<<" "<<r<<endl;
	return getp(r, type)-getp(l-1, type);
}

signed main()
{
	freopen("construct.inp", "r", stdin);
	freopen("construct.out", "w", stdout);
	cin>>tests;
	for(int test=1; test<=tests; test++)
	{
		scanf("%lld %lld", &n, &m);
		// cin>>n>>m;
		for(int i=1; i<=n; i++)
		{
			for(int j=0; j<=1; j++)
			{
				bit[i][j]=0;
			}
		}
		for(int i=1; i<=n; i++)
		{
			scanf("%lld", &temp[i]);
			// cin>>temp[i];
			a[i]=temp[i]-temp[i-1];
			update(i, a[i], 0);
			if(a[i]>0) update(i, a[i], 1);
		}
		for(int i=1; i<=m; i++)
		{
			int type, l, r, v;
			// cin>>type;
			scanf("%lld", &type);
			if(type==1)
			{
				scanf("%lld %lld %lld", &l, &r, &v);
				// cin>>l>>r>>v;
				update(l, v, 0);
				update(r+1, -v, 0);
				int newl=max(0ll, a[l]+v), newr=max(0ll, a[r+1]-v);
				update(l, newl-max(a[l], 0ll), 1);
				update(r+1, newr-max(a[r+1], 0ll), 1);
				a[l]+=v;
				a[r+1]-=v;
			}
			else
			{
				// cin>>l>>r;
				scanf("%lld %lld", &l, &r);
				// cout<<getr(l, r, 1)<<endl;
				printf("%lld\n", getr(l, r, 1)-max(a[l], 0ll)+getp(l, 0));
				// cout<<getr(l, r, 1)-max(a[l], 0ll)+getp(l, 0)<<endl;
				// cout<<getr(l, r, 1)<<" "<<a[l]<<" "<<getp(l, 0)<<endl;
				// cout<<"not anymore"<<endl;
			}
			// for(int i=1; i<=n; i++)
			// {
			// 	cout<<a[i]<<" ";
			// }
			// cout<<endl;
		}
	}
}