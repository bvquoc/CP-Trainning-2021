#include <bits/stdc++.h>

#define elif else if
#define ii pair<int,int>
#define pb push_back
#define int long long
#define FOR(i , a , b , c) for(int i = (a) ; i <= (b) ; i += (c))
#define FORD(i , a , b , c) for(int i = (a) ; i >= (b) ; i -= (c))
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define mp make_pair
#define x first
#define y second

using namespace std;

const int N = 1e5 + 2 , MASK = 1<<5 + 2;
const int inf = 1e15;

vector<ii> edge[N];

int n , m , k , l;

int d[N][MASK] , msk[MASK];

int countBit(int Bit) {
    int cnt = 0;
    FOR(i , 0 , n - 1 , 1) 
        if( (Bit >> i)&1 == 1) 
            ++cnt;
    return cnt;
}

main() {
    freopen("DHAKA.inp" , "r" , stdin);
    freopen("DHAKA.out" , "w" , stdout);
    FASTIO;

    cin >> n >> m >> k >> l;

    FOR(i , 1 , n , 1) {
        int t ; cin >> t;
        FOR(j , 1 , t , 1) {
            int x ; cin >> x;
            msk[i] = msk[i] | x;
        }
    }

    FOR(i , 1 , m , 1) {
        int u , v , w;
        cin >> u >> v >> w;
        edge[u].pb({w , v});
        edge[v].pb({w , u});
    }

    FOR(i , 1 , n , 1) 
        FOR(j , 0 , (1 << k) , 1) d[i][j] = inf;
    
    d[1][msk[1]] = 0;

    set<pair<int , ii> > s;

    s.insert(mp(0LL , mp(1LL , msk[1])));

    while(!s.empty()) {
        pair<int , ii> cur = *s.begin();
        
        s.erase(s.begin());

        int u = cur.y.x;
        int maskU = cur.y.y;
        int wu = cur.x;

        for(auto i : edge[u]) {
            int v = i.second;
            int wv = i.first;   
            int new_mask = maskU | msk[v];
            if(d[v][new_mask] > wu + wv) {
                d[v][new_mask] = wu + wv;
                s.insert(mp(wu + wv , mp(v , new_mask)));
            }
        }
    }

    int res = inf;

    FOR(i , 0 , (1 << k) - 1 , 1) 
        if(countBit(i) >= l) res = min(res , d[n][i]);
    
    if(res == inf) res = -1;
    cout << res;

    return 0;
}