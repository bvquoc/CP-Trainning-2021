#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
using namespace std;

string s, res = "";

signed main(void) {
    FastIO;
    freopen("MULT17.INP","r",stdin);
    freopen("MULT17.OUT","w",stdout);
    cin >> s;
    int c = 0;
    FORD(i,s.length()-1,0) {
        int x = s[i]-'0';
        c += x*17;
        int l = c%2;
        c /= 2;
        char k = l+'0';
        res = k+res;
    }

    while (c!=0) {
        int m = c%2;
        char k = m+'0';
        res = k+res;
        c /= 2;
    }

    cout << res;
    return 0;
}