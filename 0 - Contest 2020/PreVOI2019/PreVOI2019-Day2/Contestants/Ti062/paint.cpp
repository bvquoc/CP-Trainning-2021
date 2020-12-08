#include<bits/stdc++.h>
#define qwer "paint"

using namespace std;

int main()
{
	if (fopen(qwer".inp","r")) freopen(qwer".inp","r",stdin),freopen(qwer".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> chot(n + 1);
	iota(chot.begin(),chot.end(),0);
	function<int(int)> find = [&](int u){return chot[u] == u ? u : chot[u] = find(chot[u]);};
	auto combine = [&](int u,int v)
	{
		u = find(u);v = find(v);
		if (u != v) chot[v] = u;
	};
	vector<int> control(26,0);
	vector<int> ans(n + 1);
	int cnt = 0;
	for (int i = 1;i <= n;++i) {
		int type;
		cin >> type;
		if (type == 1) {
			char ch;
			cin >> ch;
			int x = ch - 'a';
			++cnt;
			ans[cnt] = x;
			if (!control[x]) control[x] = cnt;
			else combine(control[x],cnt); 
		}
		else {
			char l,r;
			cin >> l >> r;
			if (!control[l-'a']) continue;
			if (!control[r-'a']) {
				control[r - 'a'] = control[l-'a'];
				ans[control[r - 'a']] = r - 'a';
			}
			else combine(control[r - 'a'],control[l - 'a']);
			control[l - 'a'] = 0;
		}
	}
	for (int i = 1;i <= cnt;++i) putchar(ans[find(i)] + 'a');
}
