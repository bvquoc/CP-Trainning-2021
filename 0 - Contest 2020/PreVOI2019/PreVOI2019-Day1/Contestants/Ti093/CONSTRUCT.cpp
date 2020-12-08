#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const int BIG = 1e9 + 555;
const int maxN = 1e6 + 55;

ll a[maxN];
int n, m;
vector<pair<ll, ll> > segTree;
vector<ll> lazy;

void sub1(){
	for(int id = 0; id < m; id++){
		int tp;	cin >> tp;
		if(tp == 1){
			int l, r;	ll k;	cin >> l >> r >> k;

			for(int i = l; i <= r; i++){
				a[i] += k;
			}
		} else {
			int l, r;	cin >> l >> r;
			ll lst = 0, cur = 0;
			for(int i = l; i <= r; i++){
				if(lst < a[i]){
					cur += (a[i] - lst);
				}
				lst = a[i];
			}
			cout << cur << '\n';
		}
	}
}

void buildTree(int id, int l, int r){
	if(l == r){
		segTree[id] = make_pair(max(a[l] - a[l - 1], 0LL), a[l]);
		return;
	}

	int mid = (l + r) / 2;
	buildTree(id * 2, l, mid);
	buildTree(id * 2 + 1, mid + 1, r);
	segTree[id].first = segTree[id * 2].first + segTree[id * 2 + 1].first;
	segTree[id].second = segTree[id * 2].second + segTree[id * 2 + 1].second;
}

void propagate(int id, int l, int r){
	if(lazy[id]){
		segTree[id].second += (r - l + 1) * lazy[id];
		if(l != r){
			lazy[id * 2] += lazy[id];
			lazy[id * 2 + 1] += lazy[id];
		}
		lazy[id] = 0;
	}
}

ll queryFirst(int id, int l, int r, int L, int R){
	propagate(id, l, r);
	if(L <= l && r <= R){
		return segTree[id].first;
	}

	if(r < L || l > R){
		return 0;
	}

	int mid = (l + r) / 2;
	return queryFirst(id * 2, l, mid, L, R) + queryFirst(id * 2 + 1, mid + 1, r, L, R);
}

ll querySecond(int id, int l, int r, int idx){
	propagate(id, l, r);
	if(l == idx && r == idx){
		return segTree[id].second;
	}

	if(r < idx || l > idx){
		return 0;
	}

	int mid = (l + r) / 2;
	return querySecond(id * 2, l, mid, idx) + querySecond(id * 2 + 1, mid + 1, r, idx);
}

void updFirst(int id, int l, int r, int idx, ll val){
	propagate(id, l, r);
	if(l == idx && r == idx){
		segTree[id].first = val;
		return;
	}

	if(r < idx || l > idx){
		return;
	}

	int mid = (l + r) / 2;
	updFirst(id * 2, l, mid, idx, val);
	updFirst(id * 2 + 1, mid + 1, r, idx, val);

	segTree[id].first = segTree[id * 2].first + segTree[id * 2 + 1].first;
	segTree[id].second = segTree[id * 2].second + segTree[id * 2 + 1].second;
}

void updSecond(int id, int l, int r, int L, int R, ll val){
	propagate(id, l, r);
	if(L <= l && r <= R){
		lazy[id] += val;
		propagate(id, l, r);
		return;
	}

	if(r < L || l > R){
		return;
	}

	int mid = (l + r) / 2;
	updSecond(id * 2, l, mid, L, R, val);
	updSecond(id * 2 + 1, mid + 1, r, L, R, val);

	segTree[id].first = segTree[id * 2].first + segTree[id * 2 + 1].first;
	segTree[id].second = segTree[id * 2].second + segTree[id * 2 + 1].second;
}

void sub2(){
	segTree.resize(4 * n + 5);
	lazy.resize(4 * n + 5);
	fill(segTree.begin(), segTree.end(), make_pair(0, 0));
	fill(lazy.begin(), lazy.end(), 0);
	buildTree(1, 1, n);
	
	//for(int i = 1; i <= n; i++){
	//	cerr << a[i] << ' ' << querySecond(1, 1, n, i) << '\n';
	//}

	for(int id = 0; id < m; id++){
		int tp;
		cin >> tp;
		if(tp == 1){
			int l, r;	ll k;	cin >> l >> r >> k;
			updSecond(1, 1, n, l, r, k);
			
			ll al = querySecond(1, 1, n, l);
			ll al1 = querySecond(1, 1, n, l - 1);
			updFirst(1, 1, n, l, max(al - al1, 0LL));
			
			ll ar = querySecond(1, 1, n, r);
			ll ar1 = querySecond(1, 1, n, r + 1);
			updFirst(1, 1, n, r + 1, max(ar1 - ar, 0LL));
		} else {
			int l, r;	cin >> l >> r;
			
			ll ans = 0;
			if(l + 1 <= r){
				ans += queryFirst(1, 1, n, l + 1, r);
			}
			//cerr << "preans = " << ans << '\n';
			ll al = querySecond(1, 1, n, l);
			//cerr << "a[" << l << "] = " << al << '\n';
			ans += al;
			
			cout << ans << '\n';
		}
	}
}

void testGen(){
	srand(time(NULL));
	freopen("CONSTRUCT.INP", "w", stdout);
	
	int t = 4;
	cout << t << '\n';
	while(t--){
		int N = 1000, M = 100;
		cout << N << ' ' << M << '\n';
		for(int i = 1; i <= N; i++){
			ll x = (rand() * rand()) % 100000 + 1;
			cout << x << ' ';
		}
		cout << '\n';

		while(M--){
			int tp = rand() % 2 + 1;
			cout << tp << ' ';
			if(tp == 1){
				int l, r;	ll k = (rand() * rand()) % 100000 + 1;	
				l = rand() % N + 1;
				r = rand() % N + 1;
				if(l > r){
					swap(l, r);
				}
				cout << l << ' ' << r << ' ' << k << '\n';
			} else if(tp == 2){
				int l, r;
				l = rand() % N + 1;
				r = rand() % N + 1;
				if(l > r){
					swap(l, r);
				}
				cout << l << ' ' << r << '\n';
			}
		}
	}

	exit(0);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	//testGen();

	freopen("CONSTRUCT.INP", "r", stdin);
	freopen("CONSTRUCT.OUT", "w", stdout);
	
	int nTest;	cin >> nTest;

	while(nTest--){
		cin >> n >> m;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}

		//if(n <= 1000 && m <= 50000){
		//	sub1();
		//	continue;
		//}

		sub2();
	}

	return 0;
}