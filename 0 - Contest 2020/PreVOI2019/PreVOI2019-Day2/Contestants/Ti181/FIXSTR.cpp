#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;i++)
#define fid(i,a,b) for(int i=a;i>=b;i--)
#define maxn 1000005
#define ll long long
#define pii pair<int, int>
#define TTT "FIXSTR"
using namespace std;
struct data{char x; int u, v;};
int n, m;
char s[maxn];
int kq[maxn];
string tt;
data q[maxn];
int it[maxn * 4], st[maxn * 4];
vector<int> g[maxn];
void lazy(int id)
{
    if(st[id])
    {
        it[id * 2] +=  st[id];
        it[id * 2 + 1] += st[id];
        st[id * 2] += st[id];
        st[id * 2 + 1] += st[id];
        st[id] = 0;
    }
}
void update(int id, int l, int r, int u, int v, int val)
{
    if(l > v || r < u) return;
    if(u <= l && r <= v)
    {
        it[id] += val;
        st[id] += val;
        return;
    }
    lazy(id);
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    it[id] = min(it[id * 2], it[id * 2 + 1]);
}
int get(int id, int l, int r, int u, int v)
{
    if(l > v || r < u) return 1e9;
    if(u <= l && r <= v) return it[id];
    lazy(id);
    int mid = (l + r) / 2;
    return min(get(id * 2, l, mid, u, v),  get(id * 2 + 1, mid + 1, r, u, v));
}
int get1(int id, int l, int r, int u)
{
    if(l  > u || r < u) return 0;
    if(l == r) return it[id];
    lazy(id);
    int mid = (l + r) / 2;
    return get1(id * 2, l, mid, u) + get1(id * 2 + 1, mid + 1, r, u);
}
int d, e, f;
void DFS(int u)
{
    if(u)
    {
        if(q[u].x == 'C')
        {
            if(s[q[u].u] == '(')
            {
                s[q[u].u] = ')';
                update(1, 0, n, q[u].u, n, -2);
            }
            else
            {
                s[q[u].u] = '(';
                update(1, 0, n, q[u].u, n, 2);
            }
        }
        else if(q[u].x == 'Q')
        {
            d = get1(1, 0, n, q[u].u - 1);
            e = get1(1, 0, n, q[u].v);
            f = get(1, 0, n, q[u].u, q[u].v);
            kq[u] = max(d - f, 0) + max(max(d - f, 0) + e - d, 0);
        }
    }
    for(auto &v: g[u])
        DFS(v);
    if(q[u].x == 'C')
    {
        if(s[q[u].u] == '(')
        {
            s[q[u].u] = ')';
            update(1, 0, n, q[u].u, n, -2);
        }
        else
        {
            s[q[u].u] = '(';
            update(1, 0, n, q[u].u, n, 2);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(TTT".inp","r",stdin);
    freopen(TTT".out","w",stdout);
    cin >> tt;
    n = tt.length();
    tt = " " + tt;
    fi(i, 1, n) s[i] = tt[i];
    int tg = 0;
    fi(i, 1, n)
    {
        if(s[i] == '(') tg++; else tg--;
        update(1, 0, n, i, i, tg);
    }
    cin >> m;
    fi(i, 1, m)
    {
        cin >> q[i].x;
        if(q[i].x == 'Q') cin >> q[i].u >> q[i].v;
        else cin >> q[i].u;
    }
    fi(i, 1, m)
    if(q[i].x == 'U')
    {
        if(q[i].u != i) g[q[i].u - 1].push_back(i);
    }
    else
    {
        g[i - 1].push_back(i);
    }
    DFS(0);
    fi(i, 1, m)
    if(q[i].x == 'Q') cout << kq[i] << '\n';
}
