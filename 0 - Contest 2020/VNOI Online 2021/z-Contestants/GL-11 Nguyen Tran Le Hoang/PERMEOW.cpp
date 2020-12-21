#include <bits/stdc++.h>
using namespace std;

#define NAME "PERMEOW"
#define N 100007
#define Times cout<<"\nTime: "<<clock()/(double)1000<<" sec"

int n, res = 0;
int pos[N];
vector<int> a, b;

void sub1()
{
	for(int i = 1; i < n; i++)
	{
		for(int j = n - 1; j >= i; j--)
		{
			if(a[j] > a[j+1])
			{
				swap(a[j+1], a[j]);
				res++;
			}
		}
	}
	cout << res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen(NAME".inp", "r", stdin);
	freopen(NAME".out", "w", stdout);

	cin >> n;
	a.push_back(0);
	for(int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		a.push_back(x);
	}
	for(int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		b.push_back(x);
	}
	sub1();

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

