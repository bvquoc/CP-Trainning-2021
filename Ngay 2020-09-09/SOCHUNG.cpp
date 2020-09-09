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
using ld = long double;

int n, m, res = 0;
multiset <int> a, b;

signed main(void) {
    FastIO;
    freopen("SOCHUNG.INP","r",stdin);
    freopen("SOCHUNG.OUT","w",stdout);
    cin >> n >> m;
    FOR(i,1,n) {
        int x;
        cin >> x;
        a.insert(x);
    }
    FOR(i,1,m) {
        int x;
        cin >> x;
        b.insert(x);
    }

    for (int x: a) {
        if (b.count(x)) res++;
    }
    cout << res;
    return 0;
}