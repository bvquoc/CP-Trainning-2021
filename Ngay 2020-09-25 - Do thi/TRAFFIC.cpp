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
using ld = long double;

const int N = 202;
int n, m;
vector <int> ke[N];
bool mark[N];
int T[N];
bool ok;

void DFS(int u, int _v) {
    if (u == _v || ok) {
        ok = true;
        return;
    }
    for (int v: ke[u]) {
        DFS(v, _v);
    }
}

bool isOK(int u, int v) {
    ok = false;
    DFS(u,v);
    return ok;
}

signed main(void) {
    FastIO;
    freopen("TRAFFIC.INP","r",stdin);
    freopen("TRAFFIC.OUT","w",stdout);
    cin >> n >> m;
    FOR(i,1,n) {
        int u, v;
        cin >> u >> v;
        ke[u].push_back(v);
    }
    
    FOR(u,1,n) {
        FOR(v,1,n) {
            if (u!=v && !isOK(u,v)) {
                cout << u << ' ' << v << endl;
            }
        }
    }
    return 0;
}