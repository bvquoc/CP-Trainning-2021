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

int res = 0;
int C[1000], sz;
string s;

signed main(void) {
    FastIO;
    freopen("MOLECULAR.INP","r",stdin);
    freopen("MOLECULAR.OUT","w",stdout);

    C['H'] = C['h'] = 1;
    C['O'] = C['o'] = 16;
    C['N'] = C['n'] = 14;
    C['C'] = C['c'] = 12;

    cin >> s;
    sz = s.length();
    s.push_back('A');

    int i = 0;
    while (i<sz) {
        if (!('0'<=s[i+1] && s[i+1]<='9')) {
            res += C[s[i++]];
            continue;
        }
        int j = i+1, cur = s[j]-'0';
        while ('0'<=s[j+1] && s[j+1]<='9' && j+1<sz) {
            j++;
            cur *= 10;
            cur += s[j]-'0';
        }
        res += C[s[i]]*cur;
        i = j+1;
    }

    cout << res;
    return 0;
}