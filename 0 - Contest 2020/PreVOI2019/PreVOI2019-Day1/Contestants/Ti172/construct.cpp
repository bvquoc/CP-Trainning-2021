// Ssusanoo

#include <bits/stdc++.h>
#define N 1000010
#define MOD
#define LL long long
#define fi first
#define se second
#define MP make_pair
#define pii pair <int, int>
#define endl "\n"
#define Task "construct"

using namespace std;

int test, n, m, top;
long long res;
long long a[N];
int s[N];

long long calc(int l, int r) {
    top = 0; res = 0;
    for (int i = l; i <= r; i++) {
        long long mx = 0;
        while ( top && a[s[top]] > a[i] ) {
            mx = max(mx, a[s[top]]);
            top --;
        }
        if ( mx ) res += (mx - a[i]);
        s[++top] = i;
    }
    res += a[s[top]];
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);

    cin >> test;
    while ( test-- ) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        while ( m-- ) {
            int type; cin >> type;
            if ( type == 1 ) {
                int l, r, k; cin >> l >> r >> k;
                for (int i = l; i <= r; i++) a[i] += k;
            }
            else {
                int l, r; cin >> l >> r;
                cout << calc(l, r) << endl;
            }
        }
    }

    return 0;
}
