/*input
13 219 292
796 798 798 797 328 263 148 931 92 578 262 798 796


5 3 2
5 17 13 5 6


3 1 4
4 2 3
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define mp make_pair
#define fi first
#define se second
#define __builtin_popcount __builtin_popcountll
#define loop(i,l,r) for(int i=(l); i<=(r); i++)
#define rloop(i,l,r) for(int i=(l); i>=(r); i--)
#define bit(x,y) ((x>>y)&1LL)
const int N = 1e6 + 5;
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
	return os << '(' << a.first << ", " << a.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
	os << '[';
	for (unsigned int i = 0; i < a.size(); i++)
		os << a[i] << (i < a.size() - 1 ? ", " : "");
	os << ']';
	return os;
}
#define ll long long
int n, A, B;
vector<ll> a(N);
vector<ll> cost(N);

vector<ll> fact(ll X) {
	vector<ll> ret;
	for (ll i = 2; i * i <= X; i++) {
		if (X % i == 0) {
			while (X % i == 0) {
				X /= i;
			}
			ret.push_back(i);
		}
	}
	if (X > 1) ret.push_back(X);
	return ret;
}

pair<ll, bool> findMax(int l, int r) {
	ll sum = 0; bool fullArray = true;
	ll ret = -1e18;
	loop(i, l, r) {
		sum += cost[i];
		if (sum < 0) {
			sum = 0;
			fullArray = false;
		}
		ret = max(ret, sum);
	}
	return mp(ret, fullArray);
}

long long solve(long long div) {
	int first = n + 1, last = -1;
	long long oriCost = 0;
	loop(i, 1, n) {
		long long t = a[i] % div;
		if (t == div - 1 || t == 0 || t == 1) {
			cost[i] = (t == 0 ? 0 : A);
		}
		else {
			first = min(first, i);
			last = max(last, i);
			cost[i] = B;
		}
	}
	oriCost = accumulate(cost.begin() + 1, cost.begin() + n + 1, 0LL);
	loop(i, 1, n) cost[i] = cost[i] - B;
	if (first == n + 1) {
		auto all = findMax(1, n);
		if (all.se == true) {
			auto le = findMax(2, n);
			auto ri = findMax(1, n - 1);
			if (le.fi > ri.fi) all = le;
			else all = ri;
		}
		long long ret = oriCost - all.fi;
		return ret;
	}
	else {
		long long le = -1e18, ri = -1e18;
		long long sum = 0;
		rloop(i, first, 1) {
			sum += cost[i];
			le = max(le, sum);
		}
		sum = 0;
		loop(i, last, n) {
			sum += cost[i];
			ri = max(ri, sum);
		}
		long long ret = oriCost - le - ri;
		loop(i, first + 1, last - 1) ret -= cost[i];
		return ret;
	}
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("hsgs.inp", "r", stdin);
	freopen("hsgs.out", "w", stdout);
	int T; cin >> T;
	cin >> n >> B >> A;
	loop(i, 1, n) cin >> a[i];
	vector<ll> allDivisor;
	loop(i, -1, 1) {
		auto rec = fact(a[1] + i);
		allDivisor.insert(allDivisor.end(), rec.begin(), rec.end());
		rec = fact(a[n] + i);
		allDivisor.insert(allDivisor.end(), rec.begin(), rec.end());
	}
	sort(allDivisor.begin(), allDivisor.end()); allDivisor.resize(distance(allDivisor.begin(), unique(allDivisor.begin(), allDivisor.end())));
	long long ans = 1e18;
	for (auto it : allDivisor) {
		ans = min(ans, solve(it));
	}
	cout << ans << endl;
}
