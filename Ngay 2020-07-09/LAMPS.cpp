#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const int N = 3003;
int n, T;
vector <int> a[N];
bool x[N], d[N];
bool new_d[N];
vector <int> res;
int res_cnt = INT_MAX;

void check() {
    for (int i=1; i<=n; i++) {
        new_d[i] = d[i];
    }

    int cur_cnt = 0;
    for (int i=1; i<=n; i++) {
        if (x[i]) {
            cur_cnt++;
            new_d[i] = !new_d[i];
            for (int x:a[i]) {
                new_d[x] = !new_d[x];
            }
        }
    }
    
    bool ok = true;
    for (int i=1; i<=n; i++) {
        if (!new_d[i]) {
            ok = false;
        }
    }
    if (ok && cur_cnt<res_cnt) {
        res.clear();
        for (int i=1; i<=n; i++) {
            if (x[i]) res.push_back(i);
        }
        res_cnt = cur_cnt;
    }
}

void Try(int i) {
    for (int j=0; j<=1; j++) {
        x[i] = j;
        if (i==n) check();
        else Try(i+1);
    }
}

int32_t main(void) {
    FastIO;
    freopen("LAMPS.INP","r",stdin);
    freopen("LAMPS.OUT","w",stdout);
    cin >> n >> T;
    for (int i=1; i<=n; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i=1; i<=n; i++) {
        cin >> d[i];
    }
    if (n<=20) { // Subtask 1,2
        Try(1);
        cout << res_cnt << ' ';
        for (int x: res) cout << x << ' ';
        cout << endl;
    }
    return 0;
}