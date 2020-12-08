#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long lli;
typedef pair<int, int> pii;
const int maxn = 1e6 + 5;
const int INF = 1e9 + 19;
int n, m;
string s, rev_s;

string temp[maxn];

vector<int> to[maxn];
int par[maxn];

int ans[maxn];

struct TQuery
{
    char type;
    int x, y;
} q[maxn];

struct TNode
{
    int tot;
    int mn;

    TNode(int _tot = 0, int _mn = 0) : tot(_tot), mn(_mn) {}

    inline TNode operator +(const TNode&other)
    {
        TNode res = {tot, mn};
        res.tot += other.tot;
        res.mn = min(res.mn, other.mn + tot);
        return res;
    }
};

TNode nodes[maxn * 4];

inline char Rev(char c)
{
    return c == '(' ? ')' : '(';
}

void ReadInput()
{
    cin >> s;
    n = s.length();
    s = " " + s;
    cin >> m;
    for(int i = 1; i <= m; ++i)
    {
        cin >> q[i].type >> q[i].x;
        if(q[i].type == 'Q') cin >> q[i].y;
    }
}

void Solve_trau()
{
    for(int i = 1; i <= m; ++i)
    {
        temp[i] = s;
        char type;
        int x, y;
        type = q[i].type;
        x = q[i].x; y = q[i].y;
        if(type == 'C')
            s[x] = Rev(s[x]);
        else if(type == 'Q')
        {
            int cnt = 0, mn = maxn;
            for(int pos = x; pos <= y; ++pos)
            {
                cnt += (s[pos] == '(') ? 1 : -1;
                mn = min(mn, cnt);
            }
            int pre_add = mn < 0 ? -mn : 0;
            int ans = pre_add;
            ans += (cnt + pre_add) > 0 ? cnt + pre_add : 0;
            cout << ans << '\n';
        }
        else if(type == 'U')
            s = temp[x];
    }
}

void Build(int x, int l, int r)
{
    if(l == r)
    {
        nodes[x].mn = nodes[x].tot = ((s[l] == '(') ? 1 : -1);
        return;
    }

    int mid = (l + r) / 2;
    Build(x * 2, l, mid); Build(x * 2 + 1, mid + 1, r);
    nodes[x] = nodes[x * 2] + nodes[x * 2 + 1];
}

void Update(int x, int l, int r, int p)
{
    if(p < l || p > r) return;
    if(l == r)
    {
        s[l] = Rev(s[l]);
        nodes[x].mn = nodes[x].tot = ((s[l] == '(') ? 1 : -1);
        return;
    }
    int mid = (l + r) / 2;
    Update(x * 2, l, mid, p); Update(x * 2 + 1, mid + 1, r, p);
    nodes[x] = nodes[x * 2] + nodes[x * 2 + 1];
}

TNode Get(int x, int l, int r, int L, int R)
{
    if(L > r || l > R) return TNode(0, INF);
    if(l >= L && r <= R)
        return nodes[x];
    int mid = (l + r) / 2;
    return Get(x * 2, l, mid, L, R) + Get(x * 2 + 1, mid + 1, r, L, R);
}

void dfs(int u)
{
    if(u != 0)
    {
        char type;
        int x, y;
        type = q[u].type;
        x = q[u].x; y = q[u].y;
        if(type == 'Q')
        {
            TNode to = Get(1, 1, n, x, y);
            int cnt = to.tot, mn = to.mn;
            int pre_add = mn < 0 ? -mn : 0;
            int res = pre_add;
            res += (cnt + pre_add) > 0 ? cnt + pre_add : 0;
            ans[u] = res;
        }
        else if(type == 'C')
            Update(1, 1, n, x);
    }

    for(int v: to[u])
        if(v != par[u]) dfs(v);

    if(u != 0)
    {
        char type;
        int x;
        type = q[u].type;
        x = q[u].x;
        if(type == 'C') Update(1, 1, n, x);
    }
}

void Solve()
{
    par[0] = -1;
    for(int i = 1; i <= m; ++i)
    {
        if(q[i].type == 'U')
        {
            int x = q[i].x;
            to[x - 1].push_back(i);
            par[i] = x - 1;
        }
        else
        {
            to[i - 1].push_back(i);
            par[i] = i - 1;
        }
    }

    fill(begin(ans), end(ans), -1);
    Build(1, 1, n);
    dfs(0);
    for(int i = 1; i <= m; ++i)
        if(ans[i] != -1) cout << ans[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("FIXSTR.inp", "r", stdin);
    freopen("FIXSTR.out", "w", stdout);
    ReadInput();
    if(n <= 1000 && m <= 1000) Solve_trau();
    else
        Solve();
}


/*
(((((((((())))))))))
29
C 2
C 5
C 7
Q 2 9
Q 5 15
Q 1 13
Q 17 20
Q 2 3
U 3
U 9
U 11
C 10
C 20
C 1
C 9
C 3
Q 3 10
Q 1 4
Q 6 13
C 4
U 13
C 10
C 11
C 11
C 20
Q 10 10
C 10
U 23
Q 9 20



4
3
1
4
2
2
4
4
1
8
*/
