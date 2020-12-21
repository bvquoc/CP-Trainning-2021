///link:
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define mt make_tuple
#define all(x) x.begin(), x.end()
#define ll long long
#define cbit(mask) (__builtin_popcount(mask))
#define onbit(mask, k) (mask | (1 << k))
const int maxn = 1 + 1e5;
const ll mod = 1e9 + 7;
const ll inf = (1ll << 60);

int n, m, k, l;
int watermelon[maxn][6];
vector <pair <int, ll> > g[maxn];
ll d[maxn][(1 << 6)];
ll ans = inf;

int main()
{
	#define Task "dhaka"
	if (fopen(Task".inp", "r"))
	freopen(Task".inp", "r", stdin), freopen(Task".out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();

	cin >> n >> m >> k >> l;
  for (int i = 1; i <= n; ++i) {
		int sl; cin >> sl;
    for (int j = 0; j < sl; ++j) {
			int type; cin >> type;
			--type;
      watermelon[i][type] = 1;
    }
  }
	for (int i = 0; i < m; ++i) {
		int u, v;
		ll l;
		cin >> u >> v >> l;
		g[u].push_back(mp(v, l));
		g[v].push_back(mp(u, l));
	}

	priority_queue <tuple <ll, int, int>, vector <tuple <ll, int, int> >, greater <tuple <ll, int, int> > > q;

	for (int i = 1; i <= n; ++i) {
		for (int mask = 0; mask < (1 << k); ++mask) {
			d[i][mask] = inf;
		}
	}

	int beg = 0;
  for (int i = 0; i < k; ++i) {
    if (watermelon[1][i]) {
			beg = onbit(beg, i);
    }
  }

  q.push(mt(0, beg, 1));

  while (!q.empty()) {
		int mask, u;
		ll du;
		tie(du, mask, u) = q.top();
		q.pop();
    if (d[u][mask] < du) continue;
    for (auto id : g[u]) {
			int v = id.first, l = id.second;
			int _mask = mask;
      for (int i = 0; i < k; ++i) {
        if (watermelon[v][i]) {
					_mask = onbit(_mask, i);
        }
      }
      if (d[v][_mask] > du + l) {
        d[v][_mask] = du + l;
        q.push(mt(du + l, _mask, v));
      }
    }
  }

  for (int i = 0; i < (1 << k); ++i) {
		if (cbit(i) >= l) {
      ans = min (ans, d[n][i]);
		}
  }

  if (ans == inf) cout << -1 << '\n';
  else cout << ans << '\n';

   return 0;
}
