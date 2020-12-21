#include <bits/stdc++.h>

const int N = 1e5 + 5, mod = 1e9 + 7;
#define X first
#define Y second
#define fo(i,j,k) for(int i = j; i <= k; ++i)
#define of(i,j,k) for(int i = j; i >= k; --i)
#define PB push_back
#define getbit(i,j) (int)(((i) >> (j)) & 1)
#define all(a) (a).begin(),(a).end()
#define reset(a,val) fill(a+1,a+sizeof(a),val)
#define task "DHAKA"

using namespace std;

typedef pair <int,int> ii;
typedef long long ll;

struct data
{
    int u,val;
    bool operator < (const data &o) const
    {
        return val > o.val;
    }
};

struct data1
{
    int u,val;
    set <int> ap;
    bool operator < (const data1 &o) const
    {
        return val > o.val;
    }
};

vector <ii> child[N];

int a[N][6];
int n,m,k,l;
set <int> wtmelon[N];
set <int> ::iterator it;
int f[1025][20][10],val[20][20];
/// f[i][j]: quãng đường min khi đi với trạng thái i kết thúc tại j
/// với số loại dưa hấu tối thiểu là i
bool vsd[20][20], ap[1025][20][10][10];

void read()
{
    cin >> n >> m >> k >> l;
    fo(i,1,n)
    {
        int x;
        cin >> x;
        fo(j,1,x)
        {
            int u;
            cin >> u;
            wtmelon[i].insert(u);
        }
    }

    fo(i,1,m)
    {
        int u,v,w;
        cin >> u >> v >> w;
        vsd[u][v] = vsd[v][u] = true;
        val[u][v] = val[v][u] = w;
        child[u].PB({v,w});
        child[v].PB({u,w});
    }
}

int d[N]; set <int> melon[N];
priority_queue <data> hp;
priority_queue <data1> dp;
bool ok = false;

void Dijkstra()
{
    fo(i,1,n) d[i] = mod;
    d[1] = 0;
    hp.push({1,d[1]});
    if(wtmelon[1].size() > 0) ok = true;
    while(!hp.empty())
    {
        int u = hp.top().u;
        int du = hp.top().val;

        hp.pop();
        if(du > d[u]) continue;

        for(auto s : child[u])
        {
            int v = s.X;
            int w = s.Y;
            if(!wtmelon[v].empty()) ok = true;
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                hp.push({v,d[v]});
            }
        }
    }

    if(d[n] == mod) cout << -1;
    else if(l == 1 && ok == true) cout << d[n];
    else cout << d[n];
    exit(0);
}

void dijkstra()
{
    int ans = mod;
    fo(i,1,n) d[i] = mod; d[1] = 0;
    dp.push({1,d[1],wtmelon[1]});

    while(!dp.empty())
    {
        int u = dp.top().u;
        int du = dp.top().val;
        set <int> ap = dp.top().ap;

        dp.pop();
        if(du > d[u]) continue;

        for(auto s : child[u])
        {
            int v = s.X;
            int w = s.Y;
            set <int> t; t = ap;

            for(it = wtmelon[v].begin(); it != wtmelon[v].end(); ++it)
                t.insert(*it);

            if(v == n)
            {
                if(d[v] > d[u] + w && t.size() >= l)
                {
                    d[v] = d[u] + w;
                    ans = min(ans,d[v]);
                    dp.push({v,d[v],t});
                }
                ans = min(ans,d[v]);
            }
            else
                if(d[v] > d[u] + w)
                {
                    d[v] = d[u] + w;
                    dp.push({v,d[v],t});
                }
        }
    }

    cout << (ans == mod ? -1 : ans);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    read();
    if(l == 0 || k == 1) Dijkstra();
    else dijkstra();

    return 0;
}
