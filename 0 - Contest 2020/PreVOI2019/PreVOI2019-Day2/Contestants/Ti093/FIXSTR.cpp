#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const int BIG = 1e9 + 555;
const int maxN = 1e6 + 55;

int n, m;
int a[maxN];
int lazy[4 * maxN];
pair<int, int> segTree[4 * maxN];
string s[1000 + 5];
string str;

void propagate(int id, int l, int r){
	if(lazy[id]){
		segTree[id].first += lazy[id];
		segTree[id].second += (r - l + 1) * lazy[id];

		if(l != r){
			lazy[id * 2] += lazy[id];
			lazy[id * 2 + 1] += lazy[id];
		}
	
		lazy[id] = 0;
	}
}

void upd(int id, int l, int r, int L, int R, int val){
	propagate(id, l, r);
	if(L <= l && r <= R){
		lazy[id] += val;
		propagate(id, l, r);
		return;
	}

	if(r < L|| l > R){
		return;
	}

	int mid = (l + r) / 2;
	upd(id * 2, l, mid, L, R, val);
	upd(id * 2 + 1, mid + 1, r, L, R, val);

	segTree[id].first = min(segTree[id * 2].first, segTree[id * 2 + 1].first);
	segTree[id].second = segTree[id * 2].second + segTree[id * 2 + 1].second;
}

int getMn(int id, int l, int r, int L, int R){
	propagate(id, l, r);
	if(L <= l && r <= R){
		return segTree[id].first;
	}

	if(r < L || l > R){
		return BIG;
	}

	int mid = (l + r) / 2;
	int ans = getMn(id * 2, l, mid, L, R);
	return min(ans, getMn(id * 2 + 1, mid + 1, r, L, R));
}

int getSm(int id, int l, int r, int L, int R){
	propagate(id, l, r);
	if(L <= l && r <= R){
		return segTree[id].second;
	}

	if(r < L || l > R){
		return 0;
	}

	int mid = (l + r) / 2;
	return getSm(id * 2, l, mid, L, R) + getSm(id * 2 + 1, mid + 1, r, L, R);
}

void sub1(){
	s[0] = str;
	for(int iter = 1; iter <= m; iter++){
		s[iter] = s[iter - 1];
		char tp;	cin >> tp;
		if(tp == 'C'){
			int i;	cin >> i;
			s[iter][i] = ((s[iter][i] == '(') ? ')' : '(');
		} else if(tp == 'Q'){
			int l, r;	cin >> l >> r;
			int bal = 0, ans = 0;
			for(int i = l; i <= r; i++){
				bal += ((s[iter][i] == '(') ? +1 : -1);
				if(bal < 0){
					ans++;
					bal = 0;
				}
			}
			ans += abs(bal);
			cout << ans << '\n';
		} else {
			int k;	cin >> k;	k--;
			s[iter] = s[k];
		}
	}
}

int psum[maxN];

void sub2(){
	for(int i = 1; i <= n; i++){
		a[i] = ((str[i] == '(') ? +1 : -1);
		psum[i] = psum[i - 1] + a[i];
	}

	for(int i = 0; i <= n; i++){
		upd(1, 0, n, i, i, psum[i]);
	}

	while(m--){
		char tp;	cin >> tp;
		if(tp == 'C'){
			int i;	cin >> i;	int to = (a[i] == +1) ? -1 : +1;
			upd(1, 0, n, i, n, to - a[i]);
			a[i] = to;
			//cerr << i << ' ' << to << '\n';
		} else {
			int l, r;	cin >> l >> r;
			int extra = min(0, getMn(1, 0, n, l, r) - getSm(1, 0, n, l - 1, l - 1));
			int ans = getSm(1, 0, n, r, r) - getSm(1, 0, n, l - 1, l - 1) - extra - extra;
			//cerr << "extra = " << extra << '\n';

			cout << ans << '\n';
		}
	}
}

void testGen(){
	srand(time(NULL));
	freopen("FIXSTR.INP", "w", stdout);

	int N = 200, M = 200;
	for(int i = 0; i < N; i++){
		int a = (rand() % 2);
		if(a){
			cout << "(";
		} else {
			cout << ")";
		}
	}
	cout << '\n';

	cout << M << '\n';

	for(int i = 0; i < M; i++){
		int a = (rand() % 2);
		if(a == 0){
			cout << "C " << rand() % N + 1 << '\n';
		} else {
			int l = rand() % N + 1;
			int r = rand() % N + 1;
			if(l > r){
				swap(l, r);
			}
			cout << "Q " << l << ' ' << r << '\n';
		}
	}

	exit(0);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
		
	//testGen();

	freopen("FIXSTR.INP", "r", stdin);
	freopen("FIXSTR.OUT", "w", stdout);
	
	cin >> str;

	n = (int)str.size();
	str = ' ' + str;

	cin >> m;

	if(n <= 1000 && m <= 1000){
		sub1();
		return 0;
	}

	sub2();

	return 0;
}