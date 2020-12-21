#include<bits/stdc++.h>

#define ll long long
#define st first
#define nd second

using namespace std;

typedef pair< int , int > ii;
const int maxn = 2e3 + 2 ;
const int mod = 998244353 ;
const int oo = 1e9 ;

void input() {
    #define name "gift11"
	if (fopen(name".inp" , "r") ) {
        freopen(name".inp" , "r" , stdin) ;
        freopen(name".out" , "w" , stdout) ;
	}
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

string to_str (int n) {
    string ans = "" ;
    while (n) {
        ans += char(n % 10 + '0') ;
        n /= 10 ;
    }
    reverse(ans.begin() , ans.end()) ;
    return ans ;
}

int n , t ;
int a[maxn] , cnt[2] , p[maxn] ;
string s ;

void subtask1() {
    int res = 0 ;
    for (int i = 1 ; i <= n ; ++ i) p[i] = i ;
    do {
        s = "" ;
        for (int i = 1 ; i <= n ; ++ i) s += to_str(a[p[i]]) ;
        int sum = 0 ;
        for (int i = 0 ; i < s.size() ; ++ i) {
            if (i % 2 == 0) sum += int(s[i] - '0') ;
            else sum -= int(s[i] - '0') ;
        }
        if (abs(sum) % 11 == 0) {
            res ++ ;
            res %= mod ;
        }
    } while (next_permutation(p + 1 , p + 1 + n)) ;
    cout << res << "\n" ;
}

void subtask2() {
    int sum = 0 ;
    for (int i = 1 ; i <= n ; ++ i) sum += a[i] ;
    if (abs(sum) % 11 == 0) cout << "1\n" ;
    else cout << "0\n" ;
}

ll f[maxn][maxn][20] ;

void subtask3() {
    f[0][0][0] = 1 ;
    for (int i = 1 ; i <= n ; ++ i) {
        for (int j = 0 ; j <= n ; ++ j) {
            for (int k = 0 ; k < 11 ; ++ k) {
                if (j > 0) {
                    f[i][j][((k + a[i]) % 11)] += f[i - 1][j - 1][k] ;
                    f[i][j][((k + a[i]) % 11)] %= mod ;
                }
                f[i][j][((k - a[i] + 11) % 11)] += f[i - 1][j][k] ;
                f[i][j][((k - a[i] + 11) % 11)] %= mod ;
//                cout << ((k + a[i]) % 11) << " " << ((k - a[i] + 22) % 11) << " " << k << "\n" ;
                f[i][j][k] += f[i - 1][j][k] ;
            }
        }
    }
//    cout << f[n][(n + 1) / 2][0] << "\n" ;
    ll res = 0 ;
    for (int i = 0 ; i <= n ; ++ i) res = (res + f[n][i][0]) % mod ;
    cout << res << "\n" ;
}

int main() {
	input();
    cin >> t ;
    while (t -- ) {
        cin >> n ;
        for (int i = 1 ; i <= n ; ++ i) cin >> a[i] ;
        if (n <= 9) {
            subtask1() ;
        }
        else {
            for (int i = 1 ; i <= n ; ++ i) {
                s = to_str(a[i]) ;
                cnt[int(s.size()) % 2] ++ ;
                a[i] = 0 ;
                for (int j = 0 ; j < s.size() ; ++ j){
                    if (j % 2 == 0) a[i] += int(s[j] - '0') ;
                    else a[i] -= int(s[j] - '0') ;
                }
                a[i] = (a[i] + 99) % 11 ;
            }
            if (cnt[0] == n) {
                subtask2() ;
            }
            else {
                subtask3() ;
            }
        }
    }



	return 0;
}
