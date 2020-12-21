/**Yatogami**/
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FFOR(i, a, b) for(int i = a; i < b; i++)
#define DFOR(i, b, a) for(int i = b; i >= a; i--)
#define fi first
#define se second
#define mp make_pair
#define vi vector < int >
#define pb push_back
#define taskname "SOCKS"
#define MAXN 500004
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair < int , int > pii;
typedef pair < ll , ll > pll;
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
}

int n, q, root, maxE;
vi adj[MAXN], r;
int a[MAXN], kt[MAXN], d[MAXN];

void input() {
    read(n); read(q);
    FOR(i, 1, n) read(a[i]);
    FFOR(i, 1, n) {
        int u, v;
        read(u); read(v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    root = 1;
    maxE = 0;
    FOR(i, 1, n)
        if((int)adj[i].size() < (int)adj[root].size())
            root = i;
    FOR(i, 1, n) maxE = max(maxE, (int)adj[i].size());
}

int change(int u) {
    return (u == 0) ? 1 : 0;
}

void sub1() {
    if(maxE > 2) return;
    int sum = 0;
    FOR(i, 1, n) sum += a[i];
    if(sum != 0) write(1);
    else write(0);
    putchar('\n');
    while(q--) {
        int vt;
        read(vt);
        sum = sum - a[vt] + change(a[vt]);
        a[vt] = change(a[vt]);
        if(sum != 0) write(1);
        else write(0);
        putchar('\n');
    }
    exit(0);
}

void dfs2(int u, int c) {
    if((int)adj[u].size() == 3) {
        int cnt = 1;
        for(auto v : adj[u])
            if(v != c) {
                kt[v] = ++cnt;
                dfs2(v, u);
            }
    }
    else
        for(auto v : adj[u])
            if(v != c) {
                kt[v] = kt[u];
                dfs2(v, u);
            }
}

int getans(int x, int y, int z) {
    if(x != 0 && y != 0 && z != 0) return 2;
    if(x + y + z == 0) return 0;
    return 1;
}

void sub2() {
    if(maxE > 3) return;
    int cnt = 0;
    FOR(i, 1, n)
        cnt += ((int)adj[i].size() == 3);
    if(cnt > 2) return;
    kt[root] = 1;
    dfs2(root, root);
    d[1] = d[2] = d[3] = 0;
    FOR(i, 1, n) d[kt[i]] += a[i];
    int ans = getans(d[1], d[2], d[3]);
    write(ans); putchar('\n');
    while(q--) {
        int vt;
        read(vt);
        d[kt[vt]] = d[kt[vt]] - a[vt] + change(a[vt]);
        a[vt] = change(a[vt]);
        int ans = getans(d[1], d[2], d[3]);
        write(ans); putchar('\n');
    }
}
int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);cout.tie(0);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    input();
    sub1();
    sub2();
    return 0;
}
