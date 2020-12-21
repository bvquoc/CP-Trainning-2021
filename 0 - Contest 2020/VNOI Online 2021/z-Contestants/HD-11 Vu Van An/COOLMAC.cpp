//
#include <bits/stdc++.h>

using namespace std;
#define task        "COOLMAC"
#define maxn        100000
#define maxm
#define maxs
#define p_b         push_back
#define fs          first
#define sc          second
#define oo          2000000000
#define mod         1000000007
#define ll          long long

typedef pair <int, int> II;
typedef pair <II, int> III;

int m, n, id, d;
II a[maxn + 5];

void sol() {
    int res = 1;
    while (1) {
        if (a[id].sc == 100000) {
            cout << res;
            return;
        }
        int n_id = 0, d = 0;
        for (int i = id + 1; i <= m; i++) {
            if (a[i].fs > a[id].sc)
                break;
            else {
                if (a[i].sc > d) {
                    d = a[i].sc;
                    n_id = i;
                }
            }
        }
        if (d == 0) {
            cout << -1;
            return;
        }
        ++res;
        id = n_id;
    }
}

//
int main() {
    freopen (task".inp", "r", stdin);
    freopen (task".out", "w", stdout);
    ios::sync_with_stdio (false);
    cin.tie(0);
    cout.tie(0);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i].fs >> a[i].sc;
    }
    sort (a + 1, a + m + 1);
    int n_m = 0;
    a[m + 1].fs = oo;
    for (int i = 1; i <= m; i++) {
        if (a[i].fs != a[i + 1].fs)
            a[++n_m] = a[i];
    }
    m = n_m;
    cin >> n;
    int temp = maxn;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        temp = min (temp, t);
    }
    id = 0, d = 0;
    for (int i = 1; i <= m; i++) {
        if (a[i].fs <= temp && a[i].sc >= temp) {
            if (a[i].sc > d) {
                d = a[i].sc;
                id = i;
            }
        }
        if (a[i].fs > temp)
            break;
    }
    if (id == 0)
        cout << -1;
    else {
        sol();
    }
}
