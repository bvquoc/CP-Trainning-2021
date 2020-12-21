#include <bits/stdc++.h>

#define elif else if
#define ii pair<int,int>
#define pb push_back
#define ll long long
#define FOR(i , a , b , c) for(int i = (a) ; i <= (b) ; i += (c))
#define FORD(i , a , b , c) for(int i = (a) ; i >= (b) ; i -= (c))
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int N = 5e5 + 2;

int n , q , color[N] , cnt;

main() {
    freopen("SOCKS.inp" , "r" , stdin);
    freopen("SOCKS.out" , "w" , stdout);
    FASTIO;

    cin >> n >> q;

    FOR(i , 1 , n , 1) {
        cin >> color[i];
        cnt += color[i];
    }

    FOR(i , 1 , n - 1 , 1) {
        int u , v ;
        cin >> u >> v;
    }
    
    while(q--) {
        int x ; cin >> x;
        cnt -= color[x];
        color[x] = 1 - color[1];
        cnt += color[x];
        if(cnt <= 1) 
            cout << 0;
        else cout << 1;
        cout << "\n";
    }
    

    return 0;
}