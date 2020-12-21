#include <bits/stdc++.h>
#define int long long
#define Task "COOLMAC"
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define READFILE freopen(Task".INP", "r", stdin)
#define WRITEFILE freopen(Task".OUT", "w", stdout)
#define pb push_back
#define mp make_pair
#define oo 1e18
#define ENDL '\n'
#define debug(x) cout << #x << " = " << x << ENDL
#define X first
#define Y second
#define ever (;true;)
#define all(x) x.begin(), x.end()

using namespace std;

typedef vector < int > vi;
typedef vector < vi > vvi;
typedef vector < vvi > vvvi;
typedef pair < int, int > ii;
typedef vector < ii > vii;
typedef vector < vii > vvii;
typedef pair < int, ii > iii;
typedef vector < iii > viii;

const int N = 1e5 + 5;

int n;
ii a[N];
int Min = 1e5;

struct Segment_tree{
    vi st;
    Segment_tree(){
        st.resize(N * 10, oo);
    }

    void Upd(int pos, int val, int id = 1, int l = 0, int r = N){
        if (l > r || pos < l || pos > r) return;
        if (l == r){
            st[id] = val;
            return;
        }
        int mid = (l + r) >> 1;
        Upd(pos, val, id << 1, l, mid);
        Upd(pos, val, (id << 1) | 1, mid + 1, r);
        st[id] = min(st[id << 1], st[(id << 1) | 1]);
    }

    int Get(int u, int v, int id = 1, int l = 0, int r = N){
        if (l > r || l > v || u > r) return oo;
        if (u <= l && r <= v) return st[id];
        int mid = (l + r) >> 1;
        return min(Get(u, v, id << 1, l, mid), Get(u, v, (id << 1) | 1, mid + 1, r));
    }

};

void init(){
    FAST;
    READFILE;
    WRITEFILE;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].X >> a[i].Y;
    int m;
    cin >> m;
    while (m--){
        int w;
        cin >> w;
        Min = min(Min, w);
    }
}

bool cmp(ii x, ii y){
    return x.Y != y.Y ? x.Y > y.Y : x.X > y.X;
}

void Sol(){
    sort(a + 1, a + 1 + n, cmp);
    Segment_tree St;
    vi dp(n + 5, 1);
    if (a[1].Y < 1e5){
        cout << -1;
        return;
    }
    dp[1] = 0;
    St.Upd(a[1].X, 0);
    a[n + 1] = ii(0, Min);
    for (int i = 2; i <= n + 1; ++i){
        dp[i] = St.Get(a[i].X, a[i].Y) + 1;
        St.Upd(a[i].X, dp[i]);
    }
    cout << (dp[n + 1] > n ? -1 : dp[n + 1]);
}

signed main(){
    init();
    Sol();
    return 0;
}

