///link:
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define mt make_tuple
#define all(x) x.begin(), x.end()
#define ll long long
const int maxn = 1 + 1e6;
const ll mod = 1e9 + 7;
const int inf = (1 << 30);

int n, m;
pair <int, int> a[maxn];
int mi = inf, ma = 0;
int top;

int main()
{
	#define Task "coolmac"
	if (fopen(Task".inp", "r"))
	freopen(Task".inp", "r", stdin), freopen(Task".out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();

	cin >> m;
	for (int i = 0; i < m; ++i) {
    cin >> a[i].first >> a[i].second;
    ma = max (a[i].second, ma);
	}

	if (ma < int(1e5)) {
		cout << - 1 << '\n';
		return 0;
	}

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int u; cin >> u;
    mi = min (mi, u);
	}

	sort (a, a + m);

  pair <int, int> q[maxn];
  top = 0;
  q[0] = mp(-1, mi);
	++top;

  for (int i = 0; i < m; ++i) {
    while (top >= 2 && a[i].first <= q[top - 2].second&& a[i].second >= q[top - 1].second) {
			--top;
    }
    if (a[i].first <= q[top - 1].second) {
			q[top] = mp(a[i].first, a[i].second);
			++top;
    }
  }

  if (q[top - 1].second < int(1e5)) cout << -1 << '\n';
  else cout << top - 1 << '\n';

   return 0;
}
