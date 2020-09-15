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

int n, res;

string Dec_to_Bin(int x) {
    string s = "";
    while (x != 0) {
        s.push_back('0'+(x%2));
        x = x >> 1;
    }
    reverse(s.begin(),s.end());
    return s;
}

int getAns(string x) {
    int ans = 0, sz = x.length();
    FOR(i,0,sz-1) {
        ans += (x[i]-'0')*pow(2,sz-i-2);
    }
    return ans;
}

signed main(void) {
    FastIO;
    freopen("NUMSHIFT.INP","r",stdin);
    freopen("NUMSHIFT.OUT","w",stdout);
    cin >> n;
    string s = Dec_to_Bin(n), cur;
    signed sz = s.length();
    FOR(i,0,sz-1) {
        cur = "";
        FOR(j,i,i+sz) {
            cur += s[j%sz];
        }
        res = max(res, getAns(cur));
    }
    cout << res;
    return 0;
}