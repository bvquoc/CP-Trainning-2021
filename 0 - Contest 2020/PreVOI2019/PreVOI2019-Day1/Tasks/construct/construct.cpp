/*input
1
5 4
1 3 1 4 5
2 1 5
1 3 4 2
2 2 4
2 1 5
*/
#include <bits/stdc++.h>
using namespace std;

int read() {
	int number = 0, c = getchar();
	for(; !(c > 47 && c < 58); c = getchar());
	for(; (c > 47 && c < 58); c = getchar()) number = (number << 3) + (number << 1) + c - 48;
	return number;
}

const int N = 100005;

struct Node {
	long long l, r, ans;
	Node(long long _l = 0, long long _r = 0, long long _ans = 0):
		l(_l), r(_r), ans(_ans) {}

	void Modify(int x) {
		l += x;
		r += x;
		ans += x;
	}
} t[N << 2];

Node Merge(Node a, Node b) {
	a.ans = a.ans + b.ans - min(a.r, b.l);
	a.r = b.r;
	return a;
}

int a[N];
long long lz[N << 2];

void init(int node, int l, int r) {
	lz[node] = 0;
	if(l == r) {
		t[node] = Node(a[l], a[l], a[l]);
		return;
	}
	int mid = (l + r) >> 1;
	init(node << 1, l, mid);
	init(node << 1 | 1, mid + 1, r);
	t[node] = Merge(t[node << 1], t[node << 1 | 1]);
}

void down(int node, int l, int r) {
	if(lz[node] == 0) return;
	long long y = lz[node]; lz[node] = 0;

	t[node].Modify(y);
	if(l != r) {
		lz[node << 1] += y;
		lz[node << 1 | 1] += y;
	}
}

void update(int node, int l, int r, int u, int v, int val) {
	down(node, l, r);
	if(r < u || v < l) return;
	if(u <= l && r <= v) {
		lz[node] += val;
		down(node, l, r);
		return;
	}
	int mid = (l + r) >> 1;
	update(node << 1, l, mid, u, v, val);
	update(node << 1 | 1, mid + 1, r, u, v, val);
	t[node] = Merge(t[node << 1], t[node << 1 | 1]);
}

#define mid ((l + r) >> 1)

Node get(int node, int l, int r, int u, int v) {
	down(node, l, r);
	if(r < u || v < l) return Node(0, 0, 0);
	if(u <= l && r <= v) return t[node];
	return Merge(get(node << 1, l, mid, u, v), get(node << 1 | 1, mid + 1, r, u, v));
}

#undef mid

void solve() {
	int n = read(), m = read();
	for(int i = 1; i <= n; ++ i) a[i] = read();
	init(1, 1, n);

	while(m --) {
		int type = read();
		if(type == 1) {
			int l = read(), r = read(), k = read();
			update(1, 1, n, l, r, k);
		} else {
			int l = read(), r = read();
			auto cur = get(1, 1, n, l, r);
			printf("%lld\n", cur.ans);
		}
	}
}

int main(){
	for(int test = read(); test -- > 0;) solve();
}