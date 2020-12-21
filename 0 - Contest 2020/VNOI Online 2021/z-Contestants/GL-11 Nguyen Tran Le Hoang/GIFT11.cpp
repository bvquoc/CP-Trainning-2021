#include <bits/stdc++.h>
using namespace std;

#define NAME "GIFT11"
#define N 100000
#define Times cout<<"\nTime: "<<clock()/(double)1000<<" sec"

const int MOD = 998244353;
int n, a[N], res;
int factorial[N];

void pre()
{
	factorial[0] = 1;
	for(int i = 1; i <= N; i++) factorial[i] = (factorial[i - 1] * i) % MOD;
}

bool check(string x)
{
	int even = 0, odd = 0;
	for(int i = 1; i <= x.size(); i++)
	{
		if(i & 1) odd += x[i-1] - '0'; else even += x[i-1] - '0';
	}
	int tmp = odd - even;
	if(tmp % 11 == 0) return true; else return false;
}

void sub1()
{
	res = 0;
	vector<int> gen(n, 0); iota(gen.begin(), gen.end(), 1);
	do
	{
		string s;
		for(auto i: gen)
		{
			stringstream tmp;
			tmp << a[i];
			string p = tmp.str();
			s += p;
		}
		if(check(s)) res++;
	}
	while(next_permutation(gen.begin(), gen.end()));
	cout << res << "\n";
}

void sub2()
{
	string s;
	for(int i = 1; i <= n; i++)
	{
		stringstream tmp;
		tmp << a[i];
		string p = tmp.str();
		s += p;
	}
	if(check(s)) cout << factorial[n] << "\n"; else cout << "0" << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen(NAME".inp", "r", stdin);
	freopen(NAME".out", "w", stdout);
	
	pre();
	int _; cin >> _;
	int hoicham = 0;
	while(_--)
	{
		cin >> n;
		hoicham += n;
		bool ok2 = 1, ok3 = 1;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++)
		{
			stringstream tmp;
			tmp << a[i];
			string p = tmp.str();
			if(!(p.size() & 1)) ok3 = 0;
			if(p.size() & 1) ok2 = 0; 
		}
		if(n <= 8) sub1();
		else if(ok2) sub2();
//		if(ok3) sub3();
	}

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

