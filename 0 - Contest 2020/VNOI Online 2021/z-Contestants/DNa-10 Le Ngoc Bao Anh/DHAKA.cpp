#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define ins insert
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define unmap unordered_map
#define pq priority_queue
#define minEle min_element
#define maxEle max_element
#define lb lower_bound //first pos >= val
#define ub upper_bound // first pos > val
#define cnt_bit __builtin_popcount
//#pragma GCC optimize("Ofast")  
//#pragma GCC target("avx,avx2,fma")
using namespace std;

int d4x[4] = {1, 0, -1, 0}; int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1}; 

const long long oo = 1e18;
const int maxN = 1e5 + 10;
const int maxMask = (1 << 5) + 10; 

/* Author : Le Ngoc Bao Anh, 10A5, LQD High School for Gifted Student */

bool canMask[maxN][maxMask];
long long f[maxN][maxMask];
int melon[maxN][7];
int mxMask, n;

struct Data
{
    int v;
    long long w;

    bool operator < (const Data & temp) const {
        return w < temp.w;
    }
};

struct Priority
{
    int node, mask;
    long long d;

    bool operator < (const Priority & temp) const {
        return d > temp.d;
    }
};

vector<Data> a[maxN];
pq<Priority> q;

bool Getbit(int mask, int i) 
{
    return ((mask >> i) & 1);
}

void Dijkstra(int mainMask)
{
    //dp[node][mask];
    int ok = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < mxMask; j++) f[i][j] = oo;
    }

    for(int mask = 0; mask < mxMask; mask++) if(canMask[1][mask]) {
        f[1][mask] = 0;
        q.push({1, mask, 0});
    }

    while(!q.empty()) {
        int node = q.top().node; 
        int mask = q.top().mask;
        q.pop();

        for(int i = 0; i < a[node].size(); i++) {
            for(int nxtmask = mask; nxtmask <= mxMask; nxtmask++) {
                if((nxtmask & mask) != mask) continue;
                int need = (mask ^ nxtmask);
                if(!canMask[a[node][i].v][need]) continue;
                if(f[a[node][i].v][nxtmask] > f[node][mask] + a[node][i].w) {
                    f[a[node][i].v][nxtmask] = f[node][mask] + a[node][i].w;
                    q.push({a[node][i].v, nxtmask, f[a[node][i].v][nxtmask]});
                }
            }
        }
    }
}   

void Solve()
{
    int m, k, temp, u, v, w, l;
    cin >> n >> m >> k >> l;
    mxMask = (1 << k);
    for(int i = 1; i <= n; i++) {
        cin >> temp;
        for(int j = 1; j <= temp; j++) {
            cin >> u;
            melon[i][u] = 1;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int mask = 0; mask < mxMask; mask++) {
            int ok = 1;
            for(int j = 0; j < k; j++) {
                if(Getbit(mask, j)) {
                    if(!melon[i][k - j]) ok = 0;
                }
            }

            if(ok) canMask[i][mask] = true;
        }
    }
    

    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        a[u].pb({v, w}); a[v].pb({u, w});
    }

    for(int mask = 1; mask < mxMask; mask++) f[1][mask] = oo;

    Dijkstra(1);

    long long ans = oo;
    for(int mask = 0; mask < mxMask; mask++) {
        if(cnt_bit(mask) >= l) ans = min(ans, f[n][mask]);
    }

    if(ans == oo) ans = -1;
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   freopen("DHAKA.inp", "r", stdin);
   freopen("DHAKA.out", "w", stdout);

    Solve();
}
