#include <bits/stdc++.h>

#define elif else if
#define ii pair<int,int>
#define pb push_back
#define ll long long
#define FOR(i , a , b , c) for(int i = (a) ; i <= (b) ; i += (c))
#define FORD(i , a , b , c) for(int i = (a) ; i >= (b) ; i -= (c))
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int N = 2e3 + 1 , mod = 998244353;

string a[N];

int d[N] , c[N] , n , res;

void check() {
    string s = "";
    int odd = 0 , even = 0;
    FOR(i , 1 , n , 1) 
        s += a[c[i]];
    
    FOR(i , 0 , s.size() - 1 , 1) {
        if( (i + 1) % 2 == 0 )
            even += (s[i] - '0');
        else odd += (s[i] - '0');
    }

    if((odd - even) % 11 == 0) ++res;

    if(res >= mod) res -= mod;
}
void backtrack(int i) {
    FOR(j , 1 , n , 1) 
        if(d[j] == 0) {
            c[i] = j;
            if(i == n) 
                check();
            else {
                d[j] = 1;
                backtrack(i + 1);
                d[j] = 0;
            }
        }
}
void solve() {
    res = 0;
    cin >> n;

    FOR(i , 1 , n , 1) {
        cin >> a[i];
        d[i] = c[i] = 0;
    }
    
    backtrack(1);
    cout << res % mod << "\n";
}

main() {
    freopen("GIFT11.inp" , "r" , stdin);
    freopen("GIFT11.out" , "w" , stdout);
    FASTIO;
    
    int t ; cin >> t;

    while(t--) 
        solve();

    return 0;
}