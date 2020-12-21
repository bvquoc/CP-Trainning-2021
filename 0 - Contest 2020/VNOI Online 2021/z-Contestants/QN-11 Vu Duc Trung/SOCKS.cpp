#include <bits/stdc++.h>
#define task "SOCKS"
typedef long long int ll;
using namespace std;

const int N = 500010;
int n, q, col[N];
vector<int> adj[N];

void sub1(void) {
    ll redCol = 0;
    for (int i = 1; i <= n; ++i) redCol += (col[i] == 1);
    cout << (redCol > 1 ? 1 : 0) << '\n';
    while (q--) {
        int x; cin >> x;
        if (col[x] == 1) redCol--;
        else redCol++;
        col[x] ^= 1;
        cout << (redCol > 1 ? 1 : 0) << '\n';
    }
    exit(0);
}
int red, Color[N],t[N],vis[N],deg[N],dem,g[N],f[N];

void DFS(int u,int c)
{
    vis[u]=1;
    Color[u]=c;
    for(int v:adj[u])
    {
        if(vis[v])
            continue;
        DFS(v,c);
    }
}
void sub2()
{
    int st;
    for(int i=1; i<=n; i++)
        if(adj[i].size()==3)
        {
            st=i;
            break;
        }
    vis[st]=1;
    for(int i=0; i<adj[st].size(); i++)
    {
        int v=adj[st][i];
        DFS(v,i+1);
    }
    for(int i=1; i<=n; i++)
        if(Color[i])
        {
            red++;
            t[Color[i]]++;
        }
    for(int i=1; i<=3; i++)
        if(t[i])
            dem++;
    if(dem==3)
        cout<<"2\n";
    if(dem==2)
        cout<<"1\n";
    if(dem==1)
    {
        if(red>1)
            cout<<"1\n";
        else
            cout<<"0\n";
    }
    while(q--)
    {
        int x;
        dem=0;
        cin>>x;
        if(Color[x])
        {
            Color[x]=0;
            red--;
            t[Color[x]]--;
        }
        else
        {
            Color[x]=1;
            red++;
            t[Color[x]]++;
        }
        for(int i=1; i<=3; i++)
            if(t[i])
                dem++;
        if(dem==3)
            cout<<"2\n";
        if(dem==2)
            cout<<"1\n";
        if(dem==1)
        {
            if(red>1)
                cout<<"1\n";
            else
                cout<<"0\n";
        }
    }
}


int main() {
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> col[i];
    }
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool checkSub1 = true, checkSub2 = true;
    int rSub2 = -1;
    for (int i = 1; i <= n; ++i) {
        if (adj[i].size() > 2) {
            checkSub1 = false;
        }
        if (adj[i].size() > 3) {
            checkSub2 = false;
        }
        if (adj[i].size() == 3 && rSub2 == -1) {
            rSub2 = i;
        }
        if (adj[i].size() == 3 && rSub2 != -1) {
            checkSub2 = false;
        }
    }
    if (checkSub1) sub1();
    else sub2();
    return 0;
}

