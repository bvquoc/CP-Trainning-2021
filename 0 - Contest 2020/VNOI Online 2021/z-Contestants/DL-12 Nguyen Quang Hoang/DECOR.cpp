#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int b[500002], dd[500002], cnt;
string s, t;
int ans2l, ans2r, ans3l, ans3r;
vector<int> a[500002];
void sub1() {
    int val = 0, ansl = -1, ansr = -1, res = 0;
    for(int i = 1; i <= n; ++ i) {
        if(s[i] == '1') ++ res;
        else {
            if(res > val) {
                val = res;
                ansl = i - res;
                ansr = i - 1;
            }
            res = 0;
        }
    }
    if(val == 0) cout << -1;
    else cout << ansl << ' ' << ansr;
}
bool check2(int x) {
    for(int i = 1; i + x - 1 <= n; ++ i) {
        int j = i + x - 1;
        if(b[j] - b[i - 1] <= k) {
            ans2l = i;
            ans2r = j;
            return true;
        }
    }
    return false;
}
void sub2() {
    for(int i = 1; i <= n; ++ i) {
        if(s[i] == '0') b[i] = b[i - 1] + 1;
        else b[i] = b[i - 1];
    }
    int l = 1, r = n, mid = (l + r) / 2;
    while(l != mid && mid != r) {
        if(check2(mid)) l = mid;
        else r = mid - 1;
        mid = (l + r) / 2;
    }
    bool ok = true;
    for(int i = r; i >= l; -- i) {
        if(check2(i)) {
            cout << ans2l << ' ' << ans2r;
            ok = false;
            break;
        }
    }
    if(ok) cout << -1;
}
bool can_get(int u, int par, int lf, int rt) {
    if(u < lf || u > rt) {
        if(t[u] == '1') return true;
    }
    dd[u] = cnt;
    for(int v : a[u]) {
        if(v == par) continue;
        if(dd[v] == cnt) continue;
        if(can_get(v, u, lf, rt)) {
            swap(t[v], t[u]);
            return true;
        }
    }
    return false;
}
bool check(int x) {
    t = s;
    int num_light = k;
    for(int i = 1; i <= n; ++ i) dd[i] = 0;
    cnt = 0;
    for(int i = 1; i + x - 1 <= n; ++ i) {
        int j = i + x - 1;
        bool ok = true;
        for(int u = i; u <= j; ++ u) {
            bool ok2 = true;
            if(t[u] == '0') {
                ++ cnt;
                if(can_get(u, u, i, j)) ok2 = false;
                else if(num_light > 0) {
                    -- num_light;
                    ok2 = false;
                }
            }
            if(ok2) {
                ok = false;
                break;
            }
        }
        if(ok) {
            ans3l = i;
            ans3r = j;
            return true;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //if(fopen("test.inp", "r"))
    //    freopen("test.inp", "r", stdin);
    //else {
        #define file "DECOR"
        freopen(file".INP", "r", stdin);
        freopen(file".OUT", "w", stdout);
    //}
    cin >> n >> m >> k;
    cin >> s;
    s = ' ' + s;
    for(int i = 1; i <= m; ++ i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    if(m == 0 && k == 0) {
        sub1();
        return 0;
    }
    else if(m == 0) {
        sub2();
        return 0;
    }
    //cout << 1 << '\n';
    int l = 1, r = n, mid = (l + r) / 2;
    while(l != mid && mid != r) {
        //cout << mid << '\n';
        if(check(mid)) l = mid;
        else r = mid - 1;
        mid = (l + r) / 2;
    }
    for(int i = r; i >= l; -- i) {
        if(check(i)) {
            cout << ans3l << ' ' << ans3r;
            return 0;
        }
    }
    cout << -1;
    return 0;
}

