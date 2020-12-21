#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define BIT(x,i) (1&((x)>>(i)))
using namespace std;
const int N = (int)5e5+1;
int n , q;
int color[N] , id[N] , visited[N] , deg[N];
vector<int> f[N];
pii way[N];
void subtask1()
{
    int cnt = 0;
    for(int i=1 ; i<=n ; ++i) cnt+=color[i];
    if(cnt >= 2) cout << 1 << '\n';
    else cout << 0 << '\n';
    int u;
    while(q--)
    {
        cin >> u;
        if(color[u] == 1) color[u] = 0 , --cnt;
        else color[u] = 1 , ++cnt;
        if(cnt >= 2) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}
int cnt[5];
void dfs(int u , int t)
{
    visited[u] = 1;
    id[u] = t;
    for(int i=0 ; i<(int)f[u].size() ; ++i)
    {
        int v = f[u][i];
        if(visited[v]) continue;
        dfs(v , t);
    }
}
void subtask2()
{
    int root;
    for(int i=1 ; i<=n ; ++i)
    {
        if(deg[i] == 3)
        {
            root = i;
            break;
        }
    }
    for(int i=1 ; i<n ; ++i)
    {
        f[way[i].fi].push_back(way[i].se);
        f[way[i].se].push_back(way[i].fi);
    }
    visited[root] = 1;
    for(int i=0 ; i<(int)f[root].size() ; ++i)
    {
        dfs(f[root][i] , i+1);
    }
    for(int i=1 ; i<=n ; ++i)
    {
        if(color[i] && i != root)
        {
            cnt[id[i]]++;
        }
    }
    int tmp = 0;
    for(int i=1 ; i<=3 ; ++i)
    {
        if(cnt[i]) ++tmp;
    }
    if(tmp == 3) cout << 2 << '\n';
    else if(tmp == 2) cout << 1 << '\n';
    else if(tmp == 1)
    {
        for(int i=1 ; i<=3 ; ++i) if(cnt[i])
        {
            if(cnt[i] + color[root] >= 2)
            {
                cout << 1 << '\n';
            }
            else cout << 0 << '\n';
        }
    }
    else cout << 0 << '\n';
    while(q--)
    {
        int u;
        cin >> u;
        if(color[u]) color[u] = 0 , --cnt[id[u]];
        else color[u] = 1 , ++cnt[id[u]];
        int tmp = 0;
        for(int i=1 ; i<=3 ; ++i)
        {
            if(cnt[i]) ++tmp;
        }
        if(tmp == 3) cout << 2 << '\n';
        else if(tmp == 2) cout << 1 << '\n';
        else if(tmp == 1)
        {
            for(int i=1 ; i<=3 ; ++i) if(cnt[i])
            {
                if(cnt[i] + color[root] >= 2)
                {
                    cout << 1 << '\n';
                }
                else cout << 0 << '\n';
            }
        }
        else cout << 0 << '\n';
    }
}
int timeIn[N] , timeOut[N] , timeVisit = 0;
void dfs2(int u)
{
    timeIn[u] = id[u] = ++timeVisit;
    for(int i=0 ; i<(int)f[u].size() ; ++i)
    {
        int v = f[u][i];
        dfs2(v);
    }
    timeOut[u] = timeVisit;
}
stack<int> s;
bool cmp(int x , int y)
{
    return id[x] < id[y];
}
int b[N] , m;
void subtask3()
{
    for(int i=1 ; i<n ; ++i)
    {
        f[way[i].fi].push_back(way[i].se);
    }
    dfs2(1);
    int root;
    for(int i=1 ; i<=n ; ++i)
    {
        if(deg[i] == 1 && f[i].size())
        {
            root = i;
            break;
        }
    }
    m = 0;
    dfs2(root);
    for(int i=1 ; i<=n ; ++i)
    {
        if(color[i]) b[++m] = i;
    }
    sort(b+1 , b+m+1 , cmp);
    for(int i=1 ; i<=m ; ++i)
    {
        while(s.size() && timeIn[s.top()] <= id[b[i]] && id[b[i]] <= timeOut[s.top()]) s.pop();
        s.push(b[i]);
    }
    int tmp = s.size();
    cout << tmp/2+tmp%2 << '\n';
    while(q--)
    {
        while(s.size()) s.pop();
        int u;
        cin >> u;
        color[u] = 1-color[u];
        m = 0;
         for(int i=1 ; i<=n ; ++i)
        {
            if(color[i]) b[++m] = i;
        }
        sort(b+1 , b+m+1 , cmp);
        for(int i=1 ; i<=m ; ++i)
        {
            while(s.size() && timeIn[s.top()] <= id[b[i]] && id[b[i]] <= timeOut[s.top()]) s.pop();
            s.push(b[i]);
        }
        int tmp = s.size();
        cout << tmp/2+tmp%2 << '\n';
    }
}
int getSubtask()
{
    int maxDeg = 0;
    for(int i=1 ; i<=n ; ++i) maxDeg = max(maxDeg , deg[i]);
    if(maxDeg == 2) return 1;
    if(maxDeg == 3)
    {
        int cnt = 0;
        for(int i=1 ; i<=n ; ++i) if(deg[i] == maxDeg) ++cnt;
        if(cnt == 1) return 2;
    }
    return 3;
}
void inp()
{
    cin >> n >> q;
    for(int i=1 ; i<=n ; ++i) cin >> color[i];
    for(int i=1 ; i<n ; ++i)
    {
        cin >> way[i].fi >> way[i].se;
        deg[way[i].fi]++;
        deg[way[i].se]++;
    }
}
void solve()
{
    int st = getSubtask();
    if(st == 1) subtask1();
    else if(st == 2) subtask2();
    else subtask3();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("SOCKS.INP" , "r" , stdin);
    freopen("SOCKS.OUT" , "w" , stdout);
    inp();
    solve();
    return 0;
}
