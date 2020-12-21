#include<bits/stdc++.h>
#define ll int
//<(")
using namespace std;

typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;

const ll siz = 1e5 + 10;
const ll mod = 1e9 + 9;
const ll base = 32;
const ll MAXX = 1e18;
const ll off = 300;

void con_meo_ngoo() {
    //khong lam gi ca
}

ll n, m, k;
ll state[siz];
ll par[siz];
ll used[siz];

ll getPar(ll node) {
    if (par[node] == node) {
        return node;
    }
    return par[node] = getPar(par[node]);
}

void join(ll a, ll b) {
    ll x = getPar(a), y = getPar(b);
    if (x == y) {
        return;
    }
    par[x] = y;
}

vector<ll> hold[siz];
ll ou[siz], in[siz];
bool cnt[siz];
string s;

ll check(ll len) {
//    for (ll i = 0; i <= n; i++) {
//        cerr << in[i] << ' ' << ou[i] << '\n';
//    }

    for (ll i = 1; i <= len; i++) {
        in[getPar(i)] += ((s[i] - '0') == 0);
    }
    for (ll i = len + 1; i <= n; i++) {
        ou[getPar(i)] += ((s[i] - '0') == 1);
    }

//    for (ll i = 1; i <= n; i++) {
//        cerr << in[i] << ' ' << ou[i] << '\n';
//    }

    ll sum = 0;
    for (ll i = 1; i <= len; i++) {
        ll c = getPar(i);
        if (!used[c]) {
            used[c] = 1;
            sum += (max(in[c], ou[c]) - ou[c]);
        }
    }

    //cerr << sum << '\n';

    if (sum <= k) {
        return 1;
    }
    for (ll i = 2; i + len - 1 <= n; i++) {
        ll a = getPar(i - 1), b = getPar(i + len - 1);
        sum -= (max(in[a], ou[a]) - ou[a]);

        in[a] -= ((s[i - 1] - '0') == 0);
        ou[a] += ((s[i - 1] - '0') == 1);
        sum += (max(in[a], ou[a]) - ou[a]);

        sum -= (max(in[b], ou[b]) - ou[b]);
        ou[b] -= ((s[i + len - 1] - '0') == 1);
        in[b] += ((s[i + len - 1] - '0') == 0);
        sum += (max(in[b], ou[b]) - ou[b]);

        if (sum <= k) {
            return i;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DECOR.INP", "r", stdin);
    freopen("DECOR.OUT", "w", stdout);
    con_meo_ngoo();
    cin >> n >> m >> k;
    cin >> s;
    for (ll i = 1; i <= n; i++) {
        par[i] = i;
    }
    s = ' ' + s;
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        join(a, b);
    }
    for (ll i = 1; i <= n; i++) {
        hold[getPar(i)].push_back(i);
    }
    ii pri = ii(-1, -1);
    ll le = k + 1, ri = n;
    while (le <= ri) {
        ll mid = (le + ri) / 2;
        //cerr << mid << '\n';
        //check(mid) << '\n';
        for (ll i = 0; i <= n; i++) {
            in[i] = ou[i] = 0;
            used[i] = false;
        }
        ll val = check(mid);
        if (val != -1) {
            //cerr << mid << '\n';
            pri = ii(val, val + mid - 1);
            le = mid + 1;
        }
        else {
            ri = mid - 1;
        }
    }
    if (pri.first == -1) {
        cout << -1 << '\n';
    }
    else {
        cout << pri.first << ' ' << pri.second << '\n';
    }
    return 0;
}
