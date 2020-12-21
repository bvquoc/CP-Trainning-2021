#include <bits/stdc++.h>
#define ii pair <int, int>
#define X first
#define Y second

using namespace std;

const int N = 1e3+7;
const int OO = 1e9+7;

struct Data
{
    int u;
    int v;
    int w;
};

int n, m, k, l, res = OO;
int x[N];
vector <int> a[N];
Data s[N];
vector <ii> g[N];

void dijkstra()
{
    priority_queue <ii, vector <ii>, greater <ii>> q;
    int d[N], path[N];
    for(int i = 1; i <= n; i++)
    {
        path[i] = 0;
        d[i] = OO;
    }
    d[1] = 0;
    path[1] = -1;
    q.push({0, 1});
    while(q.size())
    {
        int u = q.top().Y;
        int du = q.top().X;
        q.pop();
        if(d[u] != du)
            continue;
        for(auto x : g[u])
        {
            int v = x.Y;
            int dv = x.X;
            if(d[v] > dv + du)
            {
                path[v] = u;
                d[v] = dv + du;
                q.push({d[v], v});
            }
        }
    }
//    cout << d[n] << endl;
    if(res > d[n])
    {
        set <int> st;
        st.clear();
        int u = n;
        while(u != -1)
        {
            for(auto x : a[u])
                st.insert(x);
            u = path[u];
        }
        if(st.size() >= l)
        {
            if(d[n] == 4)
            {
                cout << n << ' ' << a[n].size() << '\n';
                int u = path[n];
                while(u != -1)
                {
                    cout << u << ' ' << a[u].size() << '\n';
                    u = path[u];
                }
                cout << endl;
            }
            res = d[n];
        }
    }
}

void update()
{
//    for(int i = 1; i <= m; i++)
//        cout << x[i] << ' ';
//    cout << endl;
    for(int i = 1; i <= m; i++)
        if(x[i])
        {
            int u = s[i].u;
            int v = s[i].v;
            int w = s[i].w;
            g[u].push_back({w, v});
            g[v].push_back({w, u});
        }
    if(g[1].empty() || g[n].empty())
        return;
    dijkstra();
}

void backtracking(int id)
{
    for(int i = 0; i <= 1; i++)
    {
        x[id] = i;
        if(id == m)
            update();
        else
            backtracking(id + 1);
    }
}
int D1[N];
void DIJ(int l)
{
    priority_queue <ii, vector <ii>, greater <ii>> q;
    for(int i = 1; i <= n; i++)
        D1[i] = OO;
    D1[l] = 0;
    q.push({0, l});
    while(q.size())
    {
        int u = q.top().Y;
        int du = q.top().X;
        q.pop();
        if(du != D1[u])
            continue;
        for(auto x : g[u])
        {
            int v = x.Y;
            int dv = x.X;
            if(D1[v] > dv + du)
            {
                D1[v] = dv + du;
                q.push({D1[v], v});
            }
        }
    }
}
int D2[N];
void DIJ2(int l)
{
    priority_queue <ii, vector <ii>, greater <ii>> q;
    for(int i = 1; i <= n; i++)
        D2[i] = OO;
    D2[l] = 0;
    q.push({0, l});
    while(q.size())
    {
        int u = q.top().Y;
        int du = q.top().X;
        q.pop();
        if(du != D2[u])
            continue;
        for(auto x : g[u])
        {
            int v = x.Y;
            int dv = x.X;
            if(D2[v] > dv + du)
            {
                D2[v] = dv + du;
                q.push({D2[v], v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#define TASK "DHAKA"
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);

    cin >> n >> m >> k >> l;
    for(int i = 1; i <= n; i++)
    {
        int T;
        cin >> T;
        for(int j = 1; j <= T; j++)
        {
            int u;
            cin >> u;
            a[i].push_back(u);
        }
    }

    for(int i = 1; i <= m; i++)
        cin >> s[i].u >> s[i].v >> s[i].w;

    if(l == 1)
    {
        for(int i = 1; i <= m; i++)
        {
            int u = s[i].u;
            int v = s[i].v;
            int w = s[i].w;
            g[u].push_back({w, v});
            g[v].push_back({w, u});
        }
        DIJ(1);
        DIJ2(n);
        int R = OO;
        for(int i = 1; i <= n; i++)
            if(a[i].size())
                res = min(res, D1[i] + D2[i]);
        if(res == OO)
            cout << -1;
        else
            cout << res;
    }
    else if(l == 0)
    {
        for(int i = 1; i <= m; i++)
        {
            int u = s[i].u;
            int v = s[i].v;
            int w = s[i].w;
            g[u].push_back({w, v});
            g[v].push_back({w, u});
        }
        DIJ(1);
        if(D1[n] == OO)
            cout << -1;
        else
            cout << D1[n];
    }
    else
    {
        backtracking(1);
        if(res == OO)
            cout << -1;
        else
            cout << res;
    }

    return 0;
}
