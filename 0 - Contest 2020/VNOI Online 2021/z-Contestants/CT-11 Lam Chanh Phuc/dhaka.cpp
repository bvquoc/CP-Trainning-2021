/**
      11  11   000000   111111
      11 11       00    111111
      1111       00       11
      11 11     00        11
      11  11   000000     11     **/


#include<bits/stdc++.h>

#define bug(a) cout<< #a << ": " << a << endl;
#define bug2(a, b) cout<< #a << ": " << a << ", " << #b << ": " << b << endl;
#define bugarr(a, i, j) cout<< #a << "{" << i << "..." << j << "}: "; fto(k, i, j-1) cout<< a[k] << ", "; cout<< a[j] << endl;
#define fto(i, a, b) for(int i = a; i <= b; ++i)
#define fdto(i, a, b) for(int i = a; i >= b; --i)
#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d %d", &a, &b)
#define pril(a) printf("%d\n", a)
#define pris(a) printf("%d ", a)
#define ll long long
#define ii pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vii vector<ii>
#define all(x) (x).begin(), (x).end()
#define oo 10000000000000007LL
#define maxN 100008
#define sz(a) (int)a.size()
#define fast ios::sync_with_stdio(false); cin.tie(0)

using namespace std; 

ll d[maxN][(1<<6)-1];
int n, m, l, k, melon[maxN];
vii ke[maxN];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("dhaka.inp", "r", stdin);
    freopen("dhaka.out", "w", stdout);
    #endif

    fast;
    cin >> n >> m >> l >> k;

    fto(i, 1, n) {
    	int x;
    	cin >> x;
    	fto(j, 1, x) {
    		int sth;
    		cin >> sth;
    		melon[i] = (melon[i]|(1<<(sth-1)));
    	}
    }

    fto(i, 1, m) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	ke[u].pb(mp(v, w));
    	ke[v].pb(mp(u, w));
    }

    fto(i, 1, n) {
    	fto(j, 0, (1<<k)-1) {
    		d[i][j] = oo;
    	}
    }

    priority_queue<pair<ll, ii> > q;
    d[1][melon[1]] = 0;
    q.push(mp(0, mp(1, melon[1])));

    while(!q.empty()) {
    	pair<ll, ii> t = q.top(); q.pop();
    	int u = t.ss.ff;
    	int slmelon = t.ss.ss;
    	if (d[u][slmelon] < -t.ff) continue;
    	fto(i, 0, sz(ke[u])-1) {
    		int v = ke[u][i].ff;
    		ll cost = ke[u][i].ss;
    		if (d[v][slmelon|melon[v]] > d[u][slmelon]+cost) {
    			d[v][slmelon|melon[v]] = d[u][slmelon]+cost;
    			q.push(mp(-d[v][slmelon|melon[v]], mp(v, slmelon|melon[v])));
    		}
    	}
    }

    ll ans = LLONG_MAX;
    fto(i, 0, (1<<k)-1) {
    	int cnt = 0;
    	int j = i;
    	while(j > 0) {
    		++cnt;
    		j = j & (j-1);
    	}
    	if (cnt >= l) {
    		ans = min(ans, d[n][i]);
    	}
    }

    cout << ((ans == oo)? -1 : ans) << '\n';
  
    return 0;
}
