// https://codeforces.com/group/L1Sf9F4uBt/contest/200499/problem/E
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
    int n; vector <int> father;
    void assign(int sz) {
        n = sz;
        father.resize(n+1);
        for (int i=1; i<=n; i++) {
            father[i] = i;
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
        father[rootA] = rootB;
    }
} DSU;

int n, m;

signed main(void) {
    FastIO;
    // freopen("input.txt","r",stdin);
    cin >> n >> m;
    DSU.assign(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        DSU.unite(u,v);
    }
    FOR(i,1,n) cout << DSU.find(i) << ' ';
    return 0;
}