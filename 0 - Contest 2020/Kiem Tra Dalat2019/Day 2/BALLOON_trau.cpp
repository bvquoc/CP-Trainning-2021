#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int long long

const string INP=".INP", OUT=".ANS";
const string FILENAME="BALLOON";
const int N=100005;

template <typename T>
inline void Read(T& x) {
    bool Neg=false;
    char c;
    for (c=getchar();c<'0' || c>'9';c=getchar()) if (c=='-') Neg=!Neg;
    x=c-'0';
    for (c=getchar();c>='0' && c<='9';c=getchar()) x=x*10+c-'0';
    if (Neg) x=-x;
}
template <typename T>
inline void Write(T x) {
    if (x<0) { putchar('-'); x=-x; }
    T p=1;
    for (T temp=x/10;temp>0;temp/=10) p*=10;
    for (;p>0;x%=p,p/=10) putchar(x/p+'0');
}

struct Edge {
    int u, v, w;
    Edge() { 
        u=0; 
        v=0; 
        w=0;
    }
    Edge(int U, int V, int W) {
        u=U; 
        v=V; 
        w=W;
    }
    bool operator< (const Edge &b) { return w<b.w; }
};

int n, a[N], res=0;
vector <Edge> edges;

struct Disjoint_Set {
    vector<int> par, rank;
    Disjoint_Set(int n) {
        par.resize(n+1);
        rank.resize(n+1,0);
        for (int i=1; i<=n; i++) par[i]=i;
    }
    int find(int u) {
        if (par[u] != u) par[u]=find(par[u]);
        return par[u];
    }
    bool join(int u, int v) {
        u=find(u);
        v=find(v);
        if (u==v) return false;
        if (rank[u]==rank[v]) rank[u]++;
        if (rank[u]>rank[v]) par[v]=u;
        else par[u]=v;
        return true;
    }
};

int32_t main() {
    FastIO;
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);
    Read(n);
    for (int i=1;i<=n;i++)
        Read(a[i]);
    Disjoint_Set DSU(n);
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            edges.push_back(Edge(i,j,min(a[i]%a[j],a[j]%a[i])));
    sort(edges.begin(), edges.end());
    for (Edge e:edges) {
        if (DSU.join(e.u,e.v))
            res+=e.w;
    }
    Write(res);
    return 0;
}