/** VanhG **/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ii pair<int, int>
#define tkn "dhaka"
#define X first
#define Y second
#define FORU(i, a, b) for (int i = a; i <= b; i++)
#define FFOR(i, a, b) for (int i = a; i < b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
const int N = 1e5 + 7;
const ll base = 1e18;
const ll mod = 998244353;
int n, m, k, l;
int w[N];
vector <ii> adj[N];
void input(){
    cin >> n >> m >> k >> l;
    int s, x;
    FORU(i, 1, n){
        cin >> s;
        w[i] = 0;
        FORU(j, 1, s) {
            cin >> x;
            w[i] += (1 << (x - 1));
        }
    }
    int u, v, c;
    FORU(i, 1, m){
        cin >> u >> v >> c;
        adj[u].push_back(ii(v, c));
        adj[v].push_back(ii(u, c));
    }
}
void init(){}
ll d[N][35];
struct Data{
    ll du;
    int u, num;
};
struct cmp{
    bool operator() (Data a, Data b){
        return a.du > b.du;
    }
};
void dijktra(){
    priority_queue <Data,vector<Data>, cmp > q;
    q.push({0, 1, 0});
    d[1][0] = 0;
    ll du; int u, num, v, c, nnum;
    while (! q.empty()){
        du = q.top().du;
        u = q.top().u;
        num = q.top().num;
        q.pop();
        if (du != d[u][num]) continue;
        for (ii x : adj[u]){
            v = x.X; c = x.Y;
            nnum = (num | w[v]);
            if (d[v][nnum] > d[u][num] + c){
                d[v][nnum] = d[u][num] + c;
                q.push({d[v][nnum], v, nnum});
            }
        }
    }
    int ma = (1 << k) - 1;
    ll res = base;
    FORU(msk, 0, ma){
        if (__builtin_popcount(msk) >= l)
            res = min(res, d[n][msk]);
    }
    if (res == base) cout << -1;
    else cout << res;

}
void sol() {
    FORU(i, 1, n) FORU(j, 0, 34) d[i][j] = base;
    dijktra();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen(tkn".inp","r", stdin);
    freopen(tkn".out", "w", stdout);
    int test; test = 1;
    while (test --){
        input();
        init();
        sol();
    }
    return 0;
}
