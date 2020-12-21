//Hoang Son WIBU lolicon codeforces rate 1439 khong cay
#include <bits/stdc++.h>
#define F first
#define S second
#define times double stime = clock();
#define gettime cerr << "\nTime executed: " << (clock() - stime) / CLOCKS_PER_SEC * 1000 << "ms.\n";
using namespace std;
typedef long long ll;
typedef double dou;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const ll mod = 998244353;
//-std=gnu++17 -Wall

//DHAKA
int n, m, k, l;
int a[100005];
vector<pii> ed[100005];
ll d[100005][32];
struct way{
    int u, mark;
    ll w;
};
struct cmp{
    bool operator()(way &ax, way &bx){
        return ax.w > bx.w;
    }
};
priority_queue<way, vector<way>, cmp> pq;
void BFS(){
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<(1 << k); j++){
            d[i][j] = 200000000000000ll;
        }
    }
    d[1][a[1]] = 0;
    pq.push({1, a[1], 0});
    while(!pq.empty()){
        way umw = pq.top(); pq.pop();
        int u = umw.u, mark = umw.mark;
        ll w = umw.w;
        if(u == n && __builtin_popcount(mark) >= l) break;
        if(d[u][mark] != w) continue;
        for(pii &v: ed[u]){
            int newmark = (mark | a[v.F]);
            if(d[v.F][newmark] > w + 1ll*v.S){
                d[v.F][newmark] = w + 1ll*v.S;
                pq.push({v.F, newmark, d[v.F][newmark]});
            }
        }
    }
}
void process(){
    cin >> n >> m >> k >> l;
    for(int i = 1; i<=n; i++){
        int s, val;
        cin >> s;
        for(int j = 1; j<=s; j++){
            cin >> val;
            val--;
            a[i] |= (1 << val);
        }
    }
    for(int i = 1; i<=m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        ed[u].push_back({v, w});
        ed[v].push_back({u, w});
    }
    //s = 1, t = n;
    BFS();
    ll res = 200000000000000ll; 
    for(int i = 0; i < (1 << k); i++){
        if(__builtin_popcount(i) >= l){
            res = min(res, d[n][i]);
        }
    }
    if(res > 100000000000000ll){
        cout << -1;
    } else cout << res;
}
int online = 1;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(online == 0){
        freopen("in.inp","r", stdin);
        freopen("out.out","w", stdout);
    } else if(online == 1){
        freopen("DHAKA.inp","r", stdin);
        freopen("DHAKA.out","w", stdout);
    }
    //times
    process();
    //gettime
    return 0;
}