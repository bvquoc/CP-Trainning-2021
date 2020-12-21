#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxN=5e5+5;
vector<int> h[maxN];
int dem[maxN], cnt[maxN], par[maxN], f[maxN], sum;
int n, m, k;
string s;
void add(int X){
    ++dem[X];
    sum-=cnt[X];
    cnt[X]=max(0, dem[X]-f[X]);
    sum+=cnt[X];
}
void rem(int X){
    --dem[X];
    sum-=cnt[X];
    cnt[X]=max(0, dem[X]-f[X]);
    sum+=cnt[X];
}
int check(int X){
    memset(dem, 0, sizeof dem);
    memset(cnt, 0, sizeof cnt);
    sum=0;
    for (int i=1; i<=X; ++i){
        add(par[i]);
    }
    if (sum<=k) return 1;
    for (int i=2; i+X-1<=n; ++i){
        add(par[i+X-1]);
        rem(par[i-1]);
        if (sum<=k) return i;
    }
    return -1;
}
void dfs(int u, int Par){
    par[u]=Par;
    for (int i=0; i<h[u].size(); ++i){
        int v=h[u][i];
        if (par[v]!=0) continue;
        dfs(v, Par);
    }
    f[Par]+=1*(s[u]=='1');
}
int main()
{
    ifstream cin("DECOR.INP");
    ofstream cout("DECOR.OUT");
    cin >> n >> m >> k;
    cin >> s;
    s="#"+s;
    for (int i=1; i<=m; ++i) {
        int u, v;
        cin >> u >> v;
        h[u].pb(v);
        h[v].pb(u);
    }

    for (int i=1; i<=n; ++i){
        if (par[i]!=0) continue;
        dfs(i, i);
    }
    int L=1, R=n, res=-1, ires;
    while (L<=R){
        int mid=(L+R)/2;
        int tmp=check(mid);
        if (tmp!=-1) res=mid, ires=tmp, L=mid+1;
        else R=mid-1;
    }
    if (res!=-1) cout << ires << " " << ires+res-1;
    else cout << -1;
    return 0;
}
