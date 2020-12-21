#include<bits/stdc++.h>
#define se second
#define fi first

using namespace std;
typedef long long LL;
typedef pair<LL,LL> I;

const int MAXN = 10 + 1e6;
const LL MOD = 1e9 + 7;
const LL oo = 1e18;

int n , q , k , ma ;
int a[MAXN] , dp[MAXN] , deg[MAXN] ;

LL ans = 0;

vector<int> g[MAXN] ;

void Solve1() {
    int cnt = 0;
    for (int i = 1 ; i <= n ; ++i) cnt += a[i];

    cout <<(cnt > 0) <<'\n';

    for (int i = 1 ; i <= q ; ++i) {
        int x ; cin >>x;
        cnt -= a[x];
        a[x] = !a[x];
        cnt += a[x];

        cout <<(cnt > 0) <<'\n';
    }
}

int vis[MAXN] , b[MAXN];int sl[4];

void Solve2() {
    int pos = 0;
    for (int i = 1 ; i <= n ; ++i) if ( deg[i] == 3 ) pos = i;
    vis[pos] = 1;
    b[pos] = 3;
    for (int i = 0 ; i < 3 ; ++i) {
        int u = g[pos][i];
        vis[u] = 1;
        b[u] = i;
        while( g[u].size() > 1 ) {
            int j = 0 ;
            for (auto v : g[u] ) if ( !vis[v] ) j = v;
            b[j] = i;
            vis[j] = 1;
            u = j;
        }
    }
    for (int i = 1 ; i <= n ; ++i) {
        sl[ b[i] ] += a[i];
    }
    int cnt1 = 0;
    for (int i = 0 ; i < 3 ; ++i) cnt1 += (sl[i] > 0) ;
    if ( !cnt1 ) cout <<0 <<'\n';
    else if ( cnt1 == 3 ) cout <<2 <<'\n';
    else cout <<1 <<'\n';

    for (int i = 1 ; i <= q ; ++i) {
        int x ; cin >>x;
        if ( a[x] ) sl[ b[x] ] --;
        else sl[ b[x] ] ++;

        a[x] = !a[x];

        int cnt = 0;
        for (int j = 0 ; j < 3 ; ++j) cnt += (sl[j] > 0) ;

        if ( cnt + sl[b[pos]] == 0 ) { cout <<0 <<'\n'; continue; }

        if ( !cnt ) cout <<0 <<'\n';
        else if ( cnt == 3 ) cout <<2 <<'\n';
        else cout <<1 <<'\n';
    }
}

void Solve3() {

}

void Inout() {
    #define TASK "SOCKS"
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
}

int main()
{
    Inout();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >>n >>q ;
    for (int i = 1 ; i <= n ; ++i)
        cin >>a[i];
    for (int i = 1 ; i < n ; ++i) {
        int u , v ;
        cin >>u >>v;
        g[u].push_back(v);
        g[v].push_back(u);
        ++deg[u] ;
        ++deg[v] ;
    }
    for (int i = 1 ; i <= n ; ++i) ma = max( ma , deg[i] );

    if ( ma == 2 ) {
        Solve1();
        return 0;
    }

    if ( ma == 3 ) {
        Solve2();
        return 0 ;
    }

    Solve3();


return 0;
}
