#include <bits/stdc++.h>
using namespace std;

#define lint long long
#define pii pair<int, int> 
#define ld long double
#define TASK "dhaka"

char ch;
template<class T> void readNum(T&q) 
{
    q = 0;
    ch = getchar();
    while (ch>'9' || ch <'0') 
        ch = getchar();
    while (ch >= '0' && ch<= '9') 
    {
        q = 10 * q + ch - '0';
        ch = getchar();
    }
}

const int N = 100001;
int n, m, k ,l;
int a[N];
struct TF 
{
    int v, w;
};
vector<TF> g[N];

void enter() 
{
    readNum(n);
    readNum(m);
    readNum(k);
    readNum(l);
    for (int i=1, s, w, j; i<=n; ++i) 
    {
        readNum(s);
        w = 0;
        while (s--)
        {
            readNum(j);
            w |= 1 << (j - 1);
        }
        a[i] = w;        
    }
    for (int i=1,u,v,w; i<=m; ++i) 
    {
        readNum(u);
        readNum(v);
        readNum(w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
}

struct TV
{
    int u, mask;
    lint cost;

    TV () {} 
    TV (int u, int mask, lint cost) : u(u), mask(mask), cost(cost) {}

    bool operator < (const TV &h) const 
    {
        return cost > h.cost;
    }
};

const int oo = 1e9 + 7;
const lint ooo = 4e18;

lint f[N][32];
bool locked[N][32];

lint solve() 
{
    for (int j,i=1; i<=n; ++i) 
    for (j=(1 << k) - 1; j>=0; --j) 
    {
        f[i][j] = ooo;
        locked[i][j] = false;
    }

    int starting_mask = a[1];
    
    f[1][starting_mask] = 0;
    priority_queue<TV> heap;
    heap.push(TV(1, starting_mask,0));
    TV u, v;
    while (!heap.empty()) 
    {
        u = heap.top(); heap.pop();
        if (locked[u.u][u.mask]) continue;
        locked[u.u][u.mask] = true;
        for (auto & to : g[u.u]) 
        {
            v.u = to.v;
            v.mask = u.mask | a[to.v];
            v.cost = u.cost + to.w;
            if (v.cost < f[v.u][v.mask]) 
            {
                f[v.u][v.mask] = v.cost;
                heap.push(v);
            }
        }
    }   

    lint ans = ooo;

    for (int mask = (1 << k) - 1; mask >= 0; --mask) 
    {
        if (__builtin_popcount(mask) >= l) 
        {
            ans = min(ans, f[n][mask]);
        }
    }    

    if (ans == ooo)
        ans = -1;
    return ans;
}

void driver()
{
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    enter();
    cout << solve();
}

int main()
{
    ios_base::sync_with_stdio(false);
    driver();
}
