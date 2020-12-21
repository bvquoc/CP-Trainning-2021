#include <bits/stdc++.h>
#define x first
#define y second
#define ll long long
#define mod 1000000007
#define pii pair <int ,int>
#define reset(x) memset(x, 0,sizeof(x))
#define PB push_back
#define mp make_pair
#define maxn 500005
#define task "socks"

using namespace std;

int n,q,a[maxn],ma,pos[maxn],root,d[maxn];
vector <int> ke[maxn];

void sub1() {
    int dem=0;
    for(int i=1; i<=n; i++)
        dem+=a[i];
    if(dem>=2)
        cout<<1<<'\n';
    else
        cout<<0<<'\n';
    while(q--) {
        int x;
        cin>>x;
        if(a[x]==0)
            dem++,a[x]++;
        else
            dem--,a[x]--;
        if(dem>=2)
            cout<<1<<'\n';
        else
            cout<<0<<'\n';
    }
}

void dfs(int u,int pa) {
    for(int v:ke[u])
        if(v!=pa) {
            pos[v]=pos[u];
            dfs(v,u);
        }
}

void sub2() {
    for(int i=1; i<=n; i++)
        if(ke[i].size()==3) {
            root=i;
            int cnt=0;
            for(int v:ke[i]) {
                pos[v]=++cnt;
                dfs(v,i);
            }
            break;
        }
    int dem1=0,dem2=0,dem3=0;
    for(int i=1; i<=n; i++)
        if(a[i]==1) {
            if(pos[i]==1)
                dem1++;
            else if(pos[i]==2)
                dem2++;
            else if(pos[i]==3)
                dem3++;
        }
    int s=(dem1!=0)+(dem2!=0)+(dem3!=0);
    if(s==3)
        cout<<2<<'\n';
    else if(s==2)
        cout<<1<<'\n';
    else {
        if(a[root]==1)
            cout<<1<<'\n';
        else
            cout<<0<<'\n';
    }
    while(q--) {
        int x;
        cin>>x;
        if(a[x]==0) {
            a[x]++;
            if(pos[x]==1)
                dem1++;
            if(pos[x]==2)
                dem2++;
            if(pos[x]==3)
                dem3++;
        } else {
            a[x]--;
            if(pos[x]==1)
                dem1--;
            if(pos[x]==2)
                dem2--;
            if(pos[x]==3)
                dem3--;
        }
        s=(dem1!=0)+(dem2!=0)+(dem3!=0);
        if(s==3)
            cout<<2<<'\n';
        else if(s==2)
            cout<<1<<'\n';
        else {
            if(a[root]==1)
                cout<<1<<'\n';
            else
                cout<<0<<'\n';
        }
    }
}

void dfs3(int u,int pa) {
    for(int v:ke[u])
        if(v!=pa) {
            dfs3(v,u);
            d[u]+=d[v];
        }
    if(d[u]==0&&a[u]==1)
        d[u]=1;
}

void sub3() {
    dfs3(1,0);
    cout<<d[1]<<'\n';
    while(q--) {
        int x,dem=0;
        cin>>x;
        if(a[x]==1)
            a[x]--;
        else
            a[x]++;
        for(int i=1; i<=n; i++) {
            d[i]=0;
            dem+=a[i];
        }
        if(dem<=1) {
            cout<<0<<'\n';
            continue;
        }
        dfs3(1,0);
        cout<<d[1]<<'\n';
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>q;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=1; i<n; i++) {
        int u,v;
        cin>>u>>v;
        ke[u].PB(v);
        ke[v].PB(u);
    }
    for(int i=1; i<=n; i++)
        ma=max(ma,(int)ke[i].size());
    if(ma<=2) {
        sub1();
        return 0;
    } else if(ma<=3) {
        sub2();
        return 0;
    } else {
        sub3();
        return 0;
    }
}
