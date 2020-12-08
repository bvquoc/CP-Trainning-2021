#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 5;
int st[4 * N], op[4 * N], ed[4 * N];
typedef pair <int, int> pi;
string s[1003];
int m;
void build(int id, int l, int r) {
	if(l == r) {
		op[id] = (s[0][l - 1] == '(');
		ed[id] = (s[0][l - 1] == ')');
		st[id] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);
	int p = min(op[id << 1], ed[id << 1 | 1]);
	st[id] = st[id << 1] + st[id << 1 | 1] + p;
	op[id] = op[id << 1] + op[id << 1 | 1] - p;
	ed[id] = ed[id << 1] + ed[id << 1 | 1] - p;
}
void upd(int id, int l, int r, int u) {
	if(l > u || r < u) return;
	if(l == r) {
		op[id] ^= 1;
		ed[id] ^= 1;
		return;
	}
	int mid = (l + r) >> 1;
	upd(id << 1, l, mid, u);
	upd(id << 1 | 1, mid + 1, r, u);
	int p = min(op[id << 1], ed[id << 1 | 1]);
	st[id] = st[id << 1] + st[id << 1 | 1] + p;
	op[id] = op[id << 1] + op[id << 1 | 1] - p;
	ed[id] = ed[id << 1] + ed[id << 1 | 1] - p;
}

pair <int, pi> get(int id, int l, int r, int u, int v) {
	if(l > v || r < u) return {0, {0, 0}};
	if(u <= l && r <= v) return {st[id], {op[id], ed[id]}};
	int mid = (l + r) >> 1;
	pair <int, pi> lef = get(id << 1, l, mid, u, v);
	pair <int, pi> rig = get(id << 1 | 1, mid + 1, r, u, v);
	int p = min(lef.se.fi, rig.se.se);
	int A = lef.fi + rig.fi + p;
	int B = lef.se.fi + rig.se.fi - p;
	int C = lef.se.se + rig.se.se - p;
	return {A, {B, C}};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("fixstr.inp", "r", stdin);
	freopen("fixstr.out", "w", stdout);
	cin >> s[0] >> m;
	int n = s[0].length();
	if(n <= 1000 && m <= 1000) {
		for(int i = 1; i <= m; i++) {
			char typ;
			int x, y;
			cin >> typ >> x;
			if(typ == 'C') {
				s[i] = s[i - 1];
				if(s[i][x - 1] == '(') s[i][x - 1] = ')';
				else s[i][x - 1] = '(';
			}

			else if(typ == 'U') {
				s[i] = s[x - 1];
			}

			else if(typ == 'Q') {
				s[i] = s[i - 1];
				// cout << s[i] << '\n';
				cin >> y;
				x-- , y--;
				stack <int> v;
				for(int j = x; j <= y; j++) {
					if(s[i][j] == ')') {
						if(v.size() == 0) {
							v.push(1);
							continue;
						}
						int u = v.top();
						if(u == 0) v.pop();
						else v.push(1);
					}
					else {
						v.push(0);
					}
				}
				cout << (int)v.size() << '\n';
			}
		}
		return 0;
	}

	build(1, 1, n);
	// cout << st[1] << '\n';
	while(m--) {
		char typ;
		int x, y;
		cin >> typ;
		scanf("%d", &x);
		if(typ == 'C') {
			upd(1, 1, n, x);
		}
		else if(typ == 'Q') {
			scanf("%d", &y);
			int ans = get(1, 1, n, x, y).fi;
			cout << y - x + 1 - ans * 2 << '\n';
		}
	}
}