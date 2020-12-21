#include<bits/stdc++.h>
using namespace std;

#define forr(_a, _b, _c) for(_a = _b; _a <= _c; ++_a)
#define forf(_a, _b, _c) for(_a = _b; _a < _c; ++_a)
#define file "dhaka"
typedef long long ll;
const ll inf = ll(1e9) + 1;
#define fi first
#define se second
typedef pair<int,ll> pac;
typedef pair<ll,int> paa;
int n, m, k, l, s, i, x, y, j, sh[6];
ll z, b[11][11], d[100001], t, o = 1e18;
bool a[100001][6], dd[100001], tf;
vector<pac> adj[100001];
priority_queue< paa, vector<paa>, greater<paa> > pq;

void ql(int x) {
	int i;
	forr(i,1,k)
		if(a[x][i]) ++sh[i];
	dd[x] = true;
	bool chay = false;
	if(x != n)
		forr(i,1,n)
			if(!dd[i] && b[x][i] < 1000000001) {
				chay = true;
				t += b[x][i];
				ql(i);
				t -= b[x][i];
			}
	if(!chay && x == n) {
		int dem = 0;
		forr(i,1,k)
			if(sh[i]) ++dem;
		if(dem >= l) o = min(o,t);
	}
	dd[x] = false;
	forr(i,1,k)
		if(a[x][i]) --sh[i];
}

void solve1() {
	memset(b,inf,sizeof(b));
	forr(i,1,n) forf(j,0,adj[i].size()) {
		x = adj[i][j].fi;
		z = adj[i][j].se;
		b[i][x] = min(b[i][x],z);
		b[x][i] = b[i][x];
	}
	ql(1);
	if(o == 1e18) cout << -1;
	else cout << o;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	freopen(file".inp","r",stdin); freopen(file".out","w",stdout);

	cin >> n >> m >> k >> l;
	forr(i,1,n) {
		cin >> s;
		while(s-- > 0) {
			cin >> x;
			a[i][x] = true;
		}
	}
	while(m-- > 0) {
		cin >> x >> y >> z;
		adj[x].push_back(pac(y,z));
		adj[y].push_back(pac(x,z));
	}
	if(n <= 10) solve1();
	else {
		memset(d,inf,sizeof(d));
		pq.push(paa(0,1));
		d[1] = 0;
		while(!pq.empty()) {
			x = pq.top().se;
			dd[x] = true;
			pq.pop();
			forf(i,0,adj[x].size()) {
				y = adj[x][i].fi;
				z = adj[x][i].se;
				if(!dd[y] && d[x] + z < d[y]) {
					d[y] = d[x] + z;
					pq.push(paa(d[y],y));
				}
			}
			while(!pq.empty() && dd[pq.top().se]) pq.pop();
		}
		cout << d[n];
	}

	return 0;
}