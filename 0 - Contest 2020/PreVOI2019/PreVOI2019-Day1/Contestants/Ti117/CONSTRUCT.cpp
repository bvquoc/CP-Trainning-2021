#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N = 1e5 + 5;
int t,n,q,type,l,r,k,a[N],lazy[4*N];
pair<int,int> st[4*N];
void build(int id,int l,int r){
	if(l > r) return;
	if(l == r){
		st[id] = {a[l], l};
		lazy[id] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(id<<1, l, mid);
	build(id<<1|1, mid+1, r);
	st[id] = min(st[id<<1], st[id<<1|1]);
	lazy[id] = 0;
}
void push_down(int id,int l,int r){
	if(lazy[id] != 0){
		st[id].fi += lazy[id];
		if(l < r){
			lazy[id<<1] += lazy[id];
			lazy[id<<1|1] += lazy[id];
		}
		lazy[id] = 0;
	}
}
void update(int id,int l,int r,int i,int j,int val){
	push_down(id, l, r);
	if(l>j || r<i || i>j){
		return;
	}
	if(l>=i && r<=j){
		st[id].fi += val;
		if(l < r){
			lazy[id<<1] += val;
			lazy[id<<1|1] += val;
		}
		return;
	}
	int mid = (l + r) >> 1;
	update(id<<1, l, mid, i, j, val);
	update(id<<1|1, mid+1, r, i, j, val);
	st[id] = min(st[id<<1], st[id<<1|1]);
}
pair<int,int> get(int id,int l,int r,int i,int j){
	push_down(id, l, r);
	if(l>j || r<i || i>j){
		return {1e9, 1e9};
	}
	if(l>=i && r<=j){
		return st[id];
	}
	int mid = (l + r) >> 1;
	return min(get(id<<1, l, mid, i, j), get(id<<1|1, mid+1, r, i, j));
}
long long solve(int l,int r){
	pair<int,int> tmp = get(1, 1, n, l, r);
	if(l == r){
		return tmp.fi;
	}else{
		int pivot = tmp.se;
		if(pivot == l){
			long long rig = solve(pivot + 1, r);
			return rig;
		}else{
			if(pivot == r){
				long long lef = solve(l, pivot - 1);
				return lef;
			}else{
				long long lef = solve(l, pivot - 1);
				long long rig = solve(pivot + 1, r);
				return lef + rig - tmp.fi;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("CONSTRUCT.inp","r",stdin);
	freopen("CONSTRUCT.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n >> q;
		for(int i=1;i<=n;i++) cin >> a[i];
		build(1, 1, n);
		while(q--){
			cin >> type >> l >> r;
			if(type == 1){
				cin >> k;
				update(1, 1, n, l, r, k);
			}else{
				long long ans = solve(l, r);
				cout << ans << "\n";
			}
		}
	}
}
