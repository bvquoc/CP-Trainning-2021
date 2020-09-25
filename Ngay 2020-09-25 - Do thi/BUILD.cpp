#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
// #define int long long
using namespace std;

using ii = pair <int, int>;
using ld = long double;

const int N = 102, INF = 1000000000;

int n, k[5];
int res = INF;
vector <vector <int>> a, b, cur;

int c[N], d[N], tr[N];
void Find(int s, int t) {

}
void dijkstra(int s, int t) {
    priority_queue <ii, vector<ii>, greater<ii>> q;
    FOR(i,1,n) {
        c[i] = INF;
        tr[i] = 0;
        d[i] = 0;
    }
    c[s] = 0;
    q.push(ii(0,s));
    while (q.size()) {
        int u = q.top().second; q.pop();
        if (u==t || u==0) break;
        d[u] = 1;
        FOR(v,1,n) {
            if (a[u][v]>0 && c[v]>c[u]+a[u][v]) {
                c[v] = c[u] + a[u][v];
                tr[v] = u;
            }
        }
    }
    Find(s,t);
}

signed main(void) {
    FastIO;
    freopen("BUILD.INP","r",stdin);
    freopen("BUILD.OUT","w",stdout);
    { // Read Input
        cin >> n;
        a.assign(n+1,vector <int> (n+1,0));
        b.assign(n+1,vector <int> (n+1,0));
        cur.assign(n+1,vector <int> (n+1,0));
        FOR(i,1,4) cin >> k[i];
        int u, v, w;
        while (cin >> u >> v >> w) {
            a[u][v] = w;
            a[v][u] = w;
        }
    }

    FOR(i,1,n) {
        b.assign(n+1, vector<int> (n+1,0));
        FOR(j,1,4) dijkstra(k[j],i);
        solve(Min);
        if (res>Min) {
            res = Min;
            cur = b;
        }
    }
    return 0;
}