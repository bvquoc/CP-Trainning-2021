#include <bits/stdc++.h>
#define ft                          first
#define sd                          second
#define task                        "coolmac"
#define fi			                freopen(task".inp", "r", stdin)
#define fo			                freopen(task".out", "w", stdout)
#define reset(a, b)                 memset(a, b, sizeof(a))
#define MAX(a, b)                   a = max(a, b)
#define MIN(a, b)                   a = min(a, b)
#define pb  			            push_back
#define mp(a, b)                    make_pair(a, b)

using namespace std;

typedef long long                   LL;
typedef pair<int,int>               II;

const LL MOD = 1e9 + 7;
const LL N   = 1e5 + 5;
const LL INF = 1e9;
const int base = 27;

struct DATA
{
    int val, lazy;
} ST[4*N];

/* ------------- ------------- ------------- ------------- ------------- ------------- ------------- */
int n, m, mn = INT_MAX;
II p[N];

void Init(int id, int l, int r)
{
    ST[id] = {INF, INF};
    if (l == r)
        return;

    int mid = (l + r) >> 1;

    Init(id*2, l, mid);
    Init(id*2+1, mid + 1, r);

    return;
}

void Down(int id, int l, int r)
{
    if (ST[id].lazy == INF)
        return;

    int tmp = ST[id].lazy;
    ST[id].lazy = INF;
    MIN(ST[id].val, tmp);

    if (l == r)
        return;

    MIN(ST[id*2].lazy, tmp);
    MIN(ST[id*2+1].lazy, tmp);
    return;
}

void Update(int id, int l, int r, int u, int v, int val)
{
    Down(id, l, r);

    if (u > r || v < l)
        return;

    if (u <= l && r <= v)
    {
        MIN(ST[id].lazy, val);
        Down(id, l, r);
        return;
    }

    int mid = (l + r) >> 1;
    Update(id*2, l, mid, u, v, val);
    Update(id*2+1, mid + 1, r, u, v, val);

    ST[id].val = min(ST[id*2].val, ST[id*2+1].val);
    return;
}

int Get(int id, int l, int r, int u, int v)
{
    Down(id, l, r);

    if (u > r || v < l)
        return INF;

    if (u <= l && r <= v)
        return ST[id].val;

    int mid = (l + r) >> 1;

    return min(Get(id*2, l, mid, u, v), Get(id*2+1, mid+1, r, u, v));
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    fi;
    fo;
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> p[i].ft >> p[i].sd;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        MIN(mn, t);
    }

    int mx = 1e5 - mn + 1;
    for (int i = 1; i <= m; i++)
    {
        if (p[i].sd < mn)
            p[i] = {0, 0};

        p[i] = {max(1, p[i].ft - mn + 1), p[i].sd - mn + 1};
//        cout << p[i].ft << ' ' << p[i].sd << '\n';
    }

    sort(p + 1, p + 1 + m);
    Init(1, 1, mx);

    for (int i = 1; i <= m; i++)
    {
        int L = p[i].ft, R = p[i].sd;
        if (!L)
            continue;

        if (L == 1)
        {
            Update(1, 1, mx, 1, R, 1);
            continue;
        }

        int f = Get(1, 1, mx, L, R - 1);

        if (f > m)
            continue;
        Update(1, 1, mx, L, R, f + 1);
    }

    int ans = Get(1, 1, mx, mx, mx);
    cout << (ans <= m ? ans : -1);
    return 0;
}
