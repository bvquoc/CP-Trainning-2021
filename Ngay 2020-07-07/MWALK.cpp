#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int res;
string s, x="UEOAIueoai";

int32_t main(void) {
    FastIO;
    freopen("MWALK.INP","r",stdin);
    freopen("MWALK.OUT","w",stdout);
    int T; cin >> T;
    while (T--) {
        cin >> s;
        res = 0;
        for (char ch: s) {
            for (char cs: x) {
                if (ch == cs) {
                    res++;
                    break;
                }
            }
        }
        cout << res << '\n';
    }
    
    return 0;
}