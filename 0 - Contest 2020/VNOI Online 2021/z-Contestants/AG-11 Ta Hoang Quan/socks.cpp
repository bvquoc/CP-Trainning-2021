#include<bits/stdc++.h>
using namespace std;

#define forr(_a, _b, _c) for(_a = _b; _a <= _c; ++_a)
#define file "socks"
typedef long long ll;

int n, m, i, a[500001], dem;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	freopen(file".inp","r",stdin); freopen(file".out","w",stdout);

	cin >> n >> m;
	forr(i,1,n) {
		cin >> a[i];
		if(a[i]) ++dem;
	}
	int x, y;
	forr(i,1,n - 1) cin >> x >> y;
	if(dem > 1) cout << "1\n";
	else cout << "0\n";
	while(m-- > 0) {
		cin >> x;
		if(a[x]) {
			--dem;
			a[x] = 0;
		} else {
			++dem;
			a[x] = 1;
		}
		if(dem > 1) cout << "1\n";
		else cout << "0\n";
	}

	return 0;
}