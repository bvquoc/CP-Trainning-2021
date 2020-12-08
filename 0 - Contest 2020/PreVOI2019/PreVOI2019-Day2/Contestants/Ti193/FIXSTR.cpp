#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define io ios_base::sync_with_stdio(), cin.tie(0), cout.tie(0)

using namespace std;

const int maxn = 1e6 + 7;

int mn[8*maxn], sum[8*maxn], q, n, m, a[maxn], qx[maxn], qy[maxn], cnt = 1, root[maxn];
string st;
vector<int> nl, nr, ver, pre;
string save[1007];
char qc[maxn];

void build(int g, int l, int r)
{
    if (l > r) return;
    if (l == r)
    {
        sum[g] = mn[g] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(g*2, l,  mid), build(g*2 + 1, mid + 1, r);
    sum[g] = sum[g*2] + sum[g*2 + 1];
    mn[g] = min(mn[g*2], sum[g*2] + mn[g*2 + 1]);
}

void update(int g, int l, int r, int pos)
{
    if (l > pos || r < pos) return;
    if (l == r && r == pos)
    {
        if (st[l] == ')') sum[g] += 2; else sum[g] -= 2;
        mn[g] = sum[g];
        return;
    }
    int mid = (l + r) >> 1;
    update(g*2, l, mid, pos), update(g*2 + 1, mid + 1, r, pos);
    sum[g] = sum[g*2] + sum[g*2 + 1];
    mn[g] = min(mn[g*2], sum[g*2] + mn[g*2 + 1]);
}

pair<int,int> query(int g, int l, int r, int d, int c)
{
    if (l > c || r < d) return {n + 1, 0};
    if (d <= l && r <= c) return {sum[g], mn[g]};
    int mid = (l + r) >> 1;
    pair<int,int> lque = query(g*2, l, mid, d, c), rque = query(g*2 + 1, mid + 1, r, d, c);
    if (lque.fi == n + 1) return rque;
    if (rque.fi == n + 1) return lque;
    return {lque.fi + rque.fi, min(lque.se, lque.fi + rque.se)};
}

pair<int,int> que(int g, int l, int r, int d, int c)
{
    if (l > c || r < d) return {n + 1, 0};
    if (d <= l && r <= c) return {sum[g], mn[g]};
    int mid = (l + r) >> 1;
    pair<int,int> lque = que(nl[g], l, mid, d, c), rque = que(nr[g], mid + 1, r, d, c);
    if (lque.fi == n + 1) return rque;
    if (rque.fi == n + 1) return lque;
    return {lque.fi + rque.fi, min(lque.se, lque.fi + rque.se)};
}

void bui(int g, int l, int r)
{
    if (l > r) return;
    ver[g] = 0;
    if (l == r)
    {
        mn[g] = sum[g] = a[l];
        return;
    }
    nr[g] = ++cnt, nl[g] = ++cnt;
    int mid = (l + r) >> 1;
    build(nl[g], l,  mid), build(nr[g], mid + 1, r);
    sum[g] = sum[nl[g]] + sum[nr[g]];
    mn[g] = min(mn[nl[g]], sum[nl[g]] + mn[nr[g]]);
}

void upd(int g, int l, int r, int pos, int nver, int pnl, int pnr)
{
    if (l > pos || r < pos) return;
    ver[g] = nver;
    if (l == r && r == pos)
    {
        if (st[l] == ')') sum[g] += 2; else sum[g] -= 2;
        mn[g] = sum[g];
        return;
    }
    int mid = (l + r) / 2;
    if (l <= pos && pos <= mid) nl[g] = ++cnt, nr[g] = pnr, upd(nl[g], l, mid, pos, nver, nl[pnl], nr[pnl]);
    else nr[g] = ++cnt, nl[g] = pnl, upd(nr[g], mid + 1, r, pos, nver, nl[pnr], nr[pnr]);
    sum[g] = sum[nl[g]] + sum[nr[g]];
    mn[g] = min(mn[nl[g]], sum[nl[g]] + mn[nr[g]]);
}

void lucky()
{
    cnt = 0;
    nl.resize(8*n + 7), nr.resize(8*n + 7), ver.resize(8*n + 7), pre.resize(8*n + 7);
    root[0] = 1, bui(1,1,n);
    pre[1] = 0;
    for (int i = 1; i <= q; ++i)
    {
        char c = qc[i];
        int x = qx[i], y = qy[i];
        if (c == 'C')
        {
            root[i] = ++cnt;
            upd(root[i], 1, n, x, i, nl[root[pre[i]]], nr[root[pre[i]]]);
            pre[i + 1] = i;
            if (st[x] == ')') st[x] = '('; else st[x] = ')';
        }else if (c == 'Q')
        {
            pair<int,int> res = que(root[pre[i]],1,n,x,y);
            int _sum = res.fi, _mn = res.se;
            if (_mn >= 0) cout << _sum << "\n"; else
            {
                int cl = -_mn, op = cl + _sum;
                cout << op + cl << "\n";
            }
            pre[i + 1] = pre[i];
        }else pre[i + 1] = pre[y];
    }
}

void solve()
{
    cin >> q;
    bool ok = 0;
    for (int i = 1; i <= q; ++i)
    {
        cin >> qc[i] >> qx[i];
        if (qc[i] == 'Q') cin >> qy[i];
        if (qc[i] == 'U') ok = 1;
    }
    if (ok)
    {
        lucky();
        return;
    }
    build(1,1,n);
    for (int i = 1; i <= q; ++i)
    {
        char c = qc[i];
        int x = qx[i], y = qy[i];
        if (c == 'C')
        {
            update(1, 1, n, x);
            if (st[x] == ')') st[x] = '('; else st[x] = ')';
        }else
        {
            pair<int,int> res = query(1,1,n,x,y);
            int _sum = res.fi, _mn = res.se;
            if (_mn >= 0) cout << _sum << "\n"; else
            {
                int cl = -_mn, op = cl + _sum;
                cout << op + cl << "\n";
            }
        }
    }
}

void brute()
{
    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        save[i] = st;
        char c;
        int x, y;
        cin >> c >> x;
        if (c == 'C')
        {
            if (st[x] == ')') st[x] = '('; else st[x] = ')';
        }else if (c == 'Q')
        {
            cin >> y;
            int _sum = 0, _mn = 0;
            for (int i = x; i <= y; ++i)
            {
                if (st[i] == ')') --_sum; else ++_sum;
                _mn = min(_mn, _sum);
            }
            if (_mn >= 0) cout << _sum << "\n"; else
            {
                int cl = -_mn, op = cl + _sum;
                cout << op + cl << "\n";
            }
        }else if (c == 'U') st = save[x];
    }
}

void enter()
{
    freopen("FIXSTR.INP","r",stdin);
    freopen("FIXSTR.OUT","w",stdout);
    io;
    cin >> st, n = (int)st.size();
    st = "x" + st;
    for (int i = 1; i <= n; ++i)
        if (st[i] == '(') a[i] = 1; else a[i] = -1;
    if (n <= 1000 && m <= 1000) brute(); else solve();
}

int main()
{
    enter();
}
