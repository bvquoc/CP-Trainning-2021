#include <bits/stdc++.h>
#define tkn "COOLMAC"
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;
int m;
const int M = 1e5 + 7;
pii coat[M];
int n;
const int N = 1e5 + 7;
int t[N];
int minT;
int ans = 0;
bool ok;
void input() {
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> coat[i].fi >> coat[i].se;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> t[i];
}
bool cmp(pii c1, pii c2) {
    return c1.se > c2.se;
}
void init() {
    sort (coat + 1, coat + m + 1, cmp);
    for (int i = 1; i <= n; i++)
        if (i == 1) minT = t[i];
        else minT = min(minT, t[i]);
}
void specialCase() {
    for (int i = 1; i <= m; i++)
        if (coat[i].se >= 100000 && coat[i].fi <= minT) {
            ok = 1;
            ans = 1;
            return;
        }
    ok = 0;
}
void solve() {
    int ed = 1e5;
    int id = 1;
    while (id <= m) {
        priority_queue<int, vector<int>, greater<int>> heap;
        for (int i = id; i <= m; i++, id++)
            if (coat[i].se >= ed) heap.push(coat[i].fi);
            else break;
        if (heap.empty()) break;
        ed = heap.top();
        ans++;
        if (ed <= minT) {
            ok = 1;
            return;
        }
    }
    ok = 0;
}
void output() {
    if (ok) cout << ans;
    else cout << -1;
}
int main() {
    ios_base::sync_with_stdio(0);
    freopen(tkn".inp", "r", stdin);
    freopen(tkn".out", "w", stdout);
    cin.tie(0);  cout.tie(0);
    input();
    init();
    if (minT == 100000) specialCase();
    else solve();
    output();
    return 0;
}
