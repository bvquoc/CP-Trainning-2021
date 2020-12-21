#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

const int N = 1e5 + 5;

int n, q, k = N;
pii a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("COOLMAC.inp", "r", stdin);
    freopen("COOLMAC.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i].fi >> a[i].se;
    }
    cin >> q;
    while (q--){
        int x; cin >> x; k = min(k, x);
    }
    sort(a + 1, a + 1 + n);
    priority_queue <int> pq;
    int idx = 0, ans = 0;
    while (k <= 100000){
        while (idx + 1 <= n && a[idx + 1].fi <= k){
            pq.push(a[++idx].se);
        }
        if (pq.top() <= k){
            cout << -1 << endl;
            return 0;
        }
        ans++;
        k = pq.top() + 1;
    }
    cout << ans << endl;
}

/*
Repeatedly choose the range with maximum .se such that (its .fi <= k), then update k to (the maximum .se + 1).
*/

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/
