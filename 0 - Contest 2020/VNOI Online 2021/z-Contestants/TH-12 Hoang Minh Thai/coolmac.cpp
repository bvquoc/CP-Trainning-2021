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
#define taskname "coolmac"
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

const int inf = 1e9;
const int N = 1e5 + 1;
int m, n;
int mac[N];
int st[4 * N];
void update(int id, int l, int r, int i, int val){
    if(l == r){
        st[id] = min(st[id], val);
    }
    else{
        int mid = (l + r) / 2;
        if(i <= mid) update(id * 2, l, mid, i, val);
        else update(id * 2 + 1, mid + 1, r, i, val);
        st[id] = min(st[id * 2], st[id * 2 + 1]);
    }
}
int get(int id, int l, int r, int u, int v){
    if(u > r || l > v) return inf;
    if(u <= l && r <= v)
        return st[id];
    int mid = (l + r) / 2;
    return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
bool maxq = 0;
int main()
{
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    read(m);
    FFOR(i, 0, N) mac[i] = -1;
    FFOR(i, 0, 4 * N) st[i] = inf;
    FOR(i, 1, m) {
        int l, r;
        read(l); read(r);
        if(mac[l] != -1) max(mac[l], r);
        else mac[l] = r;
        if(r == N - 1) maxq = 1;
    }
    DFOR(i, N - 1, 0){
        if(mac[i] != -1){
            int tmp = get(1, 0, N - 1, i, mac[i]);
            if(mac[i] == N - 1) tmp = 0;
            update(1, 0, N - 1, i, tmp + 1);
        }
    }
    read(n);
    int pos = N - 1;
    FOR(i, 1, n){
        int t;
        read(t);
        pos = min(pos, t);
    }
    if(pos == N - 1){
        if(maxq) write(1);
        else write(-1);
        return 0;
    }
    int res = get(1, 0, N - 1, 0, pos);
    if(res == inf) write(-1);
    else write(res);
    return 0;
}
