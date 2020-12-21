#include <bits/stdc++.h>

using namespace std;

#define lint long long
#define ld long double
#define pii pair<int, int>
#define TASK "socks"
mt19937 rd;

const int N = 500001;

char ch;
template < class T > void readNumber (T &q) 
{
    ch = getchar();
    while (ch > '9' || ch < '0') 
        ch = getchar();
    q = 0;
    while (ch >= '0' && ch <= '9') 
    {
        q = 10 * q + ch - '0';
        ch = getchar();
    }
}

int n, q, Q[N];
char C[N];
vector<int> g[N];

void enter()
{
    readNumber(n);
    readNumber(q);
    for (int i=1; i<=n; ++i) 
        readNumber(C[i]);
    for (int i=1, u, v; i < n; ++i)
    {
        readNumber(u);
        readNumber(v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i=1; i<=q; ++i) 
        readNumber(Q[i]);
}

int in[N], out[N], ttime, par[N], depth[N];

void dfs(int u, int p) 
{
    in[u] = ++ttime;
    for (int v : g[u]) 
    {
        if (v == p) continue;
        par[v] = u;
        depth[v] = depth[u];
        dfs(v, u);
    }
    out[u] = ttime;
}

void init() 
{
    ttime = 0;
    dfs(1, -1);
}

bool isUparentV (int u, int v) 
{
    return in[u] <= in[v] && out[v] <= out[u];
}

vector<int> Red;
void sub3() 
{
    for (int i=1; i<=n; ++i) 
    {
        if (C[i]) 
        {
            for (int r : Red) 
            {

            }
        }
    }
}

int branch[N];
void dfs2 (int u, int p, int b) 
{
    for (int v : g[u]) 
    {
        if (v == p) continue;
        branch[v] = b;
        dfs2(v, u, b);
    }
}

int state[N];

bool sub2() 
{
    int root = 0;
    for (int i=1; i<=n; ++i) 
    {
        if (g[i].size() == 3) 
        {
            if (root == 0)
                root = i;
            else 
                return false;
        }
        else 
        {
            if (g[i].size() > 3) 
                return false;
        }
    }

    for (int i=1; i<=3; ++i) 
    {
        dfs2(g[root][i-1], root, i);
    }

    vector<int> cnt(4, 0);

    for (int i=1; i<=n; ++i) 
    {
        if (C[i]) 
        {
            cnt[branch[i]]++;
        }
        state[i] = C[i];
    }

    int ff = 0;
    
    if (cnt[0] + cnt[1] + cnt[2] + cnt[3] <= 1) 
        ff = 0;
    else 
    {
        if (((!!cnt[1]) + (!!(cnt[2])) + (!!(cnt[3]))) == 3) 
            ff = 2;
        else 
            ff = 1;
    }
    cout << ff << '\n';

    for (int i=1; i<=q; ++i) 
    {
        if (state[Q[i]]) 
        {
            state[Q[i]] = 0;
            cnt[branch[Q[i]]]--;
        }
        else 
        {
            state[Q[i]] = 1;
            cnt[branch[Q[i]]]++;
        }
        if (cnt[0] + cnt[1] + cnt[2] + cnt[3] <= 1) 
            ff = 0;
        else 
        {
            if (((!!cnt[1]) + (!!(cnt[2])) + (!!(cnt[3]))) == 3) 
                ff = 2;
            else 
                ff = 1;
        }
        cout << ff << '\n';
    }
    return true;
}

bool sub1() 
{
    for (int i=1; i<=n; ++i) 
    {
        if (g[i].size() >= 3) 
            return false;
    }
    int cnt = 0;
    for (int i=1; i<=n; ++i) 
    {
        state[i] = C[i];
        cnt += C[i];
    }
    cout << (cnt > 1) << '\n';
    for (int i=1; i<=q; ++i) 
    {
        if (state[Q[i]]) 
        {
            state[Q[i]] = 0;
            cnt--;
        }
        else 
        {
            state[Q[i]] = 1;
            ++cnt;
        }
        cout << (cnt > 1) << '\n';
    }
    return true;
}

void driver()
{
    freopen (TASK".inp", "r", stdin);
    freopen (TASK".out", "w", stdout);
    enter();
    init();
    if (sub1())
        return;
    if (sub2())
        return;
    cout << "-1";
    return;
}

int main()
{
    rd.seed(chrono::high_resolution_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(0);
    driver();
    return 0;
}
