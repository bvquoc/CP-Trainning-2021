#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define REP(i, n) for(int i=0, _n=(n); i<_n; i++)
#define ALL(v) (v).begin(), (v).end()
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define endl '\n'
#define int long long
using namespace std;

template<class T> T Abs(const T &x) { return (x < 0 ? -x : x); }
template<class X, class Y>
bool minimize(X &x, const Y &y) {
	X eps = 1e-9;
	if (x > y + eps) {
		x = y;
		return true;
	} else return false;
}
template<class X, class Y>
bool maximize(X &x, const Y &y) {
	X eps = 1e-9;
	if (x + eps < y) {
		x = y;
		return true;
	} else return false;
}

const int minN = 1e5 + 500;
const int INF = 1e15;

const int maxK = 100;
int numK = 0, fibo[maxK];

void generate_fibo() {
	fibo[1] = fibo[2] = 1;
	for (int k = 3; k < maxK; k++) {
		fibo[k] = fibo[k - 1] + fibo[k - 2];
		if (fibo[k] > INF) break;
		numK = k;
	}	
}

int cnt[minN], sum[minN][maxK];
void prepare() {
	cnt[0] = 0;
	int cur = 0;
	for (int i = 1; i < minN; i++) {
		cnt[i] = i;
		for (int k = 1; k <= numK and fibo[k] <= i; k++)
			minimize(cnt[i], cnt[i - fibo[k]] + 1);
		maximize(cur, cnt[i]);
		sum[i][cnt[i]] += cnt[i];
	}
	for (int i = 1; i < minN; i++)
		for (int k = 0; k <= cur; k++) sum[i][k] += sum[i - 1][k];
}

signed main() {
	freopen("CANDIES.INP","r",stdin);
	freopen("CANDIES.OUT","w",stdout);
	generate_fibo();
	prepare();
	int nTests; cin >> nTests;
	for (int n, k; nTests --> 0; ) {
		cin >> n >> k;
		if (max(n, k) < minN) {
			int answer = 0;
			for (int _k = k; _k < maxK; _k++) answer += sum[n][_k];
			cout << answer << endl;
		}
	}
}