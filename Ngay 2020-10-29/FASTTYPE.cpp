#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define endl '\n'
// #define int long long
using namespace std;

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

int k, m, q;
string s;

signed main(void) {
    FastIO;
    freopen("FASTTYPE.INP","r",stdin);
    freopen("FASTTYPE.OUT","w",stdout);
    cin >> k >> m;
    cin >> s;
    cin >> q;
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        string tmp = s.substr(a,b-a);
        s.insert(c,tmp);
        while (s.size() > m) s.pop_back();
    }
    FOR(i,0,k-1) cout << s[i];
    return 0;
}