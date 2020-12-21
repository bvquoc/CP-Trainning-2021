#include<bits/stdc++.h>
#define ll long long
//<(")
using namespace std;

typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;

const ll siz = 5e5 + 10;
const ll mod = 998244353;
const ll base = 32;
const ll MAXX = 1e5;
const ll maa = 1e18;
const ll off = 300;

void con_meo_ngoo() {
    //khong lam gi ca
}

ll n, q;
bool col[siz];

vector<ll> graph[siz];
ll dist[siz];
ll h[siz];

ll cnt = 0;

void dfs(ll node, ll par, ll d = 0) {
	dist[node] = d;
	for (ll i = 0; i < (int)graph[node].size(); i++) {
		ll v = graph[node][i];
		if (v != par) {
			dfs(v, node, d + 1);
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("SOCKS.INP", "r", stdin);
    freopen("SOCKS.OUT", "w", stdout);
    con_meo_ngoo();
	cin >> n >> q;
	for (ll i = 1; i <= n; i++) {
		cin >> col[i];
	}
	ll sta = -1;
	bool check1 = true, check2 = false;
	for (ll i = 1; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (ll i = 1; i <= n; i++) {
		if (graph[i].size() == 1) {
			check2 = true;
			sta = i;
		}
		if (graph[i].size() > 2) {
			check1 = false;
		}
	}
	if (check1 && check2) {
		dfs(sta, sta);
		for (ll i = 1; i <= n; i++) {
			if (col[i]) {
				cnt++;
			}
		}
		cout << ((cnt > 1) ? 1 : 0) << '\n';
		for (ll i = 0; i < q; i++) {
			ll x;
			cin >> x;
			if (col[x]) {
				cnt--;
				col[x] = 0;
			}
			else {
				col[x] = 1;
				cnt++;
			}
			cout << ((cnt > 1) ? 1 : 0) << '\n';
		}
		return 0;
	}
    return 0;
}
