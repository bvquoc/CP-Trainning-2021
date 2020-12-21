#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define eb emplace_back

#define FORU(i, a, b) for(__typeof(b) i = (a); i <= (b); ++i)
#define FORD(i, a, b) for(__typeof(a) i = (a); i >= (b); --i)

#define Fast_IO ios_base::sync_with_stdio(false); cin.tie(0);

#define PROB "COOLMAC"
void Fi(){
    if(fopen(PROB".inp", "r")){
        freopen(PROB".inp", "r", stdin);
        freopen(PROB".out", "w", stdout);
    }
}

const int N = 1e5 + 1;
const int M = 1e5 + 1;
typedef pair<int, int> pii;
pii a[M];
int L = 1e5, R = 1e5;

int ST[N * 4], lz[N * 4];

void down(int id, int be, int en){
    ST[id * 2] = min(ST[id * 2], lz[id]);
    ST[id * 2 + 1] = min(ST[id * 2 + 1], lz[id]);
    if(lz[id * 2] == 0) lz[id * 2] = lz[id];
    else lz[id * 2] = min(lz[id * 2], lz[id]);
    if(lz[id * 2 + 1] == 0) lz[id * 2 + 1] = lz[id];
    else lz[id * 2 + 1] = min(lz[id * 2 + 1], lz[id]);
    lz[id] = 0;
}

int getmin(int i, int id = 1, int be = L, int en = R){
    if(i < L) return 0;
    if(i < be || en < i) return 1e9;
    if(be == en) return ST[id];
    int mi = (be + en) / 2;
    if(lz[id]) down(id, be, en);
    return min(getmin(i, id * 2, be, mi),
               getmin(i, id * 2 + 1, mi + 1, en));
}

void updrange(int l, int r, int v, int id = 1, int be = L, int en = R){
    if(r < be || en < l) return;
    if(l <= be && en <= r){
        ST[id] = min(ST[id], v);
        if(lz[id] == 0) lz[id] = v;
        else lz[id] = min(lz[id], v);
        return;
    }
    int mi = (be + en) / 2;
    if(lz[id]) down(id, be, en);
    updrange(l, r, v, id * 2, be, mi);
    updrange(l, r, v, id * 2 + 1, mi + 1, en);
    ST[id] = min(ST[id * 2], ST[id * 2 + 1]);
}

int main(){
    Fast_IO;
    Fi();
    int m; cin >> m;
    FORU(i, 1, m){
        cin >> a[i].fi >> a[i].se;
    }
    int n; cin >> n;
    FORU(i, 1, n){
        int x; cin >> x;
        L = min(L, x);
    }
    vector<pii> na;
    FORU(i, 1, m){
        if(a[i].se < L) continue;
        na.eb(mp(max(L, a[i].fi), min(R, a[i].se)));
    }
    FORU(i, 0, N * 4 - 1) ST[i] = 1e9;
    sort(na.begin(), na.end());
    for(pii x: na){
        int pre = getmin(x.fi - 1);
        updrange(x.fi, x.se, pre + 1);
    }
    int ans = getmin(R);
    if(ans == 1e9) cout << -1;
    else cout << ans;
    return 0;
}
