#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int X, Y, s, T;
int res = 0;

int32_t main(void) {
    FastIO;
    freopen("FROG.INP","r",stdin);
    freopen("FROG.OUT","w",stdout);
    cin >> X >> Y >> s >> T;
    for (int i=X; i<=X+s; i++) {
        for (int j=Y;j<=Y+s; j++) {
            if (i+j<=T) {
                res++;
            }
        }
    }
    cout << res;
    return 0;
}