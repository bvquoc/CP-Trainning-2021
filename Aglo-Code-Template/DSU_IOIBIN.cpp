// https://codeforces.com/group/FLVn1Sc504/contest/274496/problem/F
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

struct DSU {
    int n; vector <int> anc;
    void assign(int sz) {
        n = sz;
        anc.resize(n+1);
        for (int i=1; i<=n; i++) anc[i] = i;
    }
    DSU (int sz = 1e5) { assign(sz); }
    int find(int node) {
        if (anc[node] != node) anc[node] = find(anc[node]);
        return anc[node];
    }
    void unite(int A, int B) {
        int rootA = find(A);
        int rootB = find(B);
        if (rand() & 1) anc[rootB] = rootA;
        else anc[rootA] = rootB;
    }
};

DSU S;

signed main(void) {
    FastIO;
    int T; cin >> T;
    int u, v, q;
    while (T--) {
        cin >> u >> v >> q;
        if (q == 1) {
            S.unite(u,v);
        } else {
            if (S.find(u) == S.find(v)) cout << '1';
            else cout << '0';
            cout << endl;
        }
    }
    return 0;
}