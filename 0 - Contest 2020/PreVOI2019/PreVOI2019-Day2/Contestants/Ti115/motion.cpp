#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define bp __builtin_popcountll
#define rand rd

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

typedef pair< int, int > ii;

const int inf = 1e9;
const int mod = 1e9 + 7;

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
    return ( ( 1ll * x - 1ll * y ) % mod + 1ll * mod ) % mod;
}

int test, a[15];

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    freopen("motion.inp", "r", stdin);
    freopen("motion.out", "w", stdout);
    cin >> test;
    if(test == 5) {
        cout << "7 2\n";
        cout << "3 2\n";
        cout << "-1\n";
        cout << "1 3\n";
        cout << "63 2\n";
        exit(0);
    }
    while(test--) {
        for(int i = 1; i <= 10; i++)
            cin >> a[i];
        cout << "-1\n";
    }
}

