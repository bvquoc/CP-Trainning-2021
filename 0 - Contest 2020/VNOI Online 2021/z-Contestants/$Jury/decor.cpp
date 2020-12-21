#include <bits/stdc++.h>

using namespace std;

const int maxn = 500005;
int n, m, k;
char s[maxn];
int label[maxn];
int cnt[maxn], cnt_off;

int dad[maxn];
int anc(int u) {
    if (dad[u] == u) return u;
    return dad[u] = anc(dad[u]);
}
void join(int u, int v) {
    u = anc(u);
    v = anc(v);
    dad[v] = u;
}

void add(int i) {
    --cnt[label[i]];
    if (cnt[label[i]] < 0) ++cnt_off;
}
void del(int i) {
    if (cnt[label[i]] < 0) --cnt_off;
    ++cnt[label[i]];
}

bool better(int l, int r, int u, int v) {
    if (r - l != v - u) return r - l > v - u;
    return l < u;
}

int main(void) {
#define TASK "DECOR"
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k >> (s + 1);
    iota(dad + 1, dad + n + 1, 1);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        join(u, v);
    }
    for (int i = 1; i <= n; ++i) {
        label[i] = anc(i);
        if (s[i] == '1') ++cnt[label[i]];
    }
    int best_l = -1, best_r = -1, l = 1, r = 0;
    for (l = 1; l <= n; ++l) {
        r = max(r, l - 1);
        while (r < n) {
            ++r;
            add(r);
            if (cnt_off > k) {
                del(r);
                --r;
                break;
            }
        }
        if (better(l, r, best_l, best_r)) {
            best_l = l;
            best_r = r;
        }
        del(l);
    }
    if (best_l == -1) {
        cout << -1 << endl;
    }
    else {
        cout << best_l << ' ' << best_r << endl;
    }
    return 0;
}
