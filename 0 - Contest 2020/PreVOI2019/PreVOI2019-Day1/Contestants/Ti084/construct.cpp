#include <bits/stdc++.h>
using namespace std;

//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e6 + 12;
const long long Mod = 1e9 + 7;
const long long oo = 1e18;

typedef pair<int, int> ii;
typedef pair<long long, long long> ll;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

//emsiHD
#define file "construct"
#define fi first
#define se second
#define y1 Dinh
#define y0 Huy
#define yn Is
#define j1 Me
#define bit(mask, i) ((mask>>(i - 1))&1)

int ntest;
long long a[N], f[N];
ll b[N];
map<long long, long long> d;

struct Data {
    long long x, lz;
    vector<long long> v;
} t[N];

void InOut(){
    freopen (file ".inp", "r", stdin);
    freopen (file ".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

vector<long long> Gop(vector<long long> a, vector<long long> b){
    if (a.size() == 0) return b;
    if (b.size() == 0) return a;
    int len = 0, kt = 0;
    vector<long long> ret;
    ret.clear();
    for (int i = 0; i < a.size(); i++) f[++len] = a[i];
    for (int i = 0; i < b.size(); i++) f[++len] = b[i];
    if (f[2] == f[1]) return b;
    ret.push_back(f[1]);
    int i = 2;
    while (i <= len){
        if (f[i] == ret[ret.size() - 1]) {
            i++; continue;
        }
        if (kt == 0) {
            kt = (f[i] > ret[ret.size() - 1]) ? 1 : -1;
            ret.push_back(f[i]);
            i++; continue;
        }
        if (kt == 1) {
            if (f[i] > ret[ret.size() - 1]) ret.pop_back(), ret.push_back(f[i]);
            else {
                ret.push_back(f[i]); kt = -1;
            }
            continue;
        }
        if (kt == -1){
            if (f[i] < ret[ret.size() - 1]) ret.pop_back(), ret.push_back(f[i]);
            else {
                ret.push_back(f[i]); kt = 1;
            }
        }
    }
    return ret;
}

void Build(int id, int l, int r){
    if (l > r) return ;
    if (l == r) {
        t[id].x = a[l];
        t[id].v.clear();
        t[id].v.push_back(a[l]);
        return ;
    }
    int mid = (l + r) / 2;
    Build(id * 2, l, mid);
    Build(id * 2 + 1, mid + 1, r);
    t[id].v.clear();
    t[id].v = Gop(t[id * 2].v, t[id * 2 + 1].v);
}

void Down(int id){
    long long x = t[id].lz;
    t[id * 2].lz += x, t[id * 2 + 1].lz += x;
    for (int i = 0; i < t[id * 2].v.size(); i++) t[id * 2].v[i] += x;
    for (int i = 0; i < t[id * 2 + 1].v.size(); i++) t[id * 2 + 1].v[i] += x;
    t[id].lz = 0;
}

void Update(int id, int l, int r, int u, int v, int k){
    if (l > v || r < u) return ;
    if (u <= l && r <= v) {
        t[id].lz += k;
        for (int i = 0; i < t[id].v.size(); i++) t[id].v[i] += k;
        return ;
    }
    Down(id);
    int mid = (l + r) / 2;
    Update(id * 2, l, mid, u, v, k);
    Update(id * 2 + 1, mid + 1, r, u, v, k);
    t[id].v = Gop(t[id * 2].v, t[id * 2 + 1].v);
}

vector<long long> Get(int id, int l, int r, int u, int v){
    if (l > v || r < u) return {};
    if (u <= l && r <= v) return t[id].v;
    Down(id);
    int mid = (l + r) / 2;
    return Gop(Get(id * 2, l, mid, u, v), Get(id * 2 + 1, mid + 1, r, u, v));
}

long long Xuli(vector<long long> v){
    if (v.size() == 1) return v[0];
    if (v.size() == 2) return max(v[1], v[0]);
    int len = 0;
    for (int i = 0; i < v.size(); i++) b[++len].fi = v[i], d[v[i]] = 0;
    if (b[1].fi > b[2].fi) b[1].se = 1; else b[1].se = -1;
    for (int i = 2; i <= len; i++) b[i].se = -b[i - 1].se;

    set<long long> g;
    set<long long> :: iterator it;

    for (int i = 1; i <= len; i++) {
        if (i != 1 && i != len){
            if (b[i].se == 1) d[b[i].fi]--;
            else d[b[i].fi]++;
        }
        g.insert(b[i].fi);
    }
    long long sl = 1;
    long long truoc = 0;
    long long ans = 0;
    for (it = g.begin(); it != g.end(); it++){
        long long val = *it;
        val -= truoc; truoc = *it;
        ans += val * sl;
        sl += d[truoc];
    }
    return ans;
}

void Solve(){
    cin >> ntest;
    while (ntest--){
        int n, query;
        cin >> n >> query;
        for (int i = 1; i <= n; i++) cin >> a[i];
        Build(1, 1, n);
        while (query--){
            int Type, u, v, val;
            cin >> Type;
            if (Type == 1) {
                cin >> u >> v >> val;
                Update(1, 1, n, u, v, val);
            } else {
                cin >> u >> v;
                vector<long long> q = Get(1, 1, n, u, v);
                long long ans = Xuli(q);
                cout << ans << "\n";
            }
        }
    }
}

main(){
    InOut();

    Solve();

}

