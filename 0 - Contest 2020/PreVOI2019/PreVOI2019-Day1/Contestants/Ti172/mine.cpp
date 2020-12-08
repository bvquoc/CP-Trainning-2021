// Ssusanoo

#include <bits/stdc++.h>
#define N 100
#define mod 1000003
#define LL long long
#define fi first
#define se second
#define MP make_pair
#define pii pair <int, int>
#define endl "\n"
#define Task "mine"

using namespace std;

int n, m, cnt, res;
int a[N], b[N], d[N], f[N];

bool check(int x) {
    for (int i = 0; i < n; i++)
        if ( (x >> i) & 1 ) b[++cnt] = i + 1;
        else {
            if ( !cnt ) return 0;
            if ( a[i + 1] - a[b[cnt]] > m ) return 0;
            cnt --;
        }
    return cnt == 0;
}

int sub1() {
    for (int i = 1; cnt = 0, i < (1 << n); i++) {
        if ( __builtin_popcount(i) != n / 2 ) continue;
        if ( !((i >> 0) & 1) ) continue;
        if ( check(i) ) res ++;
    }
    return res % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);

    cin >> n >> m; n *= 2;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if ( n <= 20 ) return cout << sub1(), 0;
    cout << 0;

    return 0;
}
