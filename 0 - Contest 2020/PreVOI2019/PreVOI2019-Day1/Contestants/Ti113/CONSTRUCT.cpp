#include <bits/stdc++.h>

using namespace std;
const string filename = "CONSTRUCT";

#define int long long

int t,n,m;
int a[100011];
int d[100011];
int Tree[100011];
int inc[100011];

void update(int x,int val)
{
	for(;x<=100010;x+=x&(-x))
		Tree[x] += val;		         		
}

int query(int x)
{
	int ans = 0;
	for (;x>0;x-=x&(-x))
		ans += Tree[x];
	return ans;
}

void update2(int x,int val)
{
	for(;x<=100010;x+=x&(-x))
		inc[x] += val;
}

int query2(int x)
{
	int ans = 0;
	for(;x>0;x-=x&(-x))
		ans += inc[x];
	return ans;
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen( (filename + ".inp").c_str(), "r", stdin);
	freopen( (filename + ".out").c_str(), "w", stdout);

	cin >> t;
	while(t--)
	{
		for (int i=0;i<=100010;i++)
			a[i] = d[i] = Tree[i] = inc[i] = 0;
		cin >> n >> m;
		for (int i=1;i<=n;i++)
			cin >> a[i];        
		for (int i=1;i<=n;i++)
		{
			d[i] = a[i] - a[i-1];
			if(d[i] > 0)
				update(i,d[i]);
		}
		while(m--)
		{
			int type;
			cin >> type;
			if (type == 2)
			{
				int l,r;
				cin >> l >> r;
				cout << a[l] + query2(l) + query(r) - query(l) << '\n';
			}
			else
			{
				int l,r,k;
				cin >> l >> r >> k;
				update2(l,k);
				update2(r+1,-k);
				if (d[l] > 0)
					update(l,-d[l]);
				d[l] += k;
				if (d[l] > 0)
					update(l,d[l]);
				if (d[r+1] > 0)
					update(r+1,-d[r+1]);
				d[r+1] -= k;
				if (d[r+1] > 0)
					update(r+1,d[r+1]);
			}
		}
	}
}