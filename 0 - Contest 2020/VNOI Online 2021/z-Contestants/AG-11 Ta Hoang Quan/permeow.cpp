#include<bits/stdc++.h>
using namespace std;

#define forr(_a, _b, _c) for(_a = _b; _a <= _c; ++_a)
#define ford(_a, _b, _c) for(_a = _b; _a >= _c; --_a)
#define file "permeow"
typedef long long ll;
const ll mo = ll(1e9) + 7;
int i, a[200001], b[200001], dd[200001], vt, j;
ll o, n;
bool tf;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	freopen(file".inp","r",stdin); freopen(file".out","w",stdout);

	cin >> n;
	forr(i,1,n) cin >> a[i];
	forr(i,1,n) cin >> b[i];
	tf = true;
	forr(i,1,n)
		if(a[i] != b[i]) {
			tf = false;
			break;
		}
	if(tf) {
		forr(i,1,n) {
			forr(j,1,n)
				if(a[j] == i) {
					vt = j;
					break;
				}
			ford(j,vt,i + 1) {
				swap(a[j],a[j - 1]);
				++o;
			}
		}
		cout << o;
	} else {
		tf = true;
		forr(i,1,n)
			if(a[i] != i || b[i] != n - i + 1) {
				tf = false;
				break;
			}
		if(tf) {
			o = 1;
			forr(i,2,n) o = (o * i) % mo;
			cout << (o * ((n * (n - 1)) / 4)) % mo;
		} else cout << n;
	}

	return 0;
}