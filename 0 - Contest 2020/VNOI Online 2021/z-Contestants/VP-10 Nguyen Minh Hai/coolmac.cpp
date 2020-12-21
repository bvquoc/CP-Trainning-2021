#include<bits/stdc++.h>

#define ll long long
#define st first
#define nd second

using namespace std;

typedef pair< int , int > ii;
const int maxn = 1e5 + 2 ;
const int mod = 1e9 + 7 ;
const int oo = 1e9 ;

void input() {
    #define name "coolmac"
	if (fopen(name".inp" , "r") ) {
        freopen(name".inp" , "r" , stdin) ;
        freopen(name".out" , "w" , stdout) ;
	}
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

int n , m , k , t ;
int f[maxn] , nxt[maxn] ;
ii p[maxn] , a[maxn] ;

void update (int p) {
    for (int i = p ; i > 0 ; i -= i & -i) f[i] ++ ;
}

int get (int p) {
    int ans = 0 ;
    for (int i = p ; i <= int(1e5) ; ++ i) ans += f[i] ;
    return ans ;
}

int bsearch (int v , int l , int r) {
    int ans = l ;
    while (l <= r) {
        int mid = (l + r) / 2 ;
        if (p[mid].st <= v) {
            ans = max(ans , mid) ;
            l = mid + 1 ;
        }
        else
            r = mid - 1 ;
    }
    return ans ;
}

int main() {
	input();
	cin >> m ;
	for (int i = 1 ; i <= m ; ++ i) cin >> a[i].st >> a[i].nd ;
	cin >> n ;
    int l = 1e5 , r = 1e5 ;
	for (int i = 1 ; i <= n ; ++ i) {
        cin >> t ;
        l = min(l , t) ;
	}
    sort(a + 1 , a + 1 + m) ;
    for (int i = 1 ; i <= m ; ++ i) {
        if (a[i].st <= l && a[i].nd >= r) {
            cout << "1" ;
            return 0 ;
        }
        if (get(a[i].nd) == 0) p[++k] = a[i] ;
        update(a[i].nd) ;
    }
    for (int i = 1 ; i < k ; ++ i) {
        if (p[i].nd < p[i + 1].st) nxt[i] = -1 ;
        else nxt[i] = bsearch(p[i].nd , i + 1 , k) ;
    }
    int s = -1 ;
    for (int i = 1 ; i <= k ; ++ i) {
        if (p[i].st <= l) {
            if (s == -1 || p[i].nd > p[s].nd)
                s = i ;
        }
        else
            break ;
    }
    if (s == -1) {
        cout << "-1" ;
        return 0 ;
    }
    int ans = 1 , cur = p[s].nd ;
//    for (int i = 1 ; i <= n ; ++ i) cout << p[i].st << " " << p[i].nd << "\n" ;
    while (cur < r && s <= k) {
        if (nxt[s] == -1) break ;
        cur = p[nxt[s]].nd ;
        s = nxt[s] ;
        ans ++ ;
    }
    if (cur >= r) cout << ans ;
    else cout << "-1" ;


	return 0;
}
