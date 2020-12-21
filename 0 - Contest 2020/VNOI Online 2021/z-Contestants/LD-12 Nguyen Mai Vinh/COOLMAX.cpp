#include<bits/stdc++.h>
#define ll long long
//<(")
using namespace std;

typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;

const ll siz = 3e3 + 10;
const ll mod = 1e9 + 7;
const ll base = 32;
const ll MAXX = 1e5;
const ll maa = 1e18;
const ll off = 300;

void con_meo_ngoo() {
    //khong lam gi ca
}

ll n, m;
vector<ii> hold;
ll mi = MAXX;

bool check(ii a, ii b) {
    return (b.first <= a.second + 1) && (b.second >= a.second + 1);
}

ll res[siz][siz];

ll dp(ll pos, ll pre) {
    if (pos >= m) {
        return (hold[pre].second == MAXX) ? 0 : maa;
    }
    ll &ans = res[pos][pre];
    if (ans != -1) {
        return ans;
    }
    ans = dp(pos + 1, pre);
    if (check(hold[pre], hold[pos])) {
        ans = min(ans, dp(pos + 1, pos) + 1);
    }
    return ans;
}

void sub2() {
    memset(res, -1, sizeof(res));
    ll ans = maa;
    for (ll i = 0; i < m; i++) {
        if (hold[i].first <= mi) {
            //cerr << i << '\n';
            ans = min(ans, dp(i + 1, i) + 1);
        }
    }
    if (ans >= maa) {
        cout << -1 << '\n';
    }
    else {
        cout << ans << '\n';
    }
}

ll pri[100010];

//ll go(ll pos) {

//}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("COOLMAX.INP", "r", stdin);
    freopen("COOLMAX.OUT", "w", stdout);
    con_meo_ngoo();
    cin >> m;
    hold.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> hold[i].first >> hold[i].second;
    }
    sort(hold.begin(), hold.end());
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        mi = min(mi, x);
    }

    //sub2();

    if (n <= 10 && m <= 16) {
        ll ans = maa;
        for (ll i = 1; i < (1 << m); i++) {
            vector<ii> sub;
            for (int j = 0; j < m; j++) {
                if ((i & (1 << j)) != 0) {
                    sub.push_back(hold[j]);
                }
            }
            ii cur = sub[0];
            for (int i = 0; i < (int)sub.size(); i++) {
                if (check(cur, sub[i])) {
                    cur.second = sub[i].second;
                }
            }
            if (cur.first <= mi && cur.second == MAXX) {
                ans = min(ans, (ll)sub.size());
            }
        }
        if (ans >= maa) {
            cout << -1 << '\n';
        }
        else {
            cout << ans << '\n';
        }
        return 0;
    }

    if (n <= 3000 && m <= 3000) {
        sub2();
        return 0;
    }

    return 0;
}
