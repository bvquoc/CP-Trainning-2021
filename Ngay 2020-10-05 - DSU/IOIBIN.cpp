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
    DSU () { assign(1e5); }
    DSU (int sz) { assign(sz); }
    int find(int node) {
        if (father[node] != node) {
            father[node] = find(father[node]);
        }
        return father[node];
    }
    void unite(int A, int B) {
        int rootA = find(A);
        int rootB = find(B);
        if (rand() % 2) {
            father[rootB] = rootA;
        } else {
            father[rootA] = rootB;
        }
    }
};

DSU S;

signed main(void) {
    FastIO;
    freopen("input.txt","r",stdin);
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