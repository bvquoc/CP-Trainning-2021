///....DH....///
#include <bits/stdc++.h>
#define task                "FIXSTR"
#define fi(a)               freopen(a, "r", stdin)
#define fo(a)               freopen(a, "w", stdout)

#define pii                 pair<int, int>
#define ft                  first
#define sd                  second
#define mp                  make_pair

#define pb                  push_back
#define pf                  push_front
#define popb                pop_back
#define popf                pop_front

#define reset(a, x)         memset(a, x, sizeof(a))
#define For(i, s, n, m)     for(int i = s; i <= n; i += m)
#define Ford(i, s, n, m)    for(int i = s; i >= n; i -= m)

using namespace std;

template <typename R, typename D> inline void Min(R &a, D b) {
    if(a>b)
        a=b;
}
template <typename D, typename R> inline void Max(D &a, R b) {
    if(a<b)
        a=b;
}

/** MOD **/                 const long long mod = 1e9 + 7;
/** size of array **/       const int maxn = 10005;

int d[maxn], m, pos, l, r;
char c;
string s, sta[maxn];

int weight() {
    int res = 0;
    d[l - 1] = 0;
    for(int i = l; i <= r; i++) {
        d[i] = d[i - 1] + ((s[i] == '(') ? 1 : (-1));
        if(d[i] < 0)
            res++, d[i] = 0;
    }
    if(d[r] > 0)
        res += d[r];
    return res;
}

void sub1() {
    sta[0] = s;
    for(int i = 1; i <= m; i++) {
        cin >> c;
        if(c == 'C') {
            cin >> pos;
            if(s[pos] == '(')
                s[pos] = ')';
            else
                s[pos] = '(';
        } else if(c == 'U') {
            cin >> pos;
            s = sta[pos - 1];
        } else {
            cin >> l >> r;
            cout << weight() << "\n";
        }
        sta[i] = s;
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
    cin >> s;
    s = ' ' + s;
    cin >> m;
    sub1();
}
