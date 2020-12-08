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
#define file "fixstr"
#define fi first
#define se second
#define y1 Dinh
#define y0 Huy
#define yn Is
#define j1 Me
#define bit(mask, i) ((mask>>(i - 1))&1)

char ch;
string s;
int n, query, ans, u, v;
int a[N];
string quay[N];
ii p, q;

void InOut(){
    freopen (file ".inp", "r", stdin);
    freopen (file ".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

struct Data {
    int val, lazy, pos;
} t[N * 4];

void Build(int id, int l, int r){
    if (l > r) return ;
    if (l == r) {
        t[id].val = a[l];
        t[id].pos = l;
        t[id].lazy = 0;
        return ;
    }
    int mid = (l + r) / 2;
    Build(id * 2, l, mid);
    Build(id * 2 + 1, mid + 1, r);
    t[id].lazy = 0;
    if (t[id * 2].val < t[id * 2 + 1].val){
        t[id].pos = t[id * 2].pos;
        t[id].val = t[id * 2].val;
    } else {
        t[id].pos = t[id * 2 + 1].pos;
        t[id].val = t[id * 2 + 1].val;
    }
}

void Down(int id) {
    int x = t[id].lazy;
    t[id * 2].val += x, t[id * 2].lazy += x;
    t[id * 2 + 1].val += x, t[id * 2 + 1].lazy += x;
    t[id].lazy = 0;
}

void Update(int id, int l, int r, int u, int v, int val){
    if (l > v || r < u) return ;
    if (u <= l && r <= v) {
        t[id].val += val;
        t[id].lazy += val;
        return ;
    }
    Down(id);
    int mid = (l + r) / 2;
    Update(id * 2, l, mid, u, v, val);
    Update(id * 2 + 1, mid + 1, r, u, v, val);

    if (t[id * 2].val < t[id * 2 + 1].val){
        t[id].pos = t[id * 2].pos;
        t[id].val = t[id * 2].val;
    } else {
        t[id].pos = t[id * 2 + 1].pos;
        t[id].val = t[id * 2 + 1].val;
    }
}

ii Get(int id, int l, int r, int u, int v){
    if (v == 0) return {0, 0};
    if (l > v || r < u) return {1e9, 0};
    if (u <= l && r <= v) return {t[id].val, t[id].pos};
    Down(id);
    int mid = (l + r) / 2;
    ii p = Get(id * 2, l, mid, u, v), q =  Get(id * 2 + 1, mid + 1, r, u, v);
    if (p.fi < q.fi) return p; else return q;
}

void Solve(){
    Build(1, 1, n);
    int dem = 0;
    while (query--){
        cin >> ch; dem++;
        quay[dem] = s;
        if (ch == 'C'){
            int val = 2;
            cin >> u;
            if (s[u - 1] == '(') s[u - 1] = ')'; else s[u - 1] = '(';
            a[u] = Get(1, 1, n, u, u).fi;
            a[u - 1] = Get(1, 1, n, u - 1, u - 1).fi;
            if (a[u] - a[u - 1] == 1) val = -2;
            Update(1, 1, n, u, n, val);
            continue;
        }
        if (ch == 'Q'){
            u, v; ans = 0;
            cin >> u >> v;
            p = Get(1, 1, n, u, v); q = Get(1, 1, n, u - 1, u - 1);
            p.fi -= q.fi;
            if (p.fi == 0) {cout << 0 << "\n"; continue;}
            if (p.fi > 0){
                ans = Get(1, 1, n, v, v).fi - Get(1, 1, n, u - 1, u - 1).fi;
                cout << ans << "\n";
            } else {
                ans -= p.fi;
                int pos = p.se + 1;
                if (pos <= v){
                    int valu = Get(1, 1, n, v, v).fi - Get(1, 1, n, pos - 1, pos - 1).fi;
                    ans += valu;
                }
                cout << ans << "\n";
            }
            continue;
        }
        if (ch == 'U') {
            int x; cin >> x;
            s = quay[x];
            for (int i = 0; i < n; i++) {
                if (s[i] == '(') a[i + 1] = a[i] + 1;
                else a[i + 1] = a[i] - 1;
            }
            Build(1, 1, n);
        }

    }
}

void Solve1(){
    Build(1, 1, n);
    int dem = 0;
    while (query--){
        cin >> ch; dem++;
        if (ch == 'C'){
            int val = 2;
            cin >> u;
            a[u] = Get(1, 1, n, u, u).fi;
            a[u - 1] = Get(1, 1, n, u - 1, u - 1).fi;
            if (a[u] - a[u - 1] == 1) val = -2;
            Update(1, 1, n, u, n, val);
            continue;
        }
        if (ch == 'Q'){
            u, v; ans = 0;
            cin >> u >> v;
            p = Get(1, 1, n, u, v); q = Get(1, 1, n, u - 1, u - 1);
            p.fi -= q.fi;
            if (p.fi == 0) {cout << 0 << "\n"; continue;}
            if (p.fi > 0){
                ans = Get(1, 1, n, v, v).fi - Get(1, 1, n, u - 1, u - 1).fi;
                cout << ans << "\n";
            } else {
                ans -= p.fi;
                int pos = p.se + 1;
                if (pos <= v){
                    int valu = Get(1, 1, n, v, v).fi - Get(1, 1, n, pos - 1, pos - 1).fi;
                    ans += valu;
                }
                cout << ans << "\n";
            }
            continue;
        }
    }
}

main(){
    InOut();
    cin >> s; n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') a[i + 1] = a[i] + 1;
        else a[i + 1] = a[i] - 1;
    }
    cin >> query;
    if (n <= 1000 && query <= 1000) Solve();
    else Solve1();

}

