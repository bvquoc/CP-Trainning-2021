#include <bits/stdc++.h>
using namespace std;

#define NAME "COOLMAC"
#define N 100000
#define Times cout<<"\nTime: "<<clock()/(double)1000<<" sec"
#define fi first
#define se second
#define MASK(x) (1 << (x))
#define BIT(x, i) (((x) >> i) & 1)

int n, m, t[N], res = 1e9;
pair<int, int> a[N], fen[N];

void sub1()
{
	int tmp = 1e9, lim = MASK(m), check = MASK(n) - 1;
	for(int j = 1; j <= n; j++) tmp = min(tmp, t[j]);
	for(int i = 1; i < lim; i++)
	{
		vector<int> st, en;
		int l = 1e9, r = -1;
		
		for(int j = 0; j < m; j++)
			if(BIT(i, j))
			{
				st.push_back(a[j+1].se);
				en.push_back(a[j+1].fi);
			}
		
		sort(en.begin(), en.end());
		sort(st.begin(), st.end());

		l = st.front();
		r = en.back();
						
		if(r < 100000) continue;
		if(l > tmp) continue;
		
		bool ok = 0;
		if(st.size() > 1)
			for(int j = 1; j < en.size(); j++) 
				if(st[j] >= en[j-1])
				{
					ok = 1;
					break;
				}
		if(ok) continue;
		res = min(__builtin_popcount(i), res);
	}
	
	if(res == 1e9) cout << -1; else cout << res;	
}

void update(int pos, pair<int, int> value)
{
	for(int i = pos; i <= N; i += i & -i)
		if(fen[i].first > value.first) fen[i] = value;
}

pair<int, int> getMin(int pos)
{
	pair<int, int> ans = {1e9, 0};
	for(int i = pos; i; i -= i & -i)
		if(ans.first > fen[i].first) ans = fen[i];
	return ans;
}

int Find(vector<int> p, int value)
{
	for(int i = 0; i < p.size(); i++)
		if(p[i] <= value)
		{
			cout << i << " " << p[i] << " " << value << endl;
			return i;
		}
	return -1;
}

void sub2()
{
	res = 1;
	for(int i = 1; i <= N; i++) fen[i] = {0x3f3f3f3f3f3f, 0};
	vector<int> en;
	int tmp = 1e9;
	for(int j = 1; j <= n; j++) tmp = min(tmp, t[j]);
	sort(a + 1, a + 1 + m);
	reverse(a + 1, a + 1 + m);
	
	for(int i = 1; i <= m; i++)
		update(i, {a[i].se, i}), en.push_back(a[i].fi);

	for(int i = 0; i < m; i++) cout << en[i] << " ";

	if(en[0] < 100000)
	{
		cout << "-1";
		return;
	}
	cout << "--" << endl;
	int k = a[1].se;
	while(k > tmp)
	{
		res++;
		int pos = Find(en, k);
		cout << pos << " " << res << endl;
		cout << getMin(pos).fi << " " << getMin(pos).se;
		k = getMin(pos).fi;
	}	
	cout << endl << res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen(NAME".inp", "r", stdin);
	freopen(NAME".out", "w", stdout);
	
	cin >> m;
	for(int i = 1; i <= m; i++) cin >> a[i].se >> a[i].fi;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> t[i];
	if(n <= 8 && m <= 16) sub1();
	else cout << -1;
////	else sub2();
//	sub2();
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

