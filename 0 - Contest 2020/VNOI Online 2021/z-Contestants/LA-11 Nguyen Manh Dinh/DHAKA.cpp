#include <bits/stdc++.h>
#define F first
#define S second
#define all(x) x.begin(), x.end()

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;

const ll N = 100004;
const ll mod = 50000;
const ll oo = 1e17+2;

ll n, m, k, l, s[N];
vector<ii> adj[N];
ll d_[(1<<5)][100000];
void sub4() {
	for(int i = 0; i < (1<<5); ++i)
		for(int j = 0; j <= n; ++j)
			d_[i][j] = oo;
	priority_queue<iii> pq;
	pq.push({{0, s[1]}, 1});
	d_[s[1]][1] = 0;
	while(pq.size()) {
		ll du = -pq.top().F.F;
		ll state = pq.top().F.S;
		ll u = pq.top().S;
		pq.pop();
		if (u == n && __builtin_popcount(state) >= l) {
			cout << du;
			return;
		}
		for(ii i : adj[u]) {
			ll v = i.F, w = i.S;
			ll _state = state|s[v];
			if (d_[_state][v] > d_[state][u] + w) {
				d_[_state][v] = d_[state][u] + w;
				pq.push({{-d_[_state][v], _state}, v});
			}
		}
	}
	cout << -1;
}

void sub2() {
	ll d[N];
	for(int i = 1; i <= n; ++i)
		d[i] = oo;
	priority_queue<ii> pq;
	pq.push({0, 1});
	while(pq.size()) {
		ll du = -pq.top().F, u = pq.top().S;
		pq.pop();
		if (du > d[u]) continue;
		if (u == n) {cout << du;return;}
		for(ii i : adj[u]) {
			ll v = i.F, w = i.S;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				pq.push({-d[v], v});
			}
		}
	}
	cout << -1;
}

void sub3() {
	ll d[N][2];
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= 1; ++i)
			d[i][j] = oo;
	for(int i = 1; i <= n; ++i)
		s[i] = s[i] != 0;
	priority_queue<iii> pq;
	pq.push({{0, s[1]}, 1});
	while(pq.size()) {
		ll du = -pq.top().F.F;
		ll state = pq.top().F.S;
		ll u = pq.top().S;
		pq.pop();
		if (du > d[state][u]) continue;
		if (u == n && state) {cout << du;return;}
		for(ii i : adj[u]) {
			ll v = i.F, w = i.S;
			ll _state = state|s[v];
			if (d[_state][v] > d[state][u] + w) {
				d[_state][v] = d[state][u] + w;
				pq.push({{-d[_state][v], _state}, v});
			}
		}
	}
	cout << -1;
}

void solve() {
	cin >> n >> m >> k >> l;
	for(int i = 1; i <= n; ++i) {
		ll sl; cin >> sl;
		s[i] = 0;
		while(sl--) {
			ll tmp; cin >> tmp;
			s[i] |= 1<<(tmp - 1);
		}
	}
	for(int i = 1; i <= m; ++i) {
		ll u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	if (l == 1) sub2();
	else if (k == 1) sub3();
	else sub4();
}

int main()
{
	freopen("DHAKA.inp", "r", stdin);
	freopen("DHAKA.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    solve();
    // cout << "\n\nTime: " << clock()/1000.0 << 's';
    return 0;
}