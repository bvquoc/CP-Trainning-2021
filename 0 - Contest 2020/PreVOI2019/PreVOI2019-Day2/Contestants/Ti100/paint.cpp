#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 4;
vector <int> pos[30];
int res[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("paint.inp", "r", stdin);
	freopen("paint.out", "w", stdout);
	int n, idx = 0;
	cin >> n;
	while(n--) {
		char typ, A, B;
		cin >> typ >> A;
		if(typ == '1') {
			pos[A - 'a'].push_back(++idx);
			continue;
		}

		cin >> B;
		int u = A - 'a', v = B - 'a';
		if(u == v) continue;
		if((int)pos[u].size() > (int)pos[v].size()) swap(pos[u], pos[v]);
		for(auto x : pos[u]) {
			pos[v].push_back(x);
		}
		pos[u].clear();
	}

	for(int i = 0; i < 26; i++) {
		for(auto x : pos[i]) {
			res[x] = i;
		}
	}
	for(int i = 1; i <= idx; i++) {
		cout << (char)(res[i] + 'a');
	}
}