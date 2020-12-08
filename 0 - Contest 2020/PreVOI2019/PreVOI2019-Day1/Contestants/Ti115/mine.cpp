#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair< int, int > ii;

const int mod = 1000003;
const int inf = 1e9;

int add(int x, int y) {
    if(1ll * x + 1ll * y >= mod)
        return (1ll * x + 1ll * y) % mod;
    else
        return (1ll * x + 1ll * y);
}

int mul(int x, int y) {
    if(1ll * x * 1ll * y >= mod)
        return (1ll * x * 1ll * y) % mod;
    else
        return (1ll * x * 1ll * y);
}

int del(int x, int y) {
    return ( (1ll * x - 1ll * y) % mod + mod ) % mod;
}

int binpow(int x, int y) {
    if(y == 0) return 1;
    else if(y == 1) return x;
    else {
        int sum = binpow(x, y / 2);
        sum = mul( sum, sum );
        if(y % 2) sum = mul( sum, x );
        return sum;
    }
}

const int N = 2e3 + 5;

int n, m, a[2 * N], pre[2 * N], cat[N], dp[2 * N];

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    freopen("mine.inp", "r", stdin);
    freopen("mine.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= 2 * n; i++)
        cin >> a[i];
    if(m == 1000000) {
        int A = binpow( n + 1, mod - 2 ), prod = 1;
        for(int i = 1; i <= 2 * n; i++)
            A = mul( A, i );
        for(int i = 1; i <= n; i++)
            prod = mul( prod, i );
        A = mul( A, binpow( prod, mod - 2 ) );
        A = mul( A, binpow( prod, mod - 2 ) );
        cout << A << "\n";
        exit(0);
    }
    pre[0] = 1;
    for(int i = 1; i <= 2 * n; i++)
        pre[i] = mul( pre[ i - 1 ], i );
    cat[0] = 1;
    for(int i = 1; i <= n; i++) {
        int coef = binpow( i + 1, mod - 2 );
        int sum = mul( coef, pre[2 * i] );
        int prod = binpow( pre[i], mod - 2 );
        sum = mul( sum, prod ); sum = mul( sum, prod );
        cat[i] = sum;
    }
    dp[0] = 1;
    for(int i = 2; i <= 2 * n; i += 2) {
        for(int j = 1; j <= i; j += 2) {
            if( a[i] - a[j] <= m ) {
                int lmao = (i - j - 1) / 2;
                dp[i] = add( dp[i], mul( dp[j - 1], cat[ lmao ]) );
            }
        }
    }
    cout << dp[ 2 * n ];
}

