/** Kujoh **/
#include <bits/stdc++.h>
#define fi first
#define se second
#define bug(x) cerr << #x << " = " << x << '\n';
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FFOR(i,a,b) for(int i = a; i < b; i++)
#define DFOR(i,b,a) for(int i = b; i >= a; i--)
#define getbit(x,i) ((x>>i)&1)
#define onbit(x,i) (x(1<<i))
#define offbit(x, i) (x &(~(1<<i)))
#define cntone(x) __builtin_popcount(x)
#define mask(i) (1<<i)
#define pb push_back
#define mp make_pair
#define taskname "dhaka"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
const ld eps = 1e-9;
template <typename T> inline void read(T & x)
{
    char c; bool nega=0;
    while((!isdigit(c=getchar()))&&c!='-');
    if(c=='-')
    {
        c=getchar();
        nega=1;
    }
    x=c-48;
    while(isdigit(c=getchar()))
    {
        x=x*10+c-48;
    }
    if(nega) x=-x;
}
template <typename T> void Write(T x) {
    if (x > 9) Write(x/10);
    putchar(x%10+48);
}
template <typename T> void write(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    Write(x);
    putchar(' ');
}
template <typename T> void writeln(T x) {
    write(x);
    putchar('\n');
}

             /** END OF TEMPLATE **/

const ll inf = 1e18;
const int N = 1e5 + 1;
int n, m, k, l;
int a[N][6];
int s[N];
ll f[N][1<<5];
vector<pii> adj[N];
struct node{
    ll fu;
    int u, msk;
};
struct cmp{
    bool operator ()(node A, node B){
        return A.fu > B.fu;
    }
};
priority_queue<node, vector<node>, cmp> q;
int main(){
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    read(n); read(m); read(k); read(l);
    FOR(i, 1, n){
        read(s[i]);
        FOR(j, 1, s[i]) read(a[i][j]);
    }
    FOR(i, 1, m){
        int u, v, w;
        read(u); read(v); read(w);
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    FOR(i, 1, n) FFOR(j, 0, mask(k)) f[i][j] = inf;
    int temp = 0;
    FOR(i, 1, s[1]){
        temp |= mask(a[1][i] - 1);
    }
    f[1][temp] = 0;
    q.push({0, 1, temp});
    while(!q.empty()){
        int u = q.top().u, msk = q.top().msk;
        ll fu = q.top().fu;
        q.pop();
        if(f[u][msk] != fu) continue;
        FFOR(i, 0, adj[u].size()){
            int v = adj[u][i].fi;
            ll w = adj[u][i].se;
            int new_msk = msk;
            FOR(j, 1, s[v]){
                new_msk |= mask(a[v][j] - 1);
            }
            if(f[v][new_msk] > fu + w){
                f[v][new_msk] = fu + w;
                q.push({f[v][new_msk], v, new_msk});
            }
        }
    }
    ll res = inf;
    FFOR(msk, 0, mask(k)){
        if(cntone(msk) >= l) res = min(res, f[n][msk]);
    }
    if(res == inf) write(-1);
    else write(res);
    return 0;
}
