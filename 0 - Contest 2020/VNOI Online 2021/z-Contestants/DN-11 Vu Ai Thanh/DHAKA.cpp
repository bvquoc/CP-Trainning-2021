/*
    Who the hell you think you are?
    Comin' in to break my heart
    Make it like an operation
    But I ain't one of your patients
    Tired of this waiting and I don't play that game

    I can't get you off my brain
    So I'm poppin pills for the pain
    And as soon as I go wake up
    You're caught up in your haze
    And I can't get out of my bed

    Tears are almost gone but the symptoms in my heart
    So tell me what's the cure for you (tell me now)
    'Cause girl you make me so confused
    (girl you got me so confused)

    You got me feeling like a psycho, psycho
    Got me chasin' shots of NyQuil, NyQuil
    Without you got me dizzy and upset
    Got me so obsessed with you
    Look what you started
    I'm psycho, you're heartless
*/
// peachthuw
#include <bits/stdc++.h>
#define EL cout<<'\n'
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define FU(x,a,b) for(int x=int(a);x<=int(b);x++)
#define FD(x,a,b) for(int x=int(a);x>=int(b);x--)
#define PROB "DHAKA"
using namespace std;
typedef long long ll;
typedef double db;


template <typename T>
inline void read(T& x){
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' | c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template <typename T>
inline void write(T x)
{
    if (x < 0)
    {
        putchar('-'); x = -x;
    }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}


void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(fopen(PROB".inp", "r")){
        freopen(PROB".inp", "r",stdin);
        freopen(PROB".out", "w",stdout);
    }
}

const int N = 1e5 + 2;
int n, m, k, l, path[11];
bool in[11]{0};
ll d[105][105], D[N], P[N];
ll res, wei = 0;
vector < vector < pii > > a;
bitset < 6 > dua, c[N];


void readinp(){
    cin >> n >> m >> k >> l;
    FU(i, 1, n){
        int s; cin >> s;
        FU(j, 1, s){
            int x;
            cin >> x;
            c[i][x] = 1;
        }
    }
    a.resize(n + 1);
    FU(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }
}

void floyd(){
    FU(i, 1, n) FU(j, 1, n) d[i][j] = (i == j) ? 0 : 1e18;
    FU(u, 1, n){
        for (auto v : a[u]){
            d[u][v.se] = min(d[u][v.se], ll(v.fi));
            d[v.se][u] = d[u][v.se];
        }
    }
    FU(k, 1, n) FU(u, 1, n) FU(v, 1, n)
        d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
}

void dij(ll t[], int s){
    priority_queue < pli , vector < pli > , greater < pli > > Q;
    FU(i, 1, n) t [i] = 1e18; t[s] = 0;
    Q.push({0, s});
    while (!Q.empty()){
        int u = Q.top().se;
        ll  w = Q.top().fi;
        Q.pop();
        if (t[u] < w) continue;
        for (auto v : a[u]){
            if (t[v.se] > w + ll(v.fi)){
                t[v.se] = w + ll(v.fi);
                Q.push({t[v.se], v.se});
            }
        }
    }
}

void bt(int i){
    FU(j, 2, n) if (!in[j]){
        if (wei + d[j][path[i-1]] > res) continue;
        bitset < 6 > pre = dua;
        dua|= c[j];
        in[j] = true;
        path[i] = j;
        wei+= d[j][path[i-1]];
        if (j == n){
            if (dua.count() >= l)
                res = min(res, wei);
        }
        else bt(i + 1);
        in[j] = false;
        wei-= d[j][path[i-1]];
        dua = pre;
    }
}

void sub1(){
    if (n > 10) return;
    floyd();
    path[1] = 1; in[1] = 1;
    res = 1e18;
    bt(2);
    if (res == 1e18) cout << -1;
    else cout << res;
    exit(0);
}

void sub2(){
    if (l != 0) return;
    dij(D, 1);
    res = D[n];
    if (res == 1e18) cout << -1;
    else cout << res;
    exit(0);
}

void sub3(){
    if (k > 1) return;
    dij(D, 1); dij(P, n);
    res = 1e18;
    FU(i, 1, n){
        if (c[i].count() >= 1)
            res = min(res, D[i] + P[i]);
    }
    if (res == 1e18) cout << -1;
    else cout << res;
    exit(0);
}

void solve(){
    sub1();
    sub2();
    sub3();
}

int main(){
    setIO();
    int t = 1;
//    cin >> t;
    while (t--){
        readinp();
        solve();
    }
}
