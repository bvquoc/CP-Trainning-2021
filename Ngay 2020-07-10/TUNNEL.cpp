#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const int N = 5005, INF = 1000111000;
typedef pair<int,int> ii;
int n, m, s, t, MaxH;
int h[N][N], d[N][N];
vector <int> f, T;

void Dijkstra1() {
    bool cx[n+5];
    memset(cx,true,sizeof(cx));
    f[s] = INF;
    while(true) {
        bool OUT=true;
        int Max=0, u;
        for(int i=1; i<=n; i++) {
            if(cx[i] && f[i]>Max) {
                OUT = false;
                Max = f[i];
                u = i;
            }
        }
        if (OUT) break;
        cx[u] = false;
        for(int v=1;v<=n;v++) 
            if(cx[v] && h[u][v]>0) 
                f[v] = max(f[v],min(f[u],h[u][v]));
    }
    MaxH = f[t];
}
void Dijkstra2() {
    priority_queue <ii, vector<ii>, greater<ii> > pq;
    for (int i=1; i<=n; i++) f[i]=INF;
    f[s] = 0;
    pq.push(ii(0,s));
    while (pq.size()){
        int u=pq.top().second, du=pq.top().first;
        pq.pop();
        for (int v=1; v<=n; v++)
        if (d[u][v]!=0 && h[u][v]>=MaxH) {
            int uv = d[u][v];
            if (f[v]>du+uv) {
                f[v] = du+uv;
                T[v] = u;
                pq.push(ii(f[v], v));
            }
        }
    }
}

int32_t main() {
    freopen("TUNNEL.INP","r",stdin);
    freopen("TUNNEL.OUT","w",stdout);
    cin>>n>>s>>t;
    cin>>m;
    for (int i=1;i<=m;i++) {
        int x, y, H, D;
        cin >> x >> y >> H >> D;
        h[x][y] = H; h[y][x] = H;
        d[x][y] = D; d[y][x] = D;
    }

    f.resize(n+1);
    T.resize(n+1,-1);
    Dijkstra1();
    Dijkstra2();

    int x = t; 
    vector <int> luu;
    while (T[x]!=-1) {
        luu.push_back(x);
        x = T[x];
        if (x==s) {
            luu.push_back(s);
            break;
        }
    }
    cout << luu.size() << endl;
    reverse(luu.begin(),luu.end());
    for (int x:luu) cout << x << ' ';
    return 0;
}