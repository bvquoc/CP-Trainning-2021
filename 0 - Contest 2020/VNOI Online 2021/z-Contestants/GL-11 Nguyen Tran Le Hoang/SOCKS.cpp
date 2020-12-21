#include <bits/stdc++.h>
using namespace std;

#define NAME "SOCKS"
#define N 100000
#define Times cout<<"\nTime: "<<clock()/(double)1000<<" sec"

int n, q, cnt;
int a[N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen(NAME".inp", "r", stdin);
	freopen(NAME".out", "w", stdout);
	
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		cnt += a[i];
	}
	for(int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
	}
	if(cnt < 2) cout << 0 << "\n"; else cout << 1 << "\n";	
	while(q--)
	{
		int i; cin >> i;
		cnt -= a[i];
		a[i] = 1 - a[i];
		cnt += a[i];
		if(cnt < 2) cout << 0 << "\n"; else cout << 1 << "\n";
	}
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

