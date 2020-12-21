#include <bits/stdc++.h>
#define tkn "SOCKS"
#define pb push_back
using namespace std;
int n, q;
const int N = 5e5 + 7;
int state[N];
vector<int> adj[N];
int ans = 0;
void input() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> state[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}
bool checkSub1() {
    int ct1 = 0, ct2 = 0;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1) ct1++;
        if (adj[i].size() == 2) ct2++;
    }
    return ct1 == 2 && ct2 == n - 2;
}
void sub1() {
    int cnt1 = 0;
    for (int i = 1; i <= n; i++)
        if (state[i]) cnt1++;
    if (cnt1 > 1) cout << 1 << '\n';
    else cout << 0 << '\n';
    int u;
    while (q--) {
        cin >> u;
        if (state[u]) {
            cnt1--;
            state[u] = 0;
        }
        else {
            cnt1++;
            state[u] = 1;
        }
        if (cnt1 > 1) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}
bool checkSub2() {
    int ct1 = 0, ct2 = 0, ct3 = 0;

    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1) ct1++;
        if (adj[i].size() == 2) ct2++;
        if (adj[i].size() == 3) ct3++;
    }
    return ct1 == 3 && ct2 == n - 4 && ct3 == 1;
}
int status[N];
void dfs(int node, int pre, int lv) {
    status[node] = lv;
    for (auto p : adj[node])
        if (p != pre) dfs(p, node, lv);
}
bool In23(int x, int y, int z) {
    if (x > 0 && y > 0 && z == 0) return 1;
    if (x > 0 && y == 0 && z > 0) return 1;
    if (x == 0 && y > 0 && z > 0) return 1;
    return 0;
}
bool Big(int x, int y, int z) {
    return x >= 1 || y >= 1 || z >= 1;
}
bool Bigger(int x, int y, int z) {
    return x > 1 || y > 1 || z > 1;
}
void sub2() {

    int root;
    for (int i = 1; i <= n; i++)
        if (adj[i].size() == 3) {
            root = i;
            break;
        }
    status[root] = 0;
    for (int i = 0; i < adj[root].size(); i++)
        dfs(adj[root][i], root, i + 1);
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 1; i <= n; i++)
        if (state[i]) {
            if (status[i] == 1) cnt1++;
            if (status[i] == 2) cnt2++;
            if (status[i] == 3) cnt3++;
        }

    if (cnt1 * cnt2 * cnt3 > 0) cout << 2 << '\n';
    else {
        if (In23(cnt1, cnt2, cnt3)) cout << 1 << '\n';
        else {
            if (Bigger(cnt1, cnt2, cnt3)) cout << 1 << '\n';
            else {
                if (Big(cnt1, cnt2, cnt3) && state[root]) cout << 1 << '\n';
                else cout << 0 << '\n';
            }
        }
    }
    int u;
    while (q--) {
        cin >> u;
        if (state[u]) {
            state[u] = 0;
            if (status[u] == 1) cnt1--;
            if (status[u] == 2) cnt2--;
            if (status[u] == 3) cnt3--;
        }
        else {
            state[u] = 1;
            if (status[u] == 1) cnt1++;
            if (status[u] == 2) cnt2++;
            if (status[u] == 3) cnt3++;
        }
        if (cnt1 * cnt2 * cnt3 > 0) cout << 2 << '\n';
        else {
            if (In23(cnt1, cnt2, cnt3)) cout << 1 << '\n';
            else {
                if (Bigger(cnt1, cnt2, cnt3)) cout << 1 << '\n';
                else {
                    if (Big(cnt1, cnt2, cnt3) && state[root]) cout << 1 << '\n';
                    else cout << 0 << '\n';
                }
            }
        }
    }
}
void sub3() {

}
int main()  {
    ios_base::sync_with_stdio(0);
    freopen(tkn".inp", "r", stdin);
    freopen(tkn".out", "w", stdout);
    cin.tie(0);  cout.tie(0);

    input();
    if (checkSub1()) {
        sub1();
        return 0;
    }
    if (checkSub2()) {
        sub2();
        return 0;
    }
    sub3();
    return 0;
}
