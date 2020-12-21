#include <bits/stdc++.h>
#define long long long
#define FOR(i, st, en) for (int i = st, _en = (en); i <= _en; ++i)
#define REP(i, en) for (int i = 0, _en = (en); i < _en; ++i)
#define FORD(i, st, en) for (int i = st, _en = (en); i >= _en; --i)
#define FORE(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define MASK(n) (1LL << (n))
#define BIT(x, i) (((x)>>(i)) & 1LL)
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define all(x) (x).begin(), (x).end()
#define taskname "GIFT11"
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
const long mod = 998244353;
#define maxn 2005

int n;
int a[maxn];
long dp[105][11][105];
long save[10] = {0, 0, 0, 2, 8, 0, 0, 576, 4608, 31680};
// ----------------------------------------------------------------------------------
void sub1() {
    vector<string> st(n+1);
    FOR(i, 1, n) {
        while (a[i]) st[i].push_back((a[i]%10)+48), a[i] /= 10;
        reverse(all(st[i]));
    }
    vector<int> gen(n+1, 0); iota(all(gen), 0);
    int res = 0;
    do {
        string nw = "#";
        FOR(i, 1, n) nw += st[gen[i]];

        int odd = 0, even = 0;
        FOR(i, 1, nw.size()-1)
            if (i%2 == 1) odd += (nw[i] - '0');
            else even += (nw[i] - '0');

        if ((odd-even+11)%11 == 0) res++;
    } while (next_permutation(gen.begin()+1, gen.end()));
    printf("%d\n", res);
}

long cal(int i, int mem, int odd) {
	if (i > n) return mem == 0;
	long &res = dp[i][mem][odd];
	if (res > -1) return res;

	res = 0;
	int a = i/10, b = i%10;
	res = (res + odd*cal(i+1, (mem+a-b+11)%11, odd+1) + mod)%mod;
	res = (res + (i-odd)*cal(i+1, (mem+b-a+11)%11, odd) + mod)%mod;

	return res%mod;
}

void bite() {
	vector<int> gen(10, 0); iota(all(gen), 0);
	memset(dp, -1, sizeof dp);
	long res = 0;
	do {
		int odd = 0, even = 0;
		FOR(i, 1, 9) {
			if (i%2 == 1) odd += gen[i];
			else even += gen[i];
		}
		int mem = (odd - even + 11)%11;

		if (n < 10) res += (mem == 0);
		else res = (res + cal(10, mem, 5) + mod)%mod;
	} while (next_permutation(gen.begin()+1, gen.end()));

	cout << res << endl;
}

void test_case() {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
    if (n <= 10) {sub1(); return;}

    bool check = true;
    sort(a+1, a+n+1);
    FOR(i, 1, n) if (i != a[i]) check = false;
    if (check) {bite(); return;}
}

int main() {
	// fastio;
	file;

	int test; scanf("%d", &test);
	while (test--) test_case();
	return 0;
}

/*
(\_/)
( •_•)
/>(:3)<
Mlem Mlem */

