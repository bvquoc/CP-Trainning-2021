#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
using namespace std;

template <typename T>
inline void Read(T& x) {
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}
template <typename T>
inline void Write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int N = 2003;
int n, m, q_sz;

struct DisjointSet {
    int father[N], height[N];
    void init() {
        for (int i=1; i<=n; i++) {
            father[i] = i;
            height[i] = 0;
        }
    }
    int find(int node) {
        if (father[node] != node) {
            father[node] = find(father[node]);
        }
        return father[node];
    }
    void unite(int A, int B) {
        int rootA = find(A);
        int rootB = find(B);
        if (height[rootA] > height[rootB]) {
            father[rootB] = rootA;
            height[rootA] = max(height[rootA], height[rootB] + 1);
        } else {
            father[rootA] = rootB;
            height[rootB] = max(height[rootB], height[rootA] + 1);
        }
    }
    int count() {
        set <int> S;
        for (int i=1; i<=n; i++) {
            S.insert(find(i));
        }
        return S.size();
    }
} DSU;

struct T_edge { int u,v; } E[30004];
struct T_query {
	int id;
    int u, v;
    int ans;
} q[50004];

signed main(void) {
	FastIO;
    freopen("CONCOMP.INP","r",stdin);
    freopen("CONCOMP.OUT","w",stdout);
	Read(n); Read(m);
    FOR(i,1,m) {
        Read(E[i].u);
        Read(E[i].v);
    }

	Read(q_sz);
    FOR(i,1,q_sz) {
        int l, r; Read(l); Read(r);
        if (l>r) swap(l,r);
        q[i] = {i,l,r,-1};
        DSU.init();
        FOR(k,1,l-1) DSU.unite(E[k].u,E[k].v);
        FOR(k,r+1,m) DSU.unite(E[k].u,E[k].v);
        Write(DSU.count()); putchar('\n');
    }

    // sort(q+1,q+1+n,[](const T_query &A, const T_query &B){
    //     return A.u < B.u || (A.u == B.u && A.v > B.v);
    // });
    // FOR(i,1,q_sz) {
    //     cout << q[i].id << ' ' << q[i].u << ' ' << q[i].v << endl; 
    // }
}