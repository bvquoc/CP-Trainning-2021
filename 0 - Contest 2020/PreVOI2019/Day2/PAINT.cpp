#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
vector <int> a[27];
int n=0, id['z'+1];
vector <char> res;
int32_t main() {
	FastIO;
	freopen("PAINT.INP","r",stdin);
	freopen("PAINT.OUT","w",stdout);
	for (char ch='a';ch<='z';ch++) id[ch]=ch-'a'+1;
	int q; cin>>q;
	char x,y;
	while (q--) {
		int type; cin>>type;
		if (type==1) {
			cin>>x;
			a[id[x]].push_back(++n);
			continue;
		}
		cin>>x>>y;
		if (x==y) continue;
		if (a[id[x]].size()>a[id[y]].size()) {
			while (!a[id[y]].empty()) {
				a[id[x]].push_back(a[id[y]].back());
				a[id[y]].pop_back();
			}
			swap(id[x],id[y]);
		} else {
			while (!a[id[x]].empty()) {
				a[id[y]].push_back(a[id[x]].back());
				a[id[x]].pop_back();
			}
		}
	}
	res.assign(n,' ');
	for (char color='a';color<='z';color++) 
		for (int x:a[id[color]]) res[x-1]=color;
	for (char x:res) cout<<x;
	return 0;
}