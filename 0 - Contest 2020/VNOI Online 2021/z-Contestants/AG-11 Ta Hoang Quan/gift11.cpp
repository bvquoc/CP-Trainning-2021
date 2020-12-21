#include<bits/stdc++.h>
using namespace std;

#define forr(_a, _b, _c) for(_a = _b; _a <= _c; ++_a)
#define ford(_a, _b, _c) for(_a = _b; _a >= _c; --_a)
#define forf(_a, _b, _c) for(_a = _b; _a < _c; ++_a)
#define file "gift11"
typedef long long ll;
const ll mo = 998244353;
int t, a[2001][12], n, ht, sc, sl, j, b[2001], c[2001];
ll i, o;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	freopen(file".inp","r",stdin); freopen(file".out","w",stdout);

	cin >> t;
	while(t-- > 0) {
		cin >> n;
		memset(a,0,sizeof(a));
		forr(i,1,n) {
			cin >> ht;
			a[i][11] = ht;
			while(a[i][11] > 0) {
				a[i][++a[i][0]] = a[i][11] % 10;
				a[i][11] /= 10;
			}
			for(j = 1; j <= a[i][0]; j += 2) b[i] += a[i][j];
			for(j = 2; j <= a[i][0]; j += 2) c[i] += a[i][j];
			b[i] %= 11;
			c[i] %= 11;
		}
		o = 0;
		if(n <= 10) {
			vector<int> b(n);
			forf(i,0,n) b[i] = i + 1;
			do {
				ht = sc = sl = 0;
				forf(i,0,n) ford(j,a[b[i]][0],1)
					if(++ht & 1) sl += a[b[i]][j];
					else sc += a[b[i]][j];
				if(abs(sl - sc) % 11 == 0) o = (o + 1) % 998244353;
			} while(next_permutation(b.begin(),b.end()));
		} else {
			ht = sc = sl = 0;
			forr(i,1,n) ford(j,a[i][0],1)
				if(++ht & 1) sl += a[i][j];
				else sc += a[i][j];
			if(abs(sl - sc) % 11 == 0) {
				o = 1;
				forr(i,2,n) o = (o * i) % mo;
			}
		}
		cout << o << "\n";
	}

	return 0;
}