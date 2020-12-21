/// Nỡm ///
#include <bits/stdc++.h>
using namespace std;
 
#define task "coolmac"
#define file freopen(task".inp","r",stdin),freopen(task".out","w",stdout);
#define faster ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define FOR(i,a,b) for(__typeof(b) i=a; i<=b; i++)
#define DFOR(i,a,b) for(__typeof(b) i=b; i>=a; i--)
 
#define ll long long
#define pb push_back
#define ii pair<int,int>
#define X first
#define Y second
 
#define BUG(x) {cout << #x << " = " << x << '\n';}
#define PR(x,a,b) {cout << #x << " = "; FOR(i,a,b) cout << x[i] << ' '; cout << '\n';}
 
#define MOD 1000000007
#define MAXN 10011

struct data
{
	int l,r;

	bool operator < (data b)
	{
		if(l==b.l)
			return r < b.r;
		return l < b.l;
	}
};

int n,m;
int t[MAXN];
data a[MAXN];

void read()
{
	cin >> m;
	FOR(i,1,m)
		cin >> a[i].l >> a[i].r;

	cin >> n;
	FOR(i,1,n)
		cin >> t[i];
}

namespace sub1
{
	int b[MAXN];
	int res = MOD;
	int mintime;

	int check()
	{
		int sum = 0;
		int dem = 0;
		FOR(i,1,m)
			if(b[i])
			{
				if(a[i].r<mintime)
					return MOD;
				dem++;
				sum+= a[i].r - max(mintime,a[i].l);
			}
		if(sum>= 100000-mintime)
			return dem;
		return MOD;
	}

	void sinhnp(int k)
	{
		FOR(i,0,1)
		{
			b[k] = i;
			if(k==m)
			{
				res = min(res,check());
			}
			else
				sinhnp(k+1);
		}
	}

	void prepare()
	{
		mintime = MOD;
		FOR(i,1,n)
			mintime = min(mintime,t[i]);
	}

	void solve()
	{
		prepare();
		sinhnp(1);
		if(res==MOD)
			res = -1;
		cout << res << '\n';
	}
}

namespace sub2
{
	int mintime;

	void prepare()
	{
		mintime = MOD;
		FOR(i,1,n)
			mintime = min(mintime,t[i]);
	}

	void solve()
	{
		prepare();
		sort(a+1,a+m+1);


		int num = 0;
		int i = 0;
		int start = mintime;
		int end = -1;

		while(i <=m)
		{
			if(a[i].r < start)
				i++;
			else
			{
				if(a[i].l>start)
					break;

				while(i<=m && a[i].l < start)
				{
					end = max(end,a[i].r);
					i++;
				}

				if(start!=end)
				{
					num++;
					start = end;
				}
			}
		}

		if(end>=100000)
		{
			cout << num << '\n';
			return;
		}
		cout << -1 <<'\n';

	}
}

void Rand()
{
	srand(time(NULL));

	int newm = rand() % 3000;
	cout << newm << '\n';
	FOR(i,1,newm)
	{
		int u = rand()%100000;
		int v = rand()%100000;

		cout << min(u,v) << ' ' << max(u,v) << '\n';
	}

	int newn = rand() % 3000;
	cout << newn << '\n';
	FOR(i,1,newn)
		cout << rand() % 100000 << ' ';
}	

void solve()
{
	if(n<=10 && m<=16)
	{
		sub1::solve();
		return;
	}

	//if(n<=3000 && m<=3000)
	{
		sub2::solve();
	}
}

int main()
{
	file;
	faster;

	read();
	solve();

	//Rand();

    return 0;
}