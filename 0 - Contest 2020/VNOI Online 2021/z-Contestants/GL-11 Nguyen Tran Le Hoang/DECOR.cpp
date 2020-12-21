#include <bits/stdc++.h>
using namespace std;

#define NAME "DECOR"
#define N 100007
#define Times cout<<"\nTime: "<<clock()/(double)1000<<" sec"
#define fi first
#define se second

int n, m, k, res, f[N], lft, rght;
pair<int, int> a[N];
vector<int> adj[N];
string s;

void minimize(int tmp, int i)
{
	if(res < tmp)
	{
		res = tmp;
		rght = i;
		lft = i - tmp + 1;
	}
}

void sub1()
{
	int tmp = 0;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '0')
		{
			minimize(tmp, i);
			tmp = 0;
		}
		else tmp++;
	}
	cout << lft << " " << rght;
}

void sub2()
{
	unordered_map<int, int> pre;
	int tmp0 = 0;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '0')
		{
			tmp0++;
			pre[tmp0] = i + 1;				
		}
		int hoicham = tmp0 - k;
		if(hoicham <= 0) minimize(i + 1, i + 1);
		else minimize(i + 1 - pre[hoicham] , i + 1);
	}
	cout << lft << " " << rght << " " << res;
}

void sub3()
{
	for(auto x: a)
	{
		
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j++)
		{
			
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen(NAME".inp", "r", stdin);
	freopen(NAME".out", "w", stdout);
	
	cin >> n >> m >> k;
	cin >> s;
	for(int i = 1; i <= m; i++) cin >> a[i].fi >> a[i].se;
	if(m == 0 && k == 0) sub1();
	else if(m == 0) sub2();
	else if(n <= 2000) sub3();

//	Times;
}

/*  	                                   __      NaTyn <3
		                               _.-~  )
		                    _..--~~~~,'   ,-/     _
		                 .-'. . . .'   ,-','    ,' )
		               ,'. . . _   ,--~,-'__..-'  ,'
		             ,'. . .  (@)' ---~~~~      ,'
		            /. . . . '~~             ,-'
		           /. . . . .             ,-'
		          ; . . . .  - .        ,'
		         : . . . .       _     /
		        . . . . .          `-.:
		       . . . ./  - .          )
		      .  . . |  _____..---.._/ _______________
		~---~~~~----~~~~             ~~
*/

