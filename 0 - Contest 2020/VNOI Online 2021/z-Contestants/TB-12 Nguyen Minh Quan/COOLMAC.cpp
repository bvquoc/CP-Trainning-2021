// link:
#include <bits/stdc++.h>

#define task "COOLMAC"
#define ll long long
#define f0(i, a, b) for(int i = (a); i <= (b); i++)
#define f1(i, a, b) for(int i = (a); i >= (b); i--)
#define pii pair<int, int>
#define fi first
#define se second
#define MASK(i) (1ll << (i))
#define BIT(i, x) (((x) >> (i)) & 1ll)
#define turn_on(i, x) ((1ll << (i)) | (x))
#define turn_off(i, x) ((x) & ~(1ll << (i)))
#define __builtin_popcount __builtin_popcountll

//---------------DO NOT TRY---------------//
using namespace std;
const int mxN = 1e5 + 7;

int n, m;

struct clo{
    int l, r;
    clo(){};
    clo(int _l, int _r){
        l = _l, r = _r;
    }
};
struct cmp{
    bool operator() (const clo &a, const clo &b){
        if(a.l == b.l) return a.r < b.r;
        return a.l < b.l;
    }
};

clo a[mxN];
int b[mxN];
int p[mxN];
int minT = mxN;
void input(void){
    memset(p, 0, sizeof p);
    cin >> m;
    int l, r, minL = mxN;
    f0(i, 1, m){
        cin >> l >> r;
        minL = min(minL, l);
        p[l]++, p[r + 1]--;
        a[i] = clo(l, r);
    }
    cin >> n;
    f0(i, 1, n){
        cin >> b[i];
        minT = min(minT, b[i]);
    }
    if(minL > minT){
        cout << -1;
        exit(false);
    }
    f0(i, minL, mxN - 7){
        if(i > 0)
            p[i] += p[i - 1];
        if(p[i] == 0){
            cout << -1;
            exit(false);
        }
    }
}
int ST[4 * mxN];
int lazy[4*mxN];
void doLazy(int id){
    int tmp = lazy[id];
    lazy[2*id] = min(tmp, lazy[2*id]);
    lazy[2*id + 1] = min(tmp, lazy[2*id + 1]);
}
void update(int id, int l, int r, int u, int v, int val){
    if(l > r || u > v || r < u || v < l) return;
    if(u <= l && r <= v){
        ST[id] = min(ST[id], val);
        lazy[id] = min(lazy[id], val);
        return;
    }
    lazy[id] = min(lazy[id], val);
    doLazy(id);
    int mid = (l + r) / 2;
    update(2*id, l, mid, u, v, val);
    update(2*id + 1, mid + 1, r, u, v, val);
    ST[id] = min(ST[2*id], ST[2*id + 1]);
}
int GET(int id, int l, int r, int u, int v){
    if(l > r || u > v || r < u || v < l) return mxN;
    if(u <= l && r <= v) return ST[id];
    doLazy(id);
    int mid = (l + r) / 2;
    int caseOne = GET(2*id, l, mid, u, v);
    int caseTwo = GET(2*id + 1, mid + 1, r, u, v);
    return min(caseOne, caseTwo);
}
int dp[mxN];
void solve(void){
    sort(a + 1, a + m + 1, cmp());
    f0(i, 1, 4*mxN - 2){
        ST[i] = mxN;
        lazy[i] = mxN;
    }
    dp[1] = 1;
    update(1, minT, mxN - 7, minT, a[1].r, 1);
    f0(i, 2, m){
        dp[i] = GET(1, minT, mxN - 7, minT, min(a[i].l - 1, a[i - 1].r)) + 1;
        update(1, minT, mxN - 7, minT, a[i].r, dp[i]);
    }
    int res = mxN;
    f0(i, 1, m) if(a[i].r >= (mxN - 7)) res = min(res, dp[i]);
    cout << res;
}

int main(){
    //
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
    //
    input();
    solve();
}
//3
//250 100000
//150 200
//10 300
//2
//1000 200
