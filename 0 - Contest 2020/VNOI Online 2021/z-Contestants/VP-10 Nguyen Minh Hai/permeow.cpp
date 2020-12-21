#include<bits/stdc++.h>

#define ll long long
#define st first
#define nd second

using namespace std;

typedef pair< int , int > ii;
const int maxn = 2e5 + 2 ;
const int mod = 1e9 + 7 ;
const int oo = 1e9 ;

void input() {
    #define name "permeow"
	if (fopen(name".inp" , "r") ) {
        freopen(name".inp" , "r" , stdin) ;
        freopen(name".out" , "w" , stdout) ;
	}
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

int n ;
int a[maxn] , b[maxn] ;

namespace subtask1 {
    int f[maxn] ;

    void update (int p) {
        for (int i = p ; i > 0 ; i -= i & -i) f[i] ++ ;
    }

    ll get (int p) {
        ll ans =  0 ;
        for (int i = p ; i <= n ; i += i & -i) ans += f[i] ;
        return ans ;
    }

    void solve1() {
        ll res = 0 ;
        for (int i = 1 ; i <= n ; ++ i) {
            res += get(a[i]) ;
            update(a[i]) ;
        }
        cout << res % mod ;
    }

    int p[maxn] ;

    void solve3() {
        ll res = 0 ;
        for (int i = 1 ; i <= n ; ++ i) p[i] = i ;
        do {
            bool ok1 = true , ok2 = true ;
            for (int i = 1 ; i <= n ; ++ i) {
                if (p[i] == a[i]) continue ;
                if (p[i] < a[i]) ok1 = false ;
                break ;
            }
            for (int i = 1 ; i <= n ; ++ i) {
                if (p[i] == b[i]) continue ;
                if (p[i] > b[i]) ok1 = false ;
                break ;
            }
            if (!ok1 || !ok2) continue ;
            for (int i = 1 ; i <= n ; ++ i) f[i] = 0 ;
            for (int i = 1 ; i <= n ; ++ i) {
                res += get(p[i]) ;
                res %= mod ;
                update(p[i]);
            }
        }   while (next_permutation(p + 1 , p + 1 + n)) ;
        cout << res ;
    }
}

namespace subtask2 {
    void solve() {
        if (n == 1) cout << "0" ;
        else if (n == 2) cout << "1" ;
        else {
            ll res = 1 ;
            ll gt = 2 ;
            for (int i = 3 ; i <= n ; ++ i) {
                res = (res * i % mod + gt * (i * (i - 1) / 2) % mod) % mod ;
                gt = gt * i % mod ;
//                cout << res << "\n" ;
            }
            cout << res ;
        }
    }
}

int main() {
	input();
    cin >> n ;
    bool ok = true ;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i] ;
        if (a[i] != i) ok = false ;
    }
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> b[i] ;
        if (b[i] != n - i + 1) ok = false ;
    }
    if (ok) {
        subtask2 :: solve() ;
    }
    else {
        bool check = true ;
        for (int i = 1 ; i <= n ; ++ i) {
            if (a[i] != b[i]) {
                check = false ;
                break ;
            }
        }
        if (check) {
            subtask1 :: solve1() ;
        }
        else {
            subtask1 :: solve3() ;
        }
    }


	return 0;
}
