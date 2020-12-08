#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair< int, int > ii;

const int inf = 1e9;
const int N = 1e6 + 5;

int n, m, lz[4 * N], sum[N];
ii it[4 * N];

string s;

void lzupdate(int k, int l, int r) {
    if(lz[k]) {
        it[k].fi += lz[k];
        if(l != r) {
            lz[k << 1] += lz[k];
            lz[k << 1 | 1] += lz[k];
        }
    }
    lz[k] = 0;
}

void build_tree(int k, int l, int r) {
    if(l == r) {
        int val;
        if(s[l] == '(')
            val = 1;
        else
            val = -1;
        it[k] = mp(sum[l], val);
        return ;
    }
    int md = (l + r) >> 1;
    build_tree(k << 1, l, md);
    build_tree(k << 1 | 1, md + 1, r);
    it[k].fi = min(it[k << 1].fi, it[k << 1 | 1].fi);
    it[k].se = it[k << 1].se + it[k << 1 | 1].se;
}

void updatemn(int k, int l, int r, int L, int R, int val) {
    lzupdate(k, l, r);
    if(R < l || r < L || L > R) return ;
    if(L <= l && r <= R) {
        lz[k] += val;
        lzupdate(k, l, r);
        return ;
    }
    int md = (l + r) >> 1;
    updatemn(k << 1, l, md, L, R, val);
    updatemn(k << 1 | 1, md + 1, r, L, R, val);
    it[k].fi = min(it[k << 1].fi, it[k << 1 | 1].fi);
}

void updatepos(int k, int l, int r, int L, int R, int val) {
    lzupdate(k, l, r);
    if(R < l || r < L || L > R) return ;
    if(L <= l && r <= R) {
        it[k].se += val;
        return ;
    }
    int md = (l + r) >> 1;
    updatepos(k << 1, l, md, L, R, val);
    updatepos(k << 1 | 1, md + 1, r, L, R, val);
    it[k].se = it[k << 1].se + it[k << 1 | 1].se;
}

ii get(int k, int l, int r, int L, int R) {
    lzupdate(k, l, r);
    if(R < l || r < L || L > R) return mp( inf, 0 );
    if(L <= l && r <= R)
        return it[k];
    int md = (l + r) >> 1;
    ii le = get(k << 1, l, md, L, R);
    ii ri = get(k << 1 | 1, md + 1, r, L, R);
    return mp( min(le.fi, ri.fi), le.se + ri.se );
}

vector< int > lmao;

string t[N];

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    freopen("fixstr.inp", "r", stdin);
    freopen("fixstr.out", "w", stdout);
    cin >> s;
    n = s.length();
    s = "+" + s;
    for(int i = 1; i <= n; i++) {
        if(s[i] == '(')
            sum[i] = 1;
        else
            sum[i] = -1;
        sum[i] += sum[i - 1];
    }
    build_tree(1, 1, n);
    cin >> m;
    t[0] = s;
    lmao.pb(0);
    if(n <= 1000 && m <= 1000) {
        for(int i = 1; i <= m; i++) {
            char ch; int pos;
            cin >> ch;
            if(ch == 'C') {
                cin >> pos;
                if(s[pos] == '(')
                    s[pos] = ')';
                else
                    s[pos] = '(';
                lmao.pb(i);
                t[i] = s;
            }
            else if(ch == 'Q') {
                int l, r, res = 0, mn = inf, ans = 0;
                cin >> l >> r;
                for(int k = l; k <= r; k++) {
                    if(s[k] == '(')
                        res++;
                    else
                        res--;
                    mn = min(mn, res);
                }
                if(mn < 0) {ans += abs(mn); res += abs(mn);}
                if(res > 0) ans += res;
                cout << ans << "\n";
            }
            else {
                cin >> pos;
                int pter = 0;
                for(int j = 0; j < lmao.size(); j++) {
                    if(lmao[j] < pos)
                        pter = j;
                }
                s = t[pter];
                lmao.pb(i);
                t[i] = s;
            }
        }
        exit(0);
    }
    else {
        for(int i = 1; i <= m; i++) {
            char ch; int pos;
            cin >> ch;
            if(ch == 'C') {
                cin >> pos;
                if(s[pos] == '(') {
                    s[pos] = ')';
                    updatepos(1, 1, n, pos, pos, -2);
                    updatemn(1, 1, n, pos, n, -2);
                }
                else {
                    s[pos] = '(';
                    updatepos(1, 1, n, pos, pos, 2);
                    updatemn(1, 1, n, pos, n, 2);
                }
            }
            else {
                int l, r, res = 0;
                cin >> l >> r;
                ii ans = get(1, 1, n, l, r);
                if(l > 1)
                    ans.fi -= get(1, 1, n, l - 1, l - 1).fi;
                if(ans.fi < 0) {res += abs(ans.fi);ans.se += abs(ans.fi);}
                if(ans.se > 0) res += ans.se;
                cout << res << "\n";
            }
        }
    }
}

