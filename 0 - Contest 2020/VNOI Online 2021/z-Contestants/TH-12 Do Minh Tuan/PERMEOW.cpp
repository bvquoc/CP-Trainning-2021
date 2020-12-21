#include <bits/stdc++.h>
#define tkn "PERMEOW"
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;
const ll mod = 1e9 + 7;
int n;
int a[N], b[N];
int cnt[17];
ll ans;
void input() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        cin >> b[i];
}
bool checkSub1() {
    for (int i = 1; i <= n; i++)
        if (a[i] != b[i]) return 0;
    return 1;
}
void sub1() {
    bool ok;
    while (true) {
        ok = 0;
        for (int i = 1; i < n; i++)
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                ans++;
                ok = 1;
            }
        if (!ok) break;
    }
    cout << ans;
}

bool checkSub2() {
    for (int i = 1; i <= n; i++)
        if (a[i] != i) return 0;
    for (int i = 1; i <= n; i++)
        if (b[i] != n - i + 1) return 0;
    return 1;
}
bool chosen[N];
int sv[N];
int f[N];
void bf(int id) {
    if (id == n + 1) {
        for (int i = 1; i <= n; i++) {
            cerr << sv[i];
            f[i] = sv[i];
        }
        cerr << ' ';
        int res = 0;
        bool ok;
        while (true) {
            ok = 0;
            for (int i = 1; i < n; i++)
                if (f[i] > f[i + 1]) {
                    swap(f[i], f[i + 1]);
                    res++;
                    ok = 1;
                }
            if (!ok) break;
        }
        cnt[res]++;
        cerr << res << '\n';
    }
    for (int i = 1; i <= n; i++)
        if (!chosen[i]) {
            sv[id] = i;
            chosen[i] = 1;
            bf(id + 1);
            chosen[i] = 0;
        }
}
void attempt() {
    bf(1);
    for (int i = 0; i <= 15; i++)
        cerr << cnt[i] << '\n';
}
void sub2() {
    //attempt();
    cout << 1;
}
int main() {
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

    return 0;
}
