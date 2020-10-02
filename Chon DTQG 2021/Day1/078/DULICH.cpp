#include <bits/stdc++.h>

using namespace std;
const int oo=1e6;
int n,m,d[205][205],s,l[205],t[205],k,res=oo,sq;
bool cx[205],ok;
vector<int> lin;

void dijkstra(int st) {
    for(int i=1;i<=n;++i) {
        l[i]=oo;
        t[i]=-1;
    }
    l[st]=0;
    memset(cx,true,sizeof(cx));
    while(true) {
        int mn=oo,k=-1;
        for(int i=1;i<=n;++i) {
            if(cx[i]==true && l[i]<mn) {
                mn=l[i];
                k=i;
            }
        }
        if(k==-1)   break;
        cx[k]=false;
        for(int i=1;i<=n;++i) {
            if(cx[i]==true && d[k][i]>0 && l[i]>l[k]+d[k][i]) {
                l[i]=l[k]+d[k][i];
                t[i]=k;
            }
        }
    }
}

void track(int u) {
    if(cx[u]==false && t[u]!=-1) {
        ok=false;
        return;
    }
    if(t[u]==-1) {
        ++s;
        return;
    }
    else {
        ++s;
        track(t[u]);
        cx[u]=false;
    }
}

void printtrack1(int u) {
    if(t[u]==-1) {
        lin.push_back(u);
        return;
    }
    else {
        printtrack1(t[u]);
        lin.push_back(u);
    }
}

void printtrack2(int u) {
    if(t[u]==-1) {
        return;
    }
    else {
        lin.push_back(u);
        printtrack2(t[u]);
    }
}

void solve(int st) {
    k=st;
    for(int i=1;i<=n;++i) {
        if(l[i]==oo || i==st)   continue;
        for(int j=i+1;j<=n;++j) {
            if(d[i][j]==0)   continue;
            ok=true;
            memset(cx,true,sizeof(cx));
            s=0;
            track(i);
            track(j);
            if(ok==false)   continue;
            --s;
            if(s<3) continue;
            if(res>l[i]+l[j]+d[i][j]) {
                res=l[i]+l[j]+d[i][j];
                sq=s;
                lin.clear();
                printtrack1(i);
                printtrack2(j);
            }
        }
    }
}

int32_t main() {
    freopen("DULICH.INP","r",stdin);
    freopen("DULICH.OUT","w",stdout);
    scanf("%d%d", &n, &m);
    for(int i=1;i<=m;++i) {
        int u,v,c;
        scanf("%d%d%d", &u, &v, &c);
        if(d[u][v]>0) d[u][v]=d[v][u]=min(d[u][v],c);
        else d[u][v]=d[v][u]=c;
    }
    for(int i=1;i<=n;++i) {
        dijkstra(i);
        solve(i);
    }
    if(res==oo)    printf("0");
    else {
        printf("1\n");
        printf("%d\n", res);
        printf("%d\n", sq);
        for(int i=0;i<lin.size();++i)   printf("%d\n", lin[i]);
    }
    return 0;
}
