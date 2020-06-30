#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const int N = 1003;
int n, m, m_max = 0;
int res = 0;
vector <int> a, c[N];

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

MaxST T;

void Sub1_2() {
    int T_size = *max_element(a.begin(),a.end());
    T.assign(T_size);
    // a[] = { 1,2,2,1,2,2 } -> 9
    for (int i=1; i<=m; i++) {
        T.update(1, 0, T_size,a[i], T.getmax(1,0,T_size,0,a[i]) + a[i]);
    }
    
    res = T.getmax(1, 0, T_size, 0, T_size);
}

int32_t main(void) {
    FastIO;
    freopen("pig.inp","r",stdin);
    freopen("pig.out","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> m;
        m_max = max(m_max, m);
        c[i].assign(m+1,0);
        for (int j=1; j<=m; j++) {
            cin >> c[i][j];
        }
    }

    if (m_max == 0) {
        cout << res;
        return 0;
    }
    
    if (m_max == 1) {
        a.push_back(0);
        for (int i=1; i<=n; i++) {
            int m = c[i].size()-1;
            for (int j=1; j<=m; j++) {
                a.push_back(c[i][j]);
            }
        }
        m = a.size()-1;
        Sub1_2();
        cout << res;
        return 0;
    }
    
    cout << res;
    return 0;
}