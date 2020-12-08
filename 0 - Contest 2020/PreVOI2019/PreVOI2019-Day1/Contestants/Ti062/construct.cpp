#include<bits/stdc++.h>
#define qwer "construct"

using namespace std;

const int maxn = 1e5 + 3;
int a[maxn];

template<int sze> struct Eins
{
	struct node
	{
		int val,l,r;
	};
	friend node operator + (const node&a,const node&b) 
	{
		if (!a.val) return b;
		if (!b.val) return a;
		node x;
		x.val = a.val + b.val;
		x.l = a.l;
		x.r = b.r;
		if (a.r <= b.l) x.val -= a.r;
		else x.val -= b.l;
		return x;
	}
	vector<node> st;
	Eins() {st.resize(sze);}
	void build(int id,int l,int r)
	{
		if (l == r) {
			st[id] = {a[l],a[l],a[l]};
			return ;
		}
		int mid = l + r >> 1;
		build(id << 1,l,mid);
		build(id<<1|1,mid+1,r);
		st[id] = st[id << 1] + st[id << 1|1];
	}
	void update(int id,int l,int r,int L,int R,int val)
	{
		if (l > R || r < L) return ;
		if (l == r) {
			st[id].val += val;
			st[id].l += val;
			st[id].r += val;
			return ;
		}
		int mid = l + r >> 1;
		update(id << 1,l,mid,L,R,val);
		update(id << 1|1,mid+1,r,L,R,val);
		st[id] = st[id << 1] + st[id << 1|1];
	}
	node get(int id,int l,int r,int L,int R)
	{
		if (l > R || r < L) return {0,0,0};
		if (L <= l && r <= R)return st[id];
		int mid = l + r >> 1;
		return get(id << 1,l,mid,L,R) + get(id << 1|1,mid+1,r,L,R);
	}
};
Eins<maxn << 2> Tree;

int main()
{
	if (fopen(qwer".inp","r")) freopen(qwer".inp","r",stdin),freopen(qwer".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	while (q--) {
		int n,m;
		cin >> n >> m;
		for (int i = 1;i <= n;++i) cin >> a[i];
		Tree.build(1,1,n);
		while (m--) {
			int type,l,r;
			cin >> type >> l >> r;
			if (type == 1) {
				int k;
				cin >> k;
				Tree.update(1,1,n,l,r,k);
			}
			else {
				cout << Tree.get(1,1,n,l,r).val <<"\n";
			}
		}
	}
}
