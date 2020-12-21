#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll , int> II;
typedef pair<double , double> DD;
const int N = 1e5 + 2;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int base = 251;
struct save{
    int u , mask;
    ll du;
    save(ll _du = 0 , int _u = 0 , int _mask = 0) : du(_du) , u(_u) , mask(_mask) {}
    bool operator > (const save& op) const{
       return du > op.du;
    }
};
ll dp[N][40] , ans = INF;
int n , m , k , l , u , v , w , a[N] , s , b;
vector<II> g[N];
void Dijkstra(){
    priority_queue<save , vector<save> , greater<save>> pq;
    for(int i = 0 ; i < N ; i ++)
        for(int j = 0 ; j < 40 ; j ++) dp[i][j] = INF;
    dp[1][a[1]] = 0;
    pq.push(save(0 , 1 , a[1]));
    while(!pq.empty()){
        int u = pq.top().u , mask = pq.top().mask;
        ll du = pq.top().du;
        pq.pop();
        for(auto x : g[u]){
            int v = x.second , uv = x.first;
            int nmask = mask | a[v];
            if(dp[v][nmask] > du + uv){
                dp[v][nmask] = du + uv;
                pq.push(save(dp[v][nmask] , v , nmask));
            }
        }
    }
}
int main(){
    freopen("DHAKA.inp" , "r" , stdin);
    freopen("DHAKA.out" , "w" , stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k >> l;
    for(int i = 1 ; i <= n ; i ++){
        cin >> s;
        for(int j = 1 ; j <= s ; j ++){
            cin >> b;
            a[i] |= (1 << (b - 1));
        }
    }
    for(int i = 1 ; i <= m ; i ++){
        cin >> u >> v >> w;
        g[u].push_back(II(w , v));
        g[v].push_back(II(w , u));
    }
    Dijkstra();
    for(int mask = 0 ; mask < 32 ; mask ++){
        if(__builtin_popcount(mask) >= l) ans = min(ans , dp[n][mask]);
    }
    if(ans == INF){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}
