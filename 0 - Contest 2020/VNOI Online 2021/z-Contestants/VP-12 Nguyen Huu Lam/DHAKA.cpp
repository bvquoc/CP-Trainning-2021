// Date created: "13:57:32, 18-12-2020"
// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long LL;
typedef pair<LL, LL> II;
typedef tuple<LL, LL, LL> III;

#define y0 Sword_Art_Online
#define y1 Your_lie_in_April
#define yn Darling_in_the_Franxx
#define tm Plastic_Memories
#define lr Charlotte
#define norm Weathering_with_you
#define left Violet_Evergarden
#define have Date_a_live
#define ends Your_name
#define prev Five_centimeters_per_second
#define hash Silent_voice
#define endl "\n"

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

LL Rand(LL l, LL h){
    return uniform_int_distribution<LL>(l, h)(rng);
}

template <typename T> void read(T &t){
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

const LL MaxN = 1 + 1e5;

LL n, m, l, k;
vector<LL> types[MaxN];
vector<II> adj[MaxN];

namespace Subtask2{

    LL d[MaxN];

    void Dijk(){
        memset(d, 0x3f, sizeof d);
        d[1] = 0;
        priority_queue<II, vector<II>, greater<II> > pq;
        pq.push({0, 1});
        while(!pq.empty()){
            II temp = pq.top();
            pq.pop();
            LL u = temp.second;
            for(II v : adj[u])
            if(d[u] + v.second < d[v.first]){
                d[v.first] = d[u] + v.second;
                pq.push({d[v.first], v.first});
            }
        }
    }

    void Solve(){
        for(int i = 1 ; i <= n ; ++i){
            LL sz;
            cin >> sz;
            for(int j = 0 ; j < sz ; ++j){ 
                LL x;
                cin >> x;
                types[i].push_back(x);
            }
        }
        for(int i = 0 ; i < m ; ++i){
            LL x, y, z;
            cin >> x >> y >> z;
            adj[x].push_back({y, z});
            adj[y].push_back({x, z});
        }
        Dijk();
        if(d[n] > 1e15) cout << -1 << endl;
        else cout << d[n] << endl;
    }
}

namespace Subtask3{

    LL d[2][MaxN];
    vector<LL> ver;

    void Dijk(LL ver, LL type){
        d[type][ver] = 0;
        priority_queue<II, vector<II>, greater<II> > pq;
        pq.push({0, ver});
        while(!pq.empty()){
            II temp = pq.top();
            pq.pop();
            LL u = temp.second;
            for(II v : adj[u])
            if(d[type][u] + v.second < d[type][v.first]){
                d[type][v.first] = d[type][u] + v.second;
                pq.push({d[type][v.first], v.first});
            }
        }
    }

    void Solve(){
        for(int i = 1 ; i <= n ; ++i){
            LL sz;
            cin >> sz;
            if(sz){
                LL x;
                cin >> x;
                ver.push_back(i);
            }
        }
        for(int i = 0 ; i < m ; ++i){
            LL x, y, z;
            cin >> x >> y >> z;
            adj[x].push_back({y, z});
            adj[y].push_back({x, z});
        }
        memset(d, 0x3f, sizeof d);
        Dijk(1, 0);
        Dijk(n, 1);
        LL ans = 1e18;
        for(int i : ver) ans = min(ans, d[0][i] + d[1][i]);
        if(ans == 1e18) cout << -1 << endl;
        else cout << ans << endl;
    }
}

namespace Subtask4{

    LL f[1 << 5][MaxN], mark[MaxN], ans = 1e18;

    void Dijk(){
        queue<III> pq;
        f[mark[1]][1] = 0;
        pq.push({0, mark[1], 1});
        while(!pq.empty()){
            III temp = pq.front();
            pq.pop();
            LL cost, mask, u;
            tie(cost, mask, u) = temp;
            // cout << cost << " " << mask << " " << u << endl;
            for(II v : adj[u])
            if(f[mask][u] + v.second < f[mask | mark[v.first]][v.first]){
                f[mask | mark[v.first]][v.first] = f[mask][u] + v.second;
                pq.push({f[mask | mark[v.first]][v.first], mask | mark[v.first], v.first});
            }
        }
    }

    void Solve(){
        for(int i = 1 ; i <= n ; ++i){
            LL sz;
            cin >> sz;
            for(int j = 0 ; j < sz ; ++j){ 
                LL x;
                cin >> x;
                mark[i] |= (1 << (x - 1));
            }
        }
        memset(f, 0x3f, sizeof f);
        for(int i = 0 ; i < m ; ++i){
            LL x, y, z;
            cin >> x >> y >> z;
            adj[x].push_back({y, z});
            adj[y].push_back({x, z});
        }
        Dijk();
        for(int i = 0 ; i < (1 << k) ; ++i)
        if(__builtin_popcount(i) >= l) ans = min(ans, f[i][n]);
        if(ans == 1e18) cout << -1 << endl;
        else cout << ans << endl;
    }
}

void InOut(){
    #define TASK "DHAKA"
    if(fopen(TASK".inp","r")){
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    }
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k >> l;
    if(l == 0) Subtask2::Solve();
    else if(l == 1) Subtask3::Solve();
    else Subtask4::Solve();

    return 0;
}