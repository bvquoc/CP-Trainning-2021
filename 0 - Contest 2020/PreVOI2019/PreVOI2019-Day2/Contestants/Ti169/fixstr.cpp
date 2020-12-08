#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 7;

struct Node
{
    int idl, idr, val, lz;
} p[(int) 5e7 + 7];
int cntnode, n, m, version[maxn], sum[maxn];
string s;
void SetL(int u, int v)
{
    p[u].idl = v;
}

void SetR(int u, int v)
{
    p[u].idr = v;
}

int Build(int l, int r)
{
    int rt = ++cntnode;
    if(l == r)
    {
        p[rt].val = sum[l];
        p[rt].idl = p[rt].idr = rt;
        p[rt].lz = 0;
        return rt;
    }
    int mid = l + r >> 1;
    int ChildLeft = Build(l, mid);
    int ChildRight = Build(mid + 1, r);
    SetL(rt, ChildLeft);
    SetR(rt, ChildRight);
    p[rt].lz = 0;
    p[rt].val = min(p[ChildLeft].val, p[ChildRight].val);
    return rt;
}

void Push_Down(int curNode, int l, int r)
{
    if(p[curNode].lz == 0) return;
    if(l == r) return;
    int Left = ++cntnode;
    p[Left] = p[p[curNode].idl];
    SetL(curNode, Left);
    p[Left].lz += p[curNode].lz;
    p[Left].val += p[curNode].lz;

    int Right = ++cntnode;
    p[Right] = p[p[curNode].idr];
    SetR(curNode, Right);
    p[Right].lz += p[curNode].lz;
    p[Right].val += p[curNode].lz;
    p[curNode].lz = 0;
}

int Update(int l, int r, int u, int v, int oldver, int cc)
{
    Push_Down(oldver, l, r);
    int rt = ++cntnode;
    if(l > v || r < u)
    {
        p[cntnode] = p[oldver];
        return rt;
    }
    if(u <= l && r <= v)
    {
        p[cntnode] = p[oldver];
        p[cntnode].lz += cc;
        p[cntnode].val += cc;
        return rt;
    }
    int mid = l + r >> 1;
    int Left = Update(l, mid, u, v, p[oldver].idl, cc);
    int Right = Update(mid + 1, r, u, v, p[oldver].idr, cc);
    SetL(rt, Left);
    SetR(rt, Right);
    p[rt].val = min(p[Left].val, p[Right].val);
    return rt;
}

int Get(int ver, int l, int r, int u, int v)
{
    if(u == 0) return 0;
    Push_Down(ver, l, r);
    if(l > v || r < u) return 1e9;
    if(u <= l && r <= v)
    {
        //cout << l << ' ' << r << ' ' << ver << '\n';
        return p[ver].val;
    }
    int mid = l + r >> 1;
    return min(Get(p[ver].idl, l, mid, u, v), Get(p[ver].idr, mid + 1, r, u, v));
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen("fixstr.inp", "r")) freopen("fixstr.inp", "r", stdin), freopen("fixstr.out", "w", stdout);
    cin >> s;
    s = ' ' + s;
    n = s.length() - 1;
    for(int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1];
        if(s[i] == '(') sum[i]++;
        else sum[i]--;
     }
    version[0] = Build(1, n);
    int curver = 1;
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        char type;
        cin >> type;
        if(type == 'C')
        {
            int c;
            cin >> c;
            int gau = Get(curver, 1, n, c, c) - Get(curver, 1, n, c - 1, c - 1);
            if(gau == 1)
            {
                curver = Update(1, n, c, n, curver, -2);
            }
            else
            {
                curver = Update(1, n, c, n, curver, 2);
            }
            version[i] = curver;
        }
        else if(type == 'Q')
        {
            version[i] = version[i - 1];
            int a, b; cin >> a >> b;
            int gau = Get(curver, 1, n, a, b);
            int meo = Get(curver, 1, n, a - 1, a - 1);
            int ec = Get(curver, 1, n, b, b);
            int up = max((meo - gau), 0);
            cout << up + max(ec + up - meo, 0) << "\n";
        }
        else
        {
            int k;
            cin >> k;
            curver = version[k - 1];
            version[i] = curver;
        }
    }
}
