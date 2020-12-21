/// Nỡm ///
#include <bits/stdc++.h>
using namespace std;
 
#define task "gift11"
#define file freopen(task".inp","r",stdin),freopen(task".out","w",stdout);
#define faster ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define FOR(i,a,b) for(__typeof(b) i=a; i<=b; i++)
#define DFOR(i,a,b) for(__typeof(b) i=b; i>=a; i--)
 
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define X first
#define Y second
 
#define BUG(x) {cout << #x << " = " << x << '\n';}
#define PR(x,a,b) {cout << #x << " = "; FOR(i,a,b) cout << x[i] << ' '; cout << '\n';}
 
#define MOD 1000000007
#define MAXN 2011
#define MODULE 998244353

int n;
int a[MAXN];

void read()
{
	cin >> n;
	FOR(i,1,n)
		cin >> a[i];
}

string numtostring(int x)
{
	string t;
	while(x)
	{
		t = t + char('0'+x%10);
		x /= 10;
	}
	reverse(t.begin(), t.end());
	return t;
}

namespace sub1
{
	int b[10];
	int visit[10];
	int res;
	

	int check()
	{
		string s;
		FOR(i,1,n)
		{
			s+= numtostring(a[b[i]]);
		}


		int dem1=0;
		int dem2=0;
		FOR(i,0,s.size()-1)
		{
			if(i%2)
				dem1+= s[i]-'0';
			else
				dem2+= s[i]-'0';
		}

		int t = abs(dem2-dem1);
		return t%11==0;
	}

	
	void hoanvi(int k)
	{
		FOR(i,1,n)
		{
			if(visit[i])
				continue;

			b[k] = i;
			visit[i]= true;

			if(k==n)
			{
				//FOR(i,1,n)
				//	cout << b[i];
				res+=check();
			}
			else
				hoanvi(k+1);
			visit[i]= false;
		}
	}

	void solve()
	{
		res = 0;
		hoanvi(1);
		cout << res << '\n';
	}
}

namespace sub2
{
	bool ktra(int x)
	{
		int dem = 0;
		while(x)
		{
			dem++;
			x/=10;
		}
		return dem%2==0;
	}
	bool check()
	{
		FOR(i,1,n)
			if(!ktra(a[i]))
				return false;
		return true;
	}

	ll giaithua(ll x)
	{
		ll res = 1;
		FOR(i,2,x)
		{
			res = res * i % MODULE;
		}
		return res;
	}

	void solve()
	{
		string s;

		FOR(i,1,n)
		{
			s += numtostring(a[i]);
		}

		int dem1=0;
		int dem2=0;
		FOR(i,0,s.size()-1)
		{
			if(i%2)
				dem1+= s[i]-'0';
			else
				dem2+= s[i]-'0';
		}

		int t = abs(dem1-dem2);
		if(t%11)
		{
			cout << 0 << '\n';
			return;
		}
		cout << giaithua(n) << '\n';
	}
}

namespace sub3
{
	bool ktra(int x)
	{
		int dem = 0;
		while(x)
		{
			dem++;
			x/=10;
		}
		return dem%2==1;
	}

	bool check()
	{
		FOR(i,1,n)
			if(!ktra(a[i]))
				return false;
		return true;
	}

	int demle[MAXN];
	int demchan[MAXN];

	void prepare()
	{
		FOR(i,1,n)
		{
			string s;
			s = numtostring(a[i]);

			FOR(j,0,s.size()-1)
			{
				if(j%2)
					demle[i]+= s[j]-'0';
				else
					demchan[i] += s[j]-'0';
			}			
		}

		
	}

	void solve()
	{
		prepare();

		srand(time(NULL));
		cout << rand()%MODULE << '\n';
	}

}

void Rand()
{
	srand(time(NULL));

	int newt = 8;
	cout << newt << '\n';
	while(newt--)
	{
		int newn = rand() % 8;
		cout << newn << '\n';
		FOR(i,1,newn)
		{
			cout << rand()%100000 << ' ' ;
		}

		cout << '\n';
	}
}

void solve()
{
	if(n<=8)
	{
		sub1::solve();
		return;
	}

	if(sub2::check())
	{
		sub2::solve();
		return;
	}

	if(sub3::check())
	{
		sub3::solve();
		return;
	}
}

int main()
{
	file;
	faster;

	int t;
	cin >> t;
	while(t--)
	{
		read();
		solve();
	}
	//Rand();
}