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
#define oo 1000000007
#define maxN 100008
#define sz(a) (int)a.size()
#define fast ios::sync_with_stdio(false); cin.tie(0)

using namespace std; 

int tt[maxN], n, deg[maxN], q, p[maxN], dem[4], visited[maxN];
vi ke[maxN];

void solve1() {
	int cnt = 0;
	fto(i, 1, n) {
		cnt += tt[i];
	}
	fto(i, 1, q) {
		int u; cin >> u;
		cnt += (tt[u] == 1)?-1:1;
		tt[u] = 1-tt[u];
		cout << ((cnt>1)? 1: 0) << '\n';
	}
}

void dfs(int u, int k) {
	visited[u] = 1;
	if (k != 0) p[u] = k;
	fto(i, 0, sz(ke[u])-1) {
		int v = ke[u][i];
		if (!visited[v]) {
			if (k == 0) dfs(v, i+1);
			else dfs(v, k);
		}
	}
}

void solve2() {
	int vt;
	fto(i, 1, n) {
		if (deg[i] == 3) vt = i;
	}
	dfs(vt, 0);
	dem[1] = dem[2] = dem[3] = 0;
	int cnt = 0;
	fto(i, 1, n) { 
		dem[p[i]] += tt[i];
		cnt += tt[i];
	}
	fto(i, 1, q) {
		int u; cin >> u;
		cnt += (tt[u] == 1)?-1:1;
		dem[p[u]] += (tt[u] == 1)?-1:1;
		tt[u] = 1-tt[u];
		int ans = (cnt > 1)?1:0;
		ans += (dem[1] > 0 && dem[2] > 0 && dem[3] > 0);
		cout << ans << '\n';
	}
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("socks.inp", "r", stdin);
    freopen("socks.out", "w", stdout);
    #endif
  
  	fast;
    cin >> n >> q;;
    fto(i, 1, n) {
    	cin >> tt[i]; 
    }

    fto(i, 1, n-1) {
    	int u, v;
    	cin >> u >> v;
    	ke[u].pb(v);
    	ke[v].pb(u);
    	++deg[u];
    	++deg[v];
    }

    int tt1 = 1;
    fto(i, 1, n) if (deg[i] > 2) tt1 = 0;
    if (tt1 == 1) {
    	solve1();
    }
    int tt2 = 1;
    int cnt = 0;
    fto(i, 1, n) {
    	if (deg[i] == 3) ++cnt;
    	else if (deg[i] > 2) tt2 = 0;
    }
    if (tt2 == 1 && cnt == 1) solve2();

    

    return 0;
}
