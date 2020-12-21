#include <bits/stdc++.h>
#define task "GIFT11"
typedef long long int ll;
using namespace std;

const ll mod = 998244353;

void add(ll &a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
}

const int N = 2010;
ll n, a[N], per[N];

int countNum(int a) {
    int cnt = 0;
    while (a) {
        cnt ^= 1;
        a /= 10;
    }
    return cnt;
}

void sub2(void) {
    ll chan = 0, le = 0;
    for (int i = 1; i <= n; ++i) {
        ll p = a[i], cnt = 0;
        while (p) {
            cnt ^= 1;
            if (cnt & 1) le += p % 10;
            else chan += p % 10;
            p /= 10;
        }
    }
    if (abs(chan - le) % 11) cout << 0 << '\n';
    else {
        ll res = 1;
        for (int i = 1; i <= n; ++i) res = res * i % mod;
        cout << res << '\n';
    }
}

ll Le[N], Chan[N], Cnt[N];

void pre(void) {
    for (int i = 1; i <= n; ++i) {
        Le[i] = Chan[i] = Cnt[i] = 0;
        ll p = a[i], cnt = 0;
        while (p) {
            Cnt[i] ++;
            cnt ^= 1;
            if (cnt & 1) Le[i] += p % 10;
            else Chan[i] += p % 10;
            p /= 10;
        }
    }
}

void sub1(void) {
    pre();
    ll res = 0;
    for (int i = 1; i <= n; ++i) per[i] = i;
    do {
        ll chan = 0, le = 0, cnt = 0;
        for (int i = n; i >= 1; --i) {
            if (cnt & 1) {
                le += Chan[per[i]];
                chan += Le[per[i]];
            }
            else {
                le += Le[per[i]];
                chan += Chan[per[i]];
            }
            cnt += Cnt[per[i]];
        }
//        cerr << chan << ' ' << le << endl;
        if (abs(chan - le) % 11 == 0) add(res, 1);
    } while (next_permutation(per + 1, per + n + 1));
    cout << res << '\n';
}

int main() {
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T--) {
        cin >> n;
        bool checkSub2 = true;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if (countNum(a[i]) & 1) checkSub2 = false;
        }
        if (checkSub2) sub2();
        else sub1();
    }
    return 0;
}

