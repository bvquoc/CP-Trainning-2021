/* http://lqdoj.edu.vn/problem/pig */
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const int N = 1000006;
using ii = pair <int,int>;
int n, m;
int res = 0;
set<int, greater<int> > c[N];

struct MaxST{
	vector <int> st, gt;
	MaxST() {}
	MaxST(int n) {
		st.resize((4*(n+5)));
		gt.resize(n+1);
	}
    void assign (int n) {
		st.resize((4*(n+5)));
		gt.resize(n+1);
	}
	void update(int id, int l, int r, int i, int v) {
	    if (i < l || r < i) return;
	    if (l==r) {
	        st[id]=v;
	        gt[i]=v;
	        return;
	    }
	    int mid = (l+r)>>1, id1=id<<1, id2=id1+1;
	    update(id1,l,mid,i,v);
	    update(id2,mid+1,r,i,v);
	    st[id]=max(st[id1],st[id2]);
	}
	int getmax(int id, int l, int r, int u, int v) {
	    if (v < l || r < u) return INT_MIN;
	    if (u <= l && r <= v) return st[id];
	    int mid = (l+r)>>1, id1=id<<1, id2=id1+1;
	    return max(getmax(id<<1,l,mid,u,v), getmax(id2, mid+1, r, u, v));
	}
};

const int T_size = 1000006;
MaxST T(T_size);

int32_t main(void) {
    FastIO;
    freopen("pig.inp","r",stdin);
    freopen("pig.out","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> m;
        for (int j=1; j<=m; j++) {
            int x; cin >> x;
            c[i].insert(x);
        }
    }

    for (int i=1; i<=n; i++) {
        for (int x: c[i]) {
            T.update(1, 0, T_size,x, T.getmax(1,0,T_size,0,x) + x);
        }
    }
    res = T.getmax(1, 0, T_size, 0, T_size);
    
    cout << res;
    return 0;
}