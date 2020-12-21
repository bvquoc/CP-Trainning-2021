#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5, MOD = 1e9 + 7;
int n, fac[N], dp[N];

void add(int &a, int b) {
	a = (a + b) % MOD;
}
void mul(int &a, int b) {
	a = a * b % MOD;
}

void precomputation() {
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i] = fac[i - 1];
		mul(fac[i], i);
	}
	for (int i = 2; i <= n; ++i) {
		int tmp = i * (i - 1) / 2;
		mul(tmp, fac[i - 1]);
		add(dp[i], dp[i - 1] * i + tmp);
	}
}

struct Node {
	int sum, cnt, lazy;
	Node() {}
	Node(int _sum, int _cnt, int l) : sum(_sum), cnt(_cnt), lazy(l) {}
};

struct SegmentTree {
	int n;
	vector <Node> st;
	SegmentTree() {}
	SegmentTree(int _n) {
		this -> n = _n;
		st.assign(4 * n + 5, Node(0, 0, 0));
	}
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}

	void build(int id, int L, int R) {
		if (L == R) {
			st[id].cnt = 1;
			st[id].sum = L - 1;
			return;
		}
		int mid = (L + R) >> 1;
		build(Left(id), L, mid);
		build(Right(id), mid + 1, R);
		st[id].sum = st[Left(id)].sum + st[Right(id)].sum;
		st[id].cnt = st[Left(id)].cnt + st[Right(id)].cnt;
	}

	void push(int id) {
		st[Left(id)].sum += st[Left(id)].cnt * st[id].lazy;
		st[Left(id)].lazy += st[id].lazy;
		st[Right(id)].sum += st[Right(id)].cnt * st[id].lazy;
		st[Right(id)].lazy += st[id].lazy;
		st[id].lazy = 0;
	}

	void add(int id, int L, int R, int i, int j, int v) {
		if (L > j || R < i) return;
		if (L >= i && R <= j) {
			st[id].sum += st[id].cnt * v;
			st[id].lazy += v;
			return;
		}
		int mid = (L + R) >> 1;
		push(id);
		add(Left(id), L, mid, i, j, v);
		add(Right(id), mid + 1, R, i, j, v);
		st[id].sum = st[Left(id)].sum + st[Right(id)].sum;
		st[id].cnt = st[Left(id)].cnt + st[Right(id)].cnt;
	}
	void update(int id, int L, int R, int i, int j) {
		if (L > i || R < i) return;
		if (L == R) {
			st[id].cnt = j;
			st[id].sum *= j;
			return;
		}
		int mid = (L + R) >> 1;
		push(id);
		update(Left(id), L, mid, i, j);
		update(Right(id), mid + 1, R, i, j);
		st[id].sum = st[Left(id)].sum + st[Right(id)].sum;
		st[id].cnt = st[Left(id)].cnt + st[Right(id)].cnt;
	}
	int get(int id, int L, int R, int i, int j) {
		if (L > j || R < i) return 0;
		if (L >= i && R <= j) {
			return st[id].sum;
		}
		int mid = (L + R) >> 1;
		push(id);
		int ret = get(Left(id), L, mid, i, j) + get(Right(id), mid + 1, R, i, j);
		st[id].sum = st[Left(id)].sum + st[Right(id)].sum;
		st[id].cnt = st[Left(id)].cnt + st[Right(id)].cnt;
		return ret;
	}
	int get_cnt(int id, int L, int R, int i, int j) {
		if (L > j || R < i) return 0;
		if (L >= i && R <= j) {
			return st[id].cnt;
		}
		int mid = (L + R) >> 1;
		push(id);
		int ret = get_cnt(Left(id), L, mid, i, j) + get_cnt(Right(id), mid + 1, R, i, j);
		st[id].sum = st[Left(id)].sum + st[Right(id)].sum;
		st[id].cnt = st[Left(id)].cnt + st[Right(id)].cnt;
		return ret;
	}
	void add(int i, int j, int v) {
		add(1, 1, n, i, j, v);
	}
	void update(int i, int j) {
		update(1, 1, n, i, j);
	}
	int get(int i, int j) {
		if (i > j) return 0;
		return get(1, 1, n, i, j);
	}
	int get_cnt(int i, int j) {
		if (i > j) return 0;
		return get_cnt(1, 1, n, i, j);
	}
};

int solve(vector <int> a) {
	SegmentTree Solver = SegmentTree(n);
	Solver.build(1, 1, n);
	int cur_inv = 0, tot_smaller = 0, res = 0;
	for (int i = 1; i <= n; ++i) {
		int tmp = Solver.get(a[i] + 1, n) % MOD, bigger = Solver.get_cnt(a[i] + 1, n);
		add(tmp, bigger * (cur_inv + tot_smaller));
		mul(tmp, fac[n - i]);
		add(tmp, dp[n - i] * bigger);
		add(res, tmp);
		cur_inv += n - a[i] - bigger;
		tot_smaller -= n - a[i] - bigger;
		tot_smaller += Solver.st[1].cnt - 1 - bigger;
		Solver.add(a[i] + 1, n, -1);
		Solver.update(a[i], 0);
	}
	add(res, cur_inv);
	return res;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("PERMEOW.INP", "r", stdin);
	freopen("PERMEOW.OUT", "w", stdout);

	clock_t t = clock();
	cin >> n;
	vector <int> A; A.push_back(0);
	for (int i = 1; i <= n; ++i) {
		int v;
		cin >> v;
		A.push_back(v);
	}
	precomputation();
	int res = solve(A);
	A.clear(); A.push_back(0);
	for (int i = 1; i <= n; ++i) {
		int v;
		cin >> v;
		A.push_back(v);
	}
	// cerr << 1.0 * (clock() - t) / CLOCKS_PER_SEC << endl;
	if (!next_permutation(A.begin() + 1, A.end())) {
		cout << res << endl;
		return 0;
	}
	res = (res - solve(A) + MOD) % MOD;
	cout << res << endl;

	return 0;
}