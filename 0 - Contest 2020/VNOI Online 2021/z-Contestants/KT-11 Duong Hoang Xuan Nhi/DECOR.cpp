#include <bits/stdc++.h>
#define int64_t long long
using namespace std;

const int N = 5e5 + 5;

int n, m, k;

namespace Sub1 {
string s;

void solve() {
    cin >> s;

    int64_t l = 0, r = -1;
    int64_t i = 0;

    while(i < n) {
        if(s[i] == '0') ++i;
        else {
            int64_t p = i + 1;
            while(p < n && s[p] == '1')
                p++;

            if(r - l < p - (i + 1))
                l = i + 1,
                r = p;

            i = p;
        }
    }

    if(l > r) cout << -1 << '\n';
    else cout << l << ' ' << r << '\n';
}

} //namespace Sub1()

namespace Sub2 {
string s;
int d[N];

void solve() {
    cin >> s;

    d[0] = (s[0] - '0' + 1) % 2;
    for(int i = 1; i < n; ++i)
        if(s[i] == '0')
            d[i] = d[i-1] + 1;
        else d[i] = d[i-1];

    int64_t l = 0, r = -1, ans = -1;
    int64_t i = 0, j = i + 1;

    while(i < n && j < n) {
        if(d[j] - d[i] + ((s[i] - '0' + 1) % 2) > k) {
            if(ans < j - i)
                ans = j - i,
                l = i + 1,
                r = j;

            i++;
        }
        else {
            if(ans < j - i)
                ans = j - i,
                l = i + 1,
                r = j + 1;

            j++;
        }
    }

    if(l > r) cout << -1 << '\n';
    else cout << l << ' ' << r << '\n';
}

} //namespace Sub2()

int main() {
#ifdef DN
    //freopen("in.txt", "r", stdin);
#endif
    freopen("DECOR.inp", "r", stdin);
    freopen("DECOR.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;

    if(m == 0) {
        if(k == 0) Sub1::solve();
        else Sub2::solve();
    }
    else cout << -1;

    return 0;
}
