#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
// #define int long long
using namespace std;

using ii = pair <int, int>;
using ld = long double;

const int N = 10004;
string s;
vector <string> a;
vector <int> res;
bool isPrime[N+1];
bool mark[N+1];

void sieve() {
    for(int i = 0; i < N;++i) {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i < N; ++i) {
        if(isPrime[i] == true) {
            for(int j = i * i; j < N; j += i)
                isPrime[j] = false;
        }
    }
}

void cut() {
    int i = 0;
    while (i < s.size()) {
        if (!('0'<=s[i] && s[i]<='9') && i<s.size()-1) i++;
        if (!('0'<=s[i] && s[i]<='9')) continue;
        int j = i;
        while ('0'<=s[j] && s[j]<='9' && j<s.size()) j++;
        a.push_back(s.substr(i,j-i));
        i = j;
    }
}

void getAns(string x) {
    FOR(i,0,x.size()-1) {
        int cur = 0;
        FOR(j,i,x.size()-1) {
            cur *= 10;
            cur += (x[j]-'0');
            if (isPrime[cur] && !mark[cur]) {
                res.push_back(cur);
                mark[cur] = true;
            }
        }
    }
}

signed main(void) {
    FastIO;
    freopen("NGUYENTO.INP","r",stdin);
    freopen("NGUYENTO.OUT","w",stdout);
    cin >> s;
    cut();
    sieve();
    for (string x: a) {
        getAns(x);
    }

    cout << res.size() << endl;
    for (int x: res) cout << x << ' ';
    return 0;
}