// Ssusanoo

#include <bits/stdc++.h>
#define N 500000
#define MOD
#define LL long long
#define fi first
#define se second
#define MP make_pair
#define pii pair <int, int>
#define endl "\n"
#define Task "ODDCOIN"

using namespace std;

int ct[18] = {0, 1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};
int test, x, t, res;
int f[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);

    cin >> test;
    while ( test-- ) {
        cin >> x >> t;
        for (int i = 1; i <= t; i++) f[i] = 2e9 + 10;
        ct[17] = x;
        for (int i = 1; i <= t; i++)
            for (int j = 1; j <= 17; j++)
                if ( i >= ct[j] )
                    f[i] = min(f[i], f[i - ct[j]] + 1);
        cout << f[t] << endl;
    }

    return 0;
}
