#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 1005

using namespace std;

int T, n, m, a[maxn], fen[4*maxn], laz[4*maxn];
void down(int id){
    fen[id*2] += laz[id];
    fen[id*2+1] += laz[id];
    laz[id*2] += laz[id];
    laz[id*2+1] += laz[id];
    laz[id] = 0;
}
void update(int u, int v, int w, int l = 1, int r = n, int id = 1){
    if(l > v || r < u) return;
    if(l >= u && r <= v){
        fen[id] += w;
        laz[id] += w;
        return;
    }
    down(id);
    int mid = (l + r) >> 1;
    update(u, v, w, l, mid, (id<<1));
    update(u, v, w, mid+1, r, (id<<1)+1);
    fen[id] = min(fen[id<<1], fen[(id<<1)+1]);
}
int get(int u, int v, int l = 1, int r = n, int id = 1){
    if(l > v || r < u) return 1e9;
    if(l >= u && r <= v) return fen[id];
    down(id);
    int mid = (l + r) >> 1;
    return min(get(u, v, l, mid, (id<<1)), get(u, v, mid+1, r, (id<<1)+1));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("construct.inp", "r", stdin);
    freopen("construct.out", "w", stdout);
    cin >> T;
    while(T--){
        cin >> n >> m;
        FOR(i, 1, 4*n) fen[i] = 0;
        FOR(i, 1, n) cin >> a[i];
        while(m--){
            int type; cin >> type;
            if(type == 1){
                int l, r, k;
                cin >> l >> r >> k;
                FOR(i, l, r) a[i] += k;
            }
            else{
                int l, r, ans = 0;
                cin >> l >> r;
                FOR(i, l, r){
                    int k = get(i, i);
                    update(i, i, -k);
                    update(i, i, a[i]);
                }
                FOR(i, l, r){
                    FORR(j, r, i){
                        int k = get(i, j);
                        ans += k;
                        update(i, j, -k);
                    }
                }
                cout << ans << '\n';
            }
        }

    }
}
