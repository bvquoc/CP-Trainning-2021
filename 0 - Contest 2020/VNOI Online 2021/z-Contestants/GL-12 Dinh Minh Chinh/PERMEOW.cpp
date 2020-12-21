#include <bits/stdc++.h>
#define long long long
#define FOR(i, st, en) for (int i = st, _en = (en); i <= _en; ++i)
#define REP(i, en) for (int i = 0, _en = (en); i < _en; ++i)
#define FORD(i, st, en) for (int i = st, _en = (en); i >= _en; --i)
#define FORE(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define MASK(n) (1LL << (n))
#define BIT(x, i) (((x)>>(i)) & 1LL)
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define all(x) (x).begin(), (x).end()
#define taskname "PERMEOW"
#define file                              \
	freopen(taskname".INP", "r", stdin); \
	freopen(taskname".OUT", "w", stdout)
using namespace std;
template<class T> bool minimize(T& x, const T& y) {
	if (x > y) {x = y; return true;}
	return false;
}
template<class T> bool maximize(T& x, const T& y) {
	if (x < y) {x = y; return true;}
	return false;
}
// ----------------------------------------------------------------------------------
typedef pair<int, int> ii;
const int inf = 0x3f3f3f3f;
const long mod = 1e9+7;
#define maxn 20005

int n;
vector<int> a, b;
long bit[maxn];
// ----------------------------------------------------------------------------------
void update(int idx) {
    for (int i = idx; i > 0; i -= i&-i)
        ++bit[i];
}

long get(int idx) {
    long res = 0;
    for (int i = idx; i <= n; i += i&-i)
        res += bit[i];
    return res;
}

long cal() {
    FOR(i, 1, n) bit[i] = 0;
    long res = 0;
    FOR(i, 1, n) {
        res += get(a[i]);
        update(a[i]);
    }
    return res;
}

void test_case() {
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    if (n == 2) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        if (a != c) cout << 1 << endl;
        else cout << 0 << endl;
        return;
    }
    a = b = vector<int>(n+1, 0);
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];

    long res = 0;
    do {
        res += cal();
        res %= mod;
        bool OK = true;
        FOR(i, 1, n) if (a[i] != b[i]) OK = false;
        if (OK) break;
    } while (next_permutation(a.begin()+1, a.end()));
    cout << res << endl;
}

int main() {
	fastio;
	file;

	test_case();
	return 0;
}

/*
(\_/)
( •_•)
/>(:3)<
Mlem Mlem */

