#include <bits/stdc++.h>
using namespace std;

#define oo 1e16
#define fi first
#define se second
#define sp(iiii) setprecision(iiii)
#define IO ios_base::sync_with_stdio(false); cin.tie(0)
#define ms(aaaa,xxxx) memset(aaaa,xxxx,sizeof(aaaa))
#define cntbit(xxxx) __builtin_popcount(xxxx)
#define getbit(xxxx,aaaa) ((xxxx>>(aaaa-1))&1)


typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
typedef pair<long long,long long> pll;
typedef pair<pair<long long,long long>,long long> plll;

const ll mod=1e9+7;

struct comp{
    bool operator() (plll x,plll y) {
        return x.se>y.se;
    }
};

priority_queue<plll,vector<plll>,comp> heap;
ll n,m,k,l,u,v,w,i,j,res,ans[200009][40],a[200009];
vector<pll> g[200009];

void dijkstra() {
    for (int ii=1;ii<=n;ii++) {
        for (int ij=0;ij<(1<<k);ij++) {
            ans[ii][ij]=oo;
        }
    }
    ans[1][a[1]]=0;
    heap.push({{1,a[1]},0});
    while (!heap.empty()) {
        ll x=heap.top().fi.fi;
        ll y=heap.top().se;
        ll msk=heap.top().fi.se;
        heap.pop();
        if (y>ans[x][msk]) {
            continue;
        }
        for (int ii=0;ii<g[x].size();ii++) {
            if (ans[g[x][ii].fi][a[g[x][ii].fi]|msk]>y+g[x][ii].se) {
                ans[g[x][ii].fi][a[g[x][ii].fi]|msk]=y+g[x][ii].se;
                heap.push({{g[x][ii].fi,a[g[x][ii].fi]|msk},y+g[x][ii].se});
            }
        }
    }
}

int main(){
    IO;
    freopen("dhaka.inp", "r", stdin);
    freopen("dhaka.out", "w", stdout);
    cin>>n>>m>>k>>l;
    for (i=1;i<=n;i++) {
        cin>>u;
        for (j=1;j<=u;j++) {
            cin>>v;
            a[i]|=(1<<(v-1));
        }
    }
    for (i=1;i<=m;i++) {
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    res=oo;
    dijkstra();
    for (i=0;i<(1<<k);i++) {
        if (__builtin_popcount(i)>=l) {
            res=min(res,ans[n][i]);
        }
    }
   // for (i=0;i<(1<<k);i++) {
    //    cout<<ans[n][i]<<' ';
    //}
    //cout<<'\n';
    if (res>=oo) {
        cout<<-1<<'\n';
    }
    else {
        cout<<res<<'\n';
    }
}
