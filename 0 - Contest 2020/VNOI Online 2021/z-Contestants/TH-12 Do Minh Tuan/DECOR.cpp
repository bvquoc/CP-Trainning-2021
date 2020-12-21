#include <bits/stdc++.h>
#define tkn "DECOR"
#define pb push_back
using namespace std;
int n, m, k;
const int N = 5e5 + 7;
bool egg[N];
vector<int> sw[N];
int bh[N];
int ans;
int l, r;
void input() {
    cin >> n >> m >> k;
    char r;
    for (int i = 1; i <= n; i++) {
        cin >> r;
        egg[i] = r - '0';
    }

    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        sw[u].pb(v);
        sw[v].pb(u);
    }
}
void sub1() {
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            if (egg[i]) bh[i] = 1;
            else bh[i] = n + 1;
        }
        else {
            if (!egg[i]) bh[i] = n + 1;
            else {
                if (egg[i - 1]) bh[i] = bh[i - 1];
                else bh[i] = i;
            }
        }
        if (i - bh[i] + 1 > ans) {
            ans = i - bh[i] + 1;
            l = bh[i];
            r = i;
        }
    }
    cout << l << ' ' << r;
}
void sub2() {
    priority_queue<int, vector<int>, greater<int>> heap;
    int id = 1;
    for (int i = 1; i <= n; i++)
        if (egg[i]) bh[i] = bh[i - 1] + 1;
        else bh[i] = 0;
    while (true) {
        if (id == n + 1) break;
        while (id <= n && heap.size() < k) {
            if (!egg[id]) heap.push(id);
            id++;
        }
        while (id <= n && egg[id]) id++;
        if (id - heap.top() + bh[heap.top() - 1] > ans) {
            ans = id - heap.top() + bh[heap.top() - 1];
            l = heap.top() - bh[heap.top() - 1];
            r = id - 1;
        }
        heap.pop();
    }
    cout << l << ' ' << r;
}
int main() {
    ios_base::sync_with_stdio(0);
    freopen(tkn".inp", "r", stdin);
    freopen(tkn".out", "w", stdout);
    cin.tie(0);  cout.tie(0);

    input();
    if (m == 0 && k == 0) {
        sub1();
        return 0;
    }
    if (m == 0) {
        sub2();
        return 0;
    }

    return 0;
}
