#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n, d;
string s;

int32_t main(void) {
    FastIO;
    freopen("LOGO.INP","r",stdin);
    freopen("LOGO.OUT","w",stdout);
    int T; cin >> T;
    while (T--) {
        int X = 0, Y = 0;
        cin >> n;
        while (n--) {
            cin >> s >> d;
            cout << s << ' ' << d << '\n';
        }
    }
    return 0;
}