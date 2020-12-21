#include <bits/stdc++.h>
#define Task "SOCKS"
#define pb push_back

using namespace std;

const int maxn = 100005;

int n, q;
vector<int> ke[maxn];
int cor[maxn];

namespace Sub1 {

    void Solve() {
        int cnt1 = 0, cnt2 = 0;
        for(int i = 1; i <= n; ++ i) {
            if(cor[i]) cnt1 ++;
            else cnt2 ++;
        }
        while(q --) {
            int x; cin >> x;
            cor[x] ^= 1;
            if(cor[x]) cnt1 ++, cnt2 --;
            else cnt1 --, cnt2 ++;
            if(cnt1 > 1) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
}

namespace Sub2 {

    int typ[maxn], cnt[5];

    void DFS(int u, int par, int t) {
        typ[u] = t;
        for(auto v : ke[u]) {
            if(v == par) continue;
            DFS(v, u, t);
        }
    }

    void Solve() {
        int pos;
        for(int i = 1; i <= n; ++ i) {
            if(ke[i].size() == 3) {
                pos = i;
                for(int j = 0; j < ke[i].size(); ++ j) {
                    int u = ke[i][j];
                    DFS(u, i, j + 1);
                }
                break;
            }
        }
        typ[pos] = 1;
        for(int i = 1; i <= n; ++ i) {
            cnt[typ[i]] += cor[i];
        }
        while(q --) {
            int x; cin >> x;
            cor[x] ^= 1;
            if(cor[x]) cnt[typ[x]] ++;
            else cnt[typ[x]] --;
            int dem = (cnt[1] > 0) + (cnt[2] > 0) + (cnt[3] > 0);
            if(dem == 3) cout << 2 << "\n";
            else if(dem < 2) cout << 0 << "\n";
            else cout << 1 << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> q;
    for(int i = 1; i <= n; ++ i) cin >> cor[i];
    for(int i = 1; i < n; ++ i) {
        int u, v; cin >> u >> v;
        ke[u].pb(v);
        ke[v].pb(u);
    }
    int dem = 0, sub1 = 1, sub2 = 1;
    for(int i = 1; i <= n; ++ i) {
        if(ke[i].size() > 2) sub1 = 0;
        if(ke[i].size() == 3) dem ++;
        if(dem > 1) sub2 = 0;
    }
    if(sub1) {
        Sub1::Solve();
        return 0;
    }
    if(sub2) {
        Sub2::Solve();
        return 0;
    }
}
