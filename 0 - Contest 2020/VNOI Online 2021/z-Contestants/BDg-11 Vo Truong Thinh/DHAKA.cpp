#include <bits/stdc++.h>
#define M 100005
#define Mask(n) (1 << (n))
#define Bit(x, i) (((x) >> (i)) & 1)
#define oo 1000000000000000000

using namespace std;

void reup(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int n, m, k, l;

vector<int> b[M];
int id[M][Mask(5)];

struct edge{
    int v;
    int w;
};

vector<edge> a[M];

void enter(){
    reup();
    cin >> n >> m >> k >> l;
    for(int i = 1; i <= n; ++i){
        int t;
        cin >> t;
        while(t--){
            int ta;
            cin >> ta;
            b[i].push_back(ta);
        }
    }
    for(int i = 1; i <= m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
}

long long dp[M * Mask(5)];

void init(){
    int cnt = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < Mask(k); ++j){
            id[i][j] = ++cnt;
            dp[cnt] = oo;
        }
}

struct node{
    int cur;
    int mask;
    long long w;

    bool operator < (node b)const{
        return b.w < w;
    }

};

priority_queue<node, vector<node>> h;

int hi;

void dij(){
    if(h.empty())
        return;
    node tam = h.top();
    h.pop();
    for(edge tb : a[tam.cur]){
        int newmask = tam.mask;
        for(int ta : b[tb.v])
            newmask |= Mask(ta - 1);
        /////////////////////////////////////
        int v = id[tb.v][newmask];
        if(tam.w + tb.w < dp[v]){
            dp[v] = tam.w + tb.w;
            h.push({tb.v, newmask, dp[v]});
        }
    }
    dij();
}

int cnt_bit(int ta){
    int res = 0;
    while(ta > 0){
        res += Bit(ta, 0);
        ta /= 2;
    }
    return res;
}

void solve(){
    int mask = 0;
    for(int v : b[1])
        mask |= Mask(v - 1);
    dp[id[1][mask]] = 0;
    h.push({1, mask, 0});
    dij();
    long long ans = oo;
    for(int j = 0; j < Mask(k); ++j){
        if(cnt_bit(j) < l)
            continue;
        ans = min(ans, dp[id[n][j]]);
    }
    if(ans >= oo)
        cout << -1;
    else
        cout << ans;
}

int main()
{
    freopen("DHAKA.inp", "r", stdin);
    freopen("DHAKA.out", "w", stdout);
    enter();
    init();
    solve();
    return 0;
}
