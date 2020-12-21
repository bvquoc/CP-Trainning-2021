#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("unroll-loops, no-stack-protector")
#pragma GCC target ("avx")
#pragma GCC target ("avx2")
#pragma GCC target ("fma")
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define pci pair <char, int>
#define pld pair <ld, ld>
#define ppld pair <pld, pld>
#define ppll pair <pll, pll>
#define pldl pair <ld, ll>
#define vll vector <ll>
#define vvll vector <vll>
#define vpll vector <pll>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define mll map <ll, ll>
#define fastmap gp_hash_table
#define cd complex <double>
#define vcd vector <cd>
#define PI 3.14159265358979
#define ordered_set tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update>
#pragma 03
using namespace std;
using namespace __gnu_pbds;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int mod = 1e9 + 7;
int fact[200005], ivfc[200005];
int sum[200005];
int st[800005];
int suffix_lesser[200005], suffix_pos[200005];
int n;
int modadd(int a, int b){
	a += b; if (a >= mod) a -= mod; return a;
}
int modsub(int a, int b){
	a -= b; if (a < 0) a += mod; return a;
}
int modmul(int a, int b){
	return (1LL * a * b) % mod;
}
int modpow(int a, int b){
	int ret = 1;
	while (b){
		if (b % 2) ret = modmul(ret, a);
		a = modmul(a, a); b >>= 1;
	}
	return ret;
}
int moddiv(int a, int b){
	int inv = modpow(b, mod - 2);
	return modmul(a, inv);
}
int ckn(int k, int n){
	return modmul(fact[n], modmul(ivfc[k], ivfc[n - k]));
}
int div2(int x){
	if (x % 2) x += mod; x /= 2; return x;
}
vector <int> permutation;
void build(int root, int l, int r){
	if (l == r){
		st[root] = 1; return;
	}
	int mid = (l + r) / 2;
	build(root * 2 + 1, l, mid);
	build(root * 2 + 2, mid + 1, r);
	st[root] = modadd(st[root * 2 + 1], st[root * 2 + 2]);
}
void update(int root, int l, int r, int id, int val){
	if ((id < l) || (r < id)) return;
	if (l == r){
		st[root] = val; return;
	}
	int mid = (l + r) / 2;
	update(root * 2 + 1, l, mid, id, val);
	update(root * 2 + 2, mid + 1, r, id, val);
	st[root] = modadd(st[root * 2 + 1], st[root * 2 + 2]);
}
int query(int root, int l, int r, int x, int y){
	if ((y < l) || (r < x)) return 0;
	if ((x <= l) && (r <= y)) return st[root];
	int mid = (l + r) / 2;
	return modadd(query(root * 2 + 1, l, mid, x, y), query(root * 2 + 2, mid + 1, r, x, y));
}
int calc(){
	build(0, 0, n - 1);
	for (int i = 0; i < n; i++){
		suffix_pos[i] = query(0, 0, n - 1, 0, permutation[i]);
		update(0, 0, n - 1, permutation[i], 0);
	}
	for (int i = n - 1; i >= 0; i--){
		int x = n - i;
		suffix_lesser[i] = modadd(suffix_lesser[i + 1], modmul(suffix_pos[i] - 1, fact[x - 1])); 
	}
	int ret = 0;
	for (int i = 0; i < n; i++){
		int true_pos = suffix_pos[i]; 
		int x = n - i;
		ret = modadd(ret, modmul(fact[x - 1], div2(modmul(true_pos - 1, true_pos - 2))));
		ret = modadd(ret, modmul(sum[x - 1], true_pos - 1));
		ret = modadd(ret, modmul(true_pos - 1, suffix_lesser[i + 1]));
		update(0, 0, n - 1, permutation[i], 0);
	}
	return ret;
}
int main(){
	freopen("permeow.inp", "r", stdin);
	freopen("permeow.out", "w", stdout);
	fastio;
	fact[0] = 1; for (int i = 1; i < 200005; i++) fact[i] = modmul(fact[i - 1], i);
	ivfc[200004] = moddiv(1, fact[200004]); for (int i = 200003; i >= 0; i--) ivfc[i] = modmul(ivfc[i + 1], (i + 1));
	for (int i = 0; i < 200005; i++) sum[i] = div2(modmul(fact[i], div2(modmul(i, i - 1))));
	cin >> n; suffix_lesser[n] = 1; permutation.resize(n);
	int ans = 0;
	for (int i = 0; i < n; i++) cin >> permutation[i], permutation[i]--;
	if (prev_permutation(permutation.begin(), permutation.end())) ans = modsub(ans, calc());
	for (int i = 0; i < n; i++) cin >> permutation[i], permutation[i]--;
	ans = modadd(ans, calc());
	cout << ans << "\n";
}