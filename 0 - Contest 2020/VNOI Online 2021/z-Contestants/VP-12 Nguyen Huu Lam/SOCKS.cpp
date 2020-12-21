// Date created: "09:53:31, 18-12-2020"
// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long LL;

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

const LL MaxN = 1 + 5e5;

LL n, a[MaxN], q, d[MaxN], ans, deg[MaxN], root;
vector<LL> adj[MaxN];

namespace Subtask1{
    void Solve(){
        LL total = 0;
        for(int i = 1 ; i <= n ; ++i) total += a[i];
        cout << (total > 0) << endl;
        while(q--){
            LL x;
            cin >> x;
            if(a[x]) total--;
            else total++;
            a[x] = 1 - x;
            cout << (total > 0) << endl;
        }
    }
}

void DFS(LL u, LL pr){
    LL total = 0;
    d[u] = 0;
    for(int v : adj[u])
    if(v != pr){
        DFS(v, u);
        total += d[v];
    }
    ans += total / 2;
    if(total >= 2) d[u] = 0;
    else d[u] = max(total, a[u]);
}

void InOut(){
    #define TASK "SOCKS"
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
    cin >> n >> q;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i];
    for(int i = 0 ; i < n - 1 ; ++i){
        LL x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        deg[y]++;
    }
    LL cnt = 0;
    for(int i = 1 ; i <= n ; ++i)
    if(deg[i] == 0) root = i;
    else if(deg[i] == 2) cnt++;
    if(cnt == n - 2){ 
        Subtask1::Solve();
        return 0;
    }
    ans = 0;
    DFS(root, 0);
    cout << ans + d[root] % 2 << endl;
    while(q--){
        LL x;
        cin >> x;
        a[x] = 1 - a[x];
        ans = 0;
        DFS(root, 0);
        cout << ans + d[root] % 2 << endl;
    }

    return 0;
}