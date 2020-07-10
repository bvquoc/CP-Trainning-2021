#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int N = 1003, INF = 1000111000;
int n, r, d, s, t, res;
int a[N][N], f[N];
bool cx[N];

void Dijkstra() {
    memset(cx,true,sizeof(cx));
    f[s] = INF;
    while(true) {
        bool OUT = true;
        int Max = 0, u;
        for(int i=1; i<=n; i++) {
            if(cx[i] && f[i]>Max) {
                OUT=false;
                Max=f[i];
                u=i;
            }
        }
        if (OUT) break;
        cx[u] = false;
        for(int v=1; v<=n; v++) {
            if(cx[v]==true && a[u][v]>0) {
                f[v]=max(f[v],min(f[u],a[u][v]));
            }
        }
    }
    res = d/f[t];
    if (d%f[t]>0) ++res;
}

int main() {
    FastIO;
    freopen("GUIDE.INP","r",stdin);
    freopen("GUIDE.OUT","w",stdout);
    cin >> n >> r;
    for(int i=1;i<=r;i++) {
        int x, y, z;
        cin >> x >> y >> z;
        z-=2;
        a[x][y] = a[y][x] = z;
    }
    cin >> s >> t >> d;
    Dijkstra();
    cout << res;
    return 0;
}
