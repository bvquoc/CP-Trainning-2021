#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n, w, h, res = 0;

int32_t main(void) {
    FastIO;
    freopen("RGOLDEN.INP","r",stdin);
    freopen("RGOLDEN.OUT","w",stdout);
    cin >> n;
    while (n--) {
        bool isRGOLDEN = false;
        cin >> w >> h;
        if (1.6<=double(w)/h && double(w)/h<=1.7) {
            isRGOLDEN = true;
        }
        if (1.6<=double(h)/w && double(h)/w<=1.7) {
            isRGOLDEN = true;
        }
        if (isRGOLDEN) {
            res++;
        }
    }
    cout << res;
    return 0;
}