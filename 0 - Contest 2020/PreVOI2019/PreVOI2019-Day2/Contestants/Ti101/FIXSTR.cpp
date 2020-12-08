#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair

using namespace std;

const int N = int(1e6) + 7;
const int oo = int(1e9) + 9;
typedef pair<int, int> pii;
struct TQuery {
    char cmd;
    int u, v;
    TQuery() {cmd = 'C', u = v = 0;}
    TQuery(char cmd, int u, int v): cmd(cmd), u(u), v(v) {}
} q[N];

int l[N << 2], h[N << 2], st[N << 2], lz[N << 2], n, m, cost[N];
string s, t[5003];

void Build(int x, int low, int high) {
    l[x] = low, h[x] = high;
    if(l[x] == h[x]) {
        st[x] = cost[low];
        return;
    }
    int mid = (low + high) >> 1;
    Build(x << 1, low, mid);
    Build(x << 1 | 1, mid + 1, high);
    st[x] = min(st[x << 1], st[x << 1 | 1]);
}

void Down(int x) {
    if(lz[x] == 0 || l[x] == h[x]) return;
    st[x << 1] += lz[x]; lz[x << 1] += lz[x];
    st[x << 1 | 1] += lz[x], lz[x << 1 | 1] += lz[x];
    lz[x] = 0;
}

void Update(int x, int low, int high, int val) {
    Down(x);
    if(l[x] > high || h[x] < low) return;
    if(l[x] >= low && h[x] <= high) {
        st[x] += val; lz[x] += val;
        return;
    }
    Update(x << 1, low, high, val);
    Update(x << 1 | 1, low, high, val);
    st[x] = min(st[x << 1], st[x << 1 | 1]);
}

int Query(int x, int low, int high) {
    Down(x);
    if(l[x] > high || h[x] < low) return 1e9;
    if(l[x] >= low && h[x] <= high) return st[x];
    return min(Query(x << 1, low, high), Query(x << 1 | 1, low, high));
}

void Undo(int pos, int lim) {
    int j = pos - 1;
    while(j >= lim) {
        if(q[j].cmd == 'C') {
            if(s[q[j].u] == '(') {
                s[q[j].u] = ')';
                Update(1, q[j].u, n, -2);
            } else {
                s[q[j].u] = '(';
                Update(1, q[j].u, n, 2);
            }
        } else if(q[j].cmd == 'U') lim = min(lim, q[j].u);
        --j;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "fixstr"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> s >> m; n = int(s.size()); s = ' ' + s;
    for(int i = 1; i <= n; ++i) {
        if(s[i] == '(') cost[i] = cost[i - 1] + 1;
        else cost[i] = cost[i - 1] - 1;
    }
    bool found = 0;
    for(int i = 1; i <= m; ++i) {
        cin >> q[i].cmd >> q[i].u;
        if(q[i].cmd == 'Q') cin >> q[i].v;
        if(q[i].cmd == 'U') found = 1;
    }
    if(n > 3000 || m > 3000 || !found) {
        Build(1, 0, n);
        for(int i = 1; i <= m; ++i) {
            if(q[i].cmd == 'C') {
                if(s[q[i].u] == '(') {
                    s[q[i].u] = ')';
                    Update(1, q[i].u, n, -2);
                } else {
                    s[q[i].u] = '(';
                    Update(1, q[i].u, n, 2);
                }
            } else if(q[i].cmd == 'Q') {
                int cost = Query(1, q[i].v, q[i].v) - Query(1, q[i].u - 1, q[i].u - 1);
                int Min = min(Query(1, q[i].u, q[i].v) - Query(1, q[i].u - 1, q[i].u - 1), 0);
                cout << cost - 2 * Min << '\n';
            } else Undo(i, q[i].u);
        }
    } else {
        t[0] = s;
        for(int i = 1; i <= m; ++i) {
            if(q[i].cmd == 'C') {
                if(s[q[i].u] == '(') s[q[i].u] = ')';
                else s[q[i].u] = '(';
            } else if(q[i].cmd == 'Q') {
                int cost = 0, Min = 0;
                for(int j = q[i].u; j <= q[i].v; ++j) {
                    cost += (s[j] == '('? 1: -1);
                    Min = min(Min, cost);
                }
                cout << cost - 2 * Min << '\n';
            } else s = t[q[i].u - 1];
            t[i] = s;
        }
    }
}
