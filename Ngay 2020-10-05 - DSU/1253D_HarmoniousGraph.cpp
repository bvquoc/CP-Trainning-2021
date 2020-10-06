#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
// #define int long long
using namespace std;

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

struct DisjointSet {
    int n; vector <int> father, height;
    void assign(int sz) {
        n = sz;
        father.resize(n+1);
        height.resize(n+1);
        for (int i=1; i<=n; i++) {
            father[i] = i;
            height[i] = 0;
        }
    }
    DisjointSet () { assign(1e5); }
    DisjointSet (int sz) { assign(sz); }
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
} DSU;

const int N = 200005;
int n, m, cnt[N];
bool mark[N];

signed main(void) {
    FastIO;
    // freopen("input.txt","r",stdin);
    cin >> n >> m;
    DSU.assign(n);
    FOR(i,1,m) {
        int u, v;
        cin >> u >> v;
        mark[u] = mark[v] = true;
        DSU.unite(u,v);
    }
    FOR(i,1,n) {
        if (mark[i]) {
            int root = DSU.find(i);
            cnt[root]++;
        }
    }

    int res = 0;
    FOR(i,1,n) {
        if (cnt[i]<=2) cnt[i] = 0;
        if (cnt[i]) res++;
    }
    cout << res-1;
    return 0;
}