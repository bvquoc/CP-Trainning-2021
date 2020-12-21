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
#define taskname "decor"
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
int m, n, k;
int type[N];
int comp[N];
int numEgg[N];
vector<int> adj[N];
void sub1(){
    int res = 0;
    pii pos = {0, 0};
    FOR(i, 1, n) if(type[i]){
        int j = i;
        while(j <= n && type[j]) j++;
        j--;
        if(res < j - i + 1){
            res = j - i + 1;
            pos = {i, j};
        }
        i = j;
    }
    if(res == 0) write(-1);
    else{
        write(pos.fi);
        write(pos.se);
    }
}
int sum[N][2];
void sub2(){
    FOR(i, 1, n){
        sum[i][0] = sum[i - 1][0];
        sum[i][1] = sum[i - 1][1];
        sum[i][type[i]]++;
    }
    int res = 0;
    pii pos;
    FOR(i, 1, n){
        int l = 1, r = i;
        int le = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(sum[i][0] - sum[mid - 1][0] <= k){
                le = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        if(le != -1 && res < i - le + 1){
            res = i - le + 1;
            pos = {le, i};
        }
    }
    if(res == 0) write(-1);
    else{
        write(pos.fi);
        write(pos.se);
    }
}
int Time;
vector<int> inComp[N];
int cur[N];
void dfs(int u){
    comp[u] = Time;
    numEgg[Time] += type[u];
    inComp[Time].pb(u);
    for(int v : adj[u]){
        if(!comp[v]) dfs(v);
    }
}
int ft[N];
void update(int x, int val){ /// number of 0-egg
    for(; x <= n; x += x&(-x))
        ft[x] += val;
}
int get(int x){
    int res = 0;
    for(; x > 0; x -= x&(-x))
        res += ft[x];
    return res;
}
int main(){
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    read(n); read(m); read(k);
    int cnt1 = 0;
    FOR(i, 1, n){
        char c;
        c = getchar();
        type[i] = c - '0';
        cnt1 += type[i];
    }
    FOR(i, 1, m){
        int u, v;
        read(u); read(v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if(cnt1 + k >= n){
        write(1);
        write(n);
        return 0;
    }
    if(m == 0 && k == 0){
        sub1();
        return 0;
    }
    if(m == 0){
        sub2();
        return 0;
    }
    FOR(u, 1, n){
        if(!comp[u]){
            Time++;
            dfs(u);
        }
    }
    FOR(i, 1, Time){
        cur[i] = -1;
        sort(inComp[i].begin(), inComp[i].end());
    }
    FOR(i, 1, n){
        update(i, 1);
    }
    int res = 0;
    pii pos;
    FOR(i, 1, n){
        int id = comp[i];
        cur[id]++;
        update(i, -1);
        if(cur[id] + 1 > numEgg[id]){
            int u = inComp[id][cur[id] - numEgg[id]];
            update(i, 1);
        }
        int l = 1, r = i;
        int le = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            int tmp = get(i) - get(mid - 1);
            if(tmp <= k){
                le = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        if(le != -1 && res < i - le + 1){
            res = i - le + 1;
            pos = {le, i};
        }
    }
    if(res == 0) write(-1);
    else{
        write(pos.fi);
        write(pos.se);
    }
    return 0;
}
