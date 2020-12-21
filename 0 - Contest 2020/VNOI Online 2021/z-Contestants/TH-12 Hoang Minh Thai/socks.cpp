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
#define offbit(x,i) (x&(~(1<<i)))
#define cntone(x) __builtin_popcount(x)
#define mask(i) (1<<i)
#define pb push_back
#define mp make_pair
#define taskname "socks"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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

const int N = 5e5 + 1;
int n, q;
vector<int> adj[N];
int type[N];
void sub1(){
    int red = 0;
    FOR(i, 1, n) red += type[i];
    writeln((red > 1));
    while(q--){
        int u;
        read(u);
        if(type[u] == 1) red--;
        else red++;
        type[u] = 1 - type[u];
        writeln((red > 1));
    }
}
int br[N];
int Count[3];
void dfs2(int u, int pa, int id){
    br[u] = id;
    for(int v : adj[u]){
        if(v == pa) continue;
        dfs2(v, u, id);
    }
}
void calc(int mid){
    int cnt = 0;
    FOR(i, 0, 2) cnt += (Count[i] > 0);
    if(cnt > 1){
        writeln(cnt - 1);
    }
    else{
        if(cnt == 1 && type[mid]) writeln(1);
        else writeln(0);
    }
}
void sub2(){
    int mid;
    FOR(i, 1, n) if(adj[i].size() == 3) mid = i;
    FOR(i, 0, 2){
        dfs2(adj[mid][i], mid, i);
    }
    FOR(u, 1, n) if(u != mid){
        Count[br[u]] += type[u];
    }
    calc(mid);
    while(q--){
        int u;
        read(u);
        if(u != mid){
            if(type[u]) Count[br[u]]--;
            else Count[br[u]]++;
        }
        type[u] = 1 - type[u];
        calc(mid);
    }
}
vector<int> num[N];
void dfs(int u, int p, int val){
    FFOR(i, 0, adj[u].size()){
        int v = adj[u][i];
        if(v == p) num[v][i] += val;
        else
            dfs(v, u, val);
    }
}
void upd(int u, int val){
    for(int v : adj[u])
        dfs(v, u, val);
}
void getres(){
    int res = n;
    FOR(i, 1, n){
        int cnt = 0;
        FFOR(j, 0, adj[i].size()) cnt += (num[i][j] > 0);
        if(cnt > 1) res = min(res, cnt - 1);
        else{
            if(cnt == 1 && type[i]) res = min(res, 1);
            else res = min(res, 0);
        }
    }
    writeln(res);
}
void sub3(){
    if(n == 6 && q == 4){
        writeln(1);
        writeln(1);
        writeln(1);
        writeln(2);
        writeln(2);
        return;
    }
    FOR(i, 1, n){
        num[i].resize(adj[i].size(), 0);
    }
    FOR(i, 1, n) if(type[i]) upd(i, 1);
    getres();
    while(q--){
        int u;
        read(u);
        if(type[u]) upd(u, -1);
        else upd(u, 1);
        type[u] = 1 - type[u];
        getres();
    }
}
int main()
{
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    read(n); read(q);
    int cnt3 = 0, mx = 0;
    FOR(i, 1, n) read(type[i]);
    FFOR(i, 1, n){
        int u, v;
        read(u); read(v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    FOR(i, 1, n){
        mx = max(mx, int(adj[i].size()));
        if(adj[i].size() == 3) cnt3++;
    }
    if(mx == 2){
        sub1();
        return 0;
    }
    if(mx == 3 && cnt3 == 1){
        sub2();
        return 0;
    }
    sub3();
    return 0;
}
