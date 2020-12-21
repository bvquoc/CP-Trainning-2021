#include <bits/stdc++.h>
#define int long long
using namespace std;
const string filename="DHAKA";
typedef pair<int, int> ii;
const int nmax=1e5+5,oo=1e15;
int n,m,K,L,s[nmax],a[nmax][7],l[nmax],res=oo,ty=0,t[nmax];
vector<vector<ii> > d;
bool cx[nmax],take[nmax];

void dijkstra(int st) {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for(int i=1;i<=n;++i)   l[i]=oo;
    l[st]=0;
    pq.push(ii(0, st));
    while (pq.size()) {
        int u=pq.top().second;
        int lu=pq.top().first;
        pq.pop();
        if(lu!=l[u])    continue;
        for (int i=0;i<d[u].size();i++) {
            int v=d[u][i].second;
            int uv=d[u][i].first;
            if(l[v]>lu+uv) {
                l[v]=lu+uv;
                pq.push(ii(l[v], v));
            }
        }
    }
}

int track(int u, int sumty) {
    int sum=0;
    if(s[u]>0) {
        for(int i=1;i<=s[u];++i) {
            if(!take[a[u][i]]) {
                take[a[u][i]]=true;
                ++sum;
            }
        }
    }
    if(t[u]==-1)    return sumty+sum;
    else return track(t[u],sumty+sum);
}

void backtrack(int u, int sumPath) {
    if(u==n) {
        for(int i=1;i<=K;++i)   take[i]=false;
        int sumty=track(n,0);
        if(sumty>=L) {
            if(res==sumPath && ty<sumty) {
                ty=sumty;
            }
            if(res>sumPath) {
                res=sumPath;
                ty=sumty;
            }
        }
        return;
    }
    for(int i=0;i<d[u].size();++i) {
        int v=d[u][i].second;
        int uv=d[u][i].first;
        if(!cx[v]) {
            cx[v]=true;
            t[v]=u;
            backtrack(v,sumPath+uv);
            cx[v]=false;
        }
    }
}

bool check() {
    bool typ[nmax];
    int sum=0;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=s[i];++j) {
            if(!typ[a[i][j]]) {
                ++sum;
                typ[a[i][j]]=true;
            }
        }
    }
    if(sum>=L)  return true;
    return false;
}

int32_t main() {
    freopen((filename+".INP").c_str(),"r",stdin);
    freopen((filename+".OUT").c_str(),"w",stdout);
    scanf("%lld%lld%lld%lld", &n, &m, &K, &L);
    d.resize(n+2);
    for(int i=1;i<=n;++i) {
        scanf("%lld", &s[i]);
        for(int j=1;j<=s[i];++j)    scanf("%lld", &a[i][j]);
    }
    for(int i=1;i<=m;++i) {
        int u,v,c;
        scanf("%lld%lld%lld", &u, &v, &c);
        d[u].push_back(ii(c,v));
        d[v].push_back(ii(c,u));
    }
    if(L==0) {
        dijkstra(1);
        if(l[n]!=oo)    printf("%lld", l[n]);
        else printf("-1");
        return 0;
    }
    if(K==1 || L==1) {
        res=oo;
        for(int i=1;i<=n;++i) {
            if(s[i]>0) {
                dijkstra(i);
                res=min(res,l[1]+l[n]);
            }
        }
        if(res!=oo)    printf("%lld", res);
        else printf("-1");
        return 0;
    }
    if(!check()) {
        printf("-1");
        return 0;
    }
    if(n<=10) {
        for(int i=1;i<=n;++i)   t[i]=-1;
        cx[1]=true;
        backtrack(1,0);
        printf("%lld", res);
        return 0;
    }
    return 0;
}
