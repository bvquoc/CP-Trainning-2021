#include<bits/stdc++.h>
using namespace std;

#define forr(_a, _b, _c) for(_a = _b; _a <= _c; ++_a)
#define file "decor"
typedef long long ll;

int n, m, k, i, x, y, o, l, r, dem, tx, ty;
string s;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	freopen(file".inp","r",stdin); freopen(file".out","w",stdout);

	cin >> n >> m >> k >> s;
	s = ' ' + s + ' ';
	while(m-- > 0) cin >> x >> y;
	x = 1; 
	y = 1;
	while(x <= n && y <= n + 1) {
		if(x > y) y = x;
		while((s[y] == '1' || k) && y <= n) {
			if(s[y] == '0') --k;
			++y;
			++dem;
			if(y - x + 1 > o) {
				o = y - x;
				l = x;
				r = y;
			}
		}
		if(x < y && s[x] == '0') ++k;
		++x;
		if(x == tx && y == ty) break;
		else {
			tx = x;
			ty = y;
		}
	}
	if(!l) cout << -1;
	else cout << l << " " << r - 1;

	return 0;
}