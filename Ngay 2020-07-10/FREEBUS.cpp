#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define int64 long long
using namespace std;
typedef pair<int64,int64> ii;
const int64 oo=888888888888, MaxN=200005;
int n, m, k, s, t;
vector <ii> a[MaxN], e;
int64 s_[MaxN], t_[MaxN], res=oo;
int64 d[8][MaxN];
void Dijkstra_k1() {
    priority_queue <ii, vector<ii>, greater<ii> > pq1, pq2;
    for (int i=1; i<=n; i++) {
        s_[i] = oo;
        t_[i] = oo;
    }
    s_[s] = 0;
    pq1.push(ii(0,s));
    while (pq1.size()){
        int64 u=pq1.top().second;
        int64 du=pq1.top().first;
        pq1.pop();
        if (du!=s_[u]) continue;
        for (int64 i=0; int64 v=a[u][i].second; i++) {
            int64 uv=a[u][i].first;
            if (s_[v]>du+uv) {
                s_[v]=du+uv;
                pq1.push(ii(s_[v], v));
            }
        }
    }
    t_[t] = 0;
    pq2.push(ii(0,t));
    while (pq2.size()){
        int u=pq2.top().second;
        int64 du=pq2.top().first;
        pq2.pop();
        if (du!=t_[u]) continue;
        for (int i=0; int64 v=a[u][i].second; i++) {
            int64 uv=a[u][i].first;
            if (t_[v]>du+uv) {
                t_[v]=du+uv;
                pq2.push(ii(t_[v], v));
            }
        }
    }
}
void Dijkstra_k5();
int main(void) {
    FastIO;
    freopen("FREEBUS.INP","r",stdin);
    freopen("FREEBUS.OUT","w",stdout);
    cin>>n>>m>>k>>s>>t;
    int p, q; int64 w;
    for (int i=1;i<=m;i++) {
        cin>>p>>q>>w;
        a[p].push_back(ii(w, q));
        a[q].push_back(ii(w, p));
        e.push_back(ii(p,q));
    }
    for (int i=1; i<=n; i++) a[i].push_back(ii(0,0));
    if (k==1) {
        Dijkstra_k1();
        for (int64 i=0;i<e.size();i++) {
            p=e[i].first; q=e[i].second;
            w=min(s_[p]+t_[q],s_[q]+t_[p]);
            res=min(res,w);
        }
        cout<<res;
        return 0;
    }
    Dijkstra_k5();
    for (int i=0;i<=k;i++) res=min(res,d[i][t]);//cout<<d[i][t]<<endl;
    cout<<res;
    return 0;
}
struct iii {
    int v, i, dist;
    iii () {}
    iii (int _i, int _j, int64 _dist) { v=_i; i=_j; dist=_dist; }
};
// operator <(const iii &a, const iii &b) { return (a.dist>b.dist || (a.dist==b.dist && a.v>b.v));}
bool operator <(const iii &a, const iii &b) { return (a.dist>b.dist);}
void Dijkstra_k5() {
    for (int i=0; i<=k; i++) for (int j=1;j<=n;j++) d[i][j]=oo;
    priority_queue <iii, vector<iii> > pq;
    // for (int i=0;i<=k;i++) {
    //     d[i][s]=0;
    //     pq.push(iii(0,i,s));
    // }
    d[0][s]=0;
    pq.push(iii(s,0,0));
    while (!pq.empty()) {
        int u=pq.top().v, ui=pq.top().i;
        int64 du=pq.top().dist;
        pq.pop();
        // if (du!=d[ui][u]) continue;
        if (t==u) break;
        for (int i=0; i<a[u].size(); i++) {
            int v=a[u][i].second;
            int64 uv=a[u][i].first;
            if (d[ui][v]>du+uv) {
                d[ui][v]=du+uv;
                pq.push(iii(v,ui,d[ui][v]));
            }
            if (ui<k && d[ui+1][v]>d[ui][v]) {
                d[ui+1][v]=d[ui][v];
                pq.push(iii(v,ui+1,d[ui][v]));
            }
        }
    }
}