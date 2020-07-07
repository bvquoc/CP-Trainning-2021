#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n;
string s;

int32_t main(void) {
    FastIO;
    freopen("FNAME.INP","r",stdin);
    freopen("FNAME.OUT","w",stdout);
    cin >> n;
    while (n--) {
        cin >> s;
        int pos = 0, cnt1 = 0, cnt2 = 0;
        while (true) { // find SUVO
            size_t found = s.find("SUVO", pos);
            if (found!=std::string::npos) {
                // cout << found+1 << ' ';
                pos = found + 1;
                cnt1++;
            } else break;
        }
        pos = 0;
        while (true) { // find SUVO
            size_t found = s.find("SUVOJIT", pos);
            if (found!=std::string::npos) {
                // cout << found+1 << ' ';
                pos = found + 1;
                cnt2++;
            } else break;
        }
        cnt1 -= cnt2;
        cout << "SUVO = " << cnt1 << ", ";
        cout << "SUVOJIT = " << cnt2 << '\n';
    }
    return 0;
}