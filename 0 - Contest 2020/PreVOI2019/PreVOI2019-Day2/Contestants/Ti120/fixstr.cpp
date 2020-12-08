#include <bits/stdc++.h>
#define maxn 1000009
#define pb push_back

using namespace std;
int a[maxn],t[maxn*4],t1[maxn*4],m,n;
int x[maxn],y[maxn],z[maxn],ans[maxn];
vector<int> vec[maxn];

void build(int u, int l, int r){
    if(l==r){
        t[u]=a[l];
        return;
    }
    int m=(l+r)/2;
    build(u*2,l,m);
    build(u*2+1,m+1,r);
    t[u]=min(t[u*2],t[u*2+1]);
}

void ud(int u, int l, int r, int vt, int gt){
    if(r<vt) return;
    if(l>=vt){
        t[u]+=gt;
        t1[u]+=gt;
        return;
    }
    if(t1[u]){
        t[u*2]+=t1[u];t1[u*2]+=t1[u];
        t[u*2+1]+=t1[u];t1[u*2+1]+=t1[u];
        t1[u]=0;
    }
    int m=(l+r)/2;
    ud(u*2,l,m,vt,gt);
    ud(u*2+1,m+1,r,vt,gt);
    t[u]=min(t[u*2],t[u*2+1]);
}

int get(int u, int l, int r, int l1, int r1){
    if(r1<l || r<l1)return 1e7;
    if(l1<=l && r<=r1) return t[u];
    int m=(l+r)/2;
    if(t1[u]){
        t[u*2]+=t1[u];t1[u*2]+=t1[u];
        t[u*2+1]+=t1[u];t1[u*2+1]+=t1[u];
        t1[u]=0;
    }
    return min(get(u*2,l,m,l1,r1),get(u*2+1,m+1,r,l1,r1));
    int tg = min(get(u*2,l,m,l1,r1),get(u*2+1,m+1,r,l1,r1));
    t[u]=min(t[u*2],t[u*2+1]);
    return tg;
}
int t2[maxn];
void add(int x, int gt){for(;x<=n;x+=x&-x)t2[x]+=gt;}
int get(int x){int res=0;for(;x;x-=x&-x)res+=t2[x];return res;}

string s;

void dfs(int i){
    int tg;
    int j=y[i];
    if(x[i]==1){
        if(s[j]==')')s[j]='(';
        else s[j]=')';
        tg=(s[j]=='(' ? 2:-2);
        add(j,tg);
        ud(1,0,n,j,tg);
    }
    if(x[i]==2){
        ans[i]=get(y[i]-1)+get(z[i])-2*get(1,0,n,y[i]-1,z[i]);
    }
    for(auto v:vec[i])dfs(v);
    if(x[i]==1){
        if(s[j]==')')s[j]='(';
        else s[j]=')';
        add(j,-tg);
        ud(1,0,n,j,-tg);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("fixstr.inp", "r", stdin);
    freopen("fixstr.out", "w", stdout);
    cin >> s;
    n=s.length();
    s=' '+s;
    for(int i=1; i<=n; ++i){
        int tg=(s[i]=='('?1:-1);
        a[i]=a[i-1]+tg;
        add(i,tg);
    }
    build(1,0,n);
    cin >> m;
    for(int i=1; i<=m; ++i){
        char c;
        cin >> c >> y[i];
        if(c=='C')x[i]=1;
        if(c=='Q'){
            x[i]=2;
            cin >>z[i];
        }
        if(c=='U')x[i]=3;
        if(x[i]==3)vec[y[i]-1].pb(i);
        else vec[i-1].pb(i);
    }
    for(auto x:vec[0])dfs(x);
    for(int i=1; i<=m; ++i)if(x[i]==2)cout << ans[i] <<'\n';
    return 0;
}
/*
((()))
10
C 1
Q 2 5
C 5
Q 1 6
U 3
C 4
Q 3 6
U 5
C 1
Q 1 5

0
2
0
3
*/
