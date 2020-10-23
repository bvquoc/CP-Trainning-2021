#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
#define int long long
using namespace std;

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int  MOD = 1000000007;

int pw(int m,int n) {
    int ans = 1;
    while (n != 0) {
        if (n%2 != 0) ans = ans*m % MOD;
        n /= 2;
        m = m*m % MOD;
    }
    return ans;
}

int k, n; string a;

signed main(void) {
    FastIO;
    freopen("NGUHANH.inp","r",stdin);
    freopen("NGUHANH.out","w",stdout);
    cin >> a >> k; n = a.length();
    
    int res = 0;
    for (int i=0; i<n; i++) {
        if (a[i]=='0' || a[i]=='5') {
            res=(res+pw(2,i))%MOD;
        }
    }

    int t1 = pw((pw(2,n)-1),MOD-2);
    int t2 = (t1*(pw(2,k*n)-1)) % MOD;
    res = (res*t2) % MOD;
    cout << res;
    return 0;
}