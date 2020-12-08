#include <bits/stdc++.h>

#define taskname "FIXSTR"
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex <ld> cd;
typedef vector <cd> vcd;
typedef vector <int> vi;

template<class T> using v2d = vector <vector <T> >;
template<class T> bool uin(T &a, T b)
{
    return a > b ? (a = b, true) : false;
}
template<class T> bool uax(T &a, T b)
{
    return a < b ? (a = b, true) : false;
}

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int maxN = 1e6 + 1;
const int maxM = 1e6 + 1;
const int maxS = 3e7 + 1;

int n, m;
char s[maxN];

struct query
{
    char type;
    int i, j, k;
    query(char &type, int &i, int &j): type(type), i(i), j(j) {}
    query(char &tp, int &a)
    {
        type = tp;
        if (tp == 'C')
        {
            i = a;
        }
        else
        {
            k = a;
        }
    }
};

vector <query> qr;

struct node
{
    int nl, nr;
    node()
    {
        nl = nr = 0;
    }
    node(int nl, int nr) : nl(nl), nr(nr) {}
} f[maxN * 4];
int idx, L, R;
void build(int x, int low, int high)
{
    if (low == high)
    {
        if (s[low] == '(')
        {
            f[x] = node(0, 1);
        }
        else
        {
            f[x] = node(1, 0);
        }
        return;
    }
    int mid = (low + high) / 2;
    build(x * 2, low, mid);
    build(x * 2 + 1, mid + 1, high);
    int k = min(f[x * 2].nr, f[x * 2 + 1].nl);
    f[x].nl = f[x * 2].nl + f[x * 2 + 1].nl - k;
    f[x].nr = f[x * 2].nr + f[x * 2 + 1].nr - k;
}
void update(int x, int low, int high)
{
    if (idx > high || idx < low)
    {
        return;
    }
    if (low == high)
    {
        if (f[x].nr)
        {
            f[x] = node(1, 0);
        }
        else
        {
            f[x] = node(0, 1);
        }
        return;
    }
    int mid = (low + high) / 2;
    update(x * 2, low, mid);
    update(x * 2 + 1, mid + 1, high);
    int k = min(f[x * 2].nr, f[x * 2 + 1].nl);
    f[x].nl = f[x * 2].nl + f[x * 2 + 1].nl - k;
    f[x].nr = f[x * 2].nr + f[x * 2 + 1].nr - k;
}
node query(int x, int low, int high)
{
    if (L > high || R < low)
    {
        return node(0, 0);
    }
    if (low >= L && high <= R)
    {
        return f[x];
    }
    int mid = (low + high) / 2;
    node l = query(x * 2, low, mid);
    node r = query(x * 2 + 1, mid + 1, high);
    int k = min(l.nr, r.nl);
    return node(l.nl + r.nl - k, l.nr + r.nr - k);
}

void udp(int x)
{
    idx = x;
    update(1, 1, n);
}

int get(int l, int r)
{
    L = l;
    R = r;
    node rs = query(1, 1, n);
    return rs.nl + rs.nr;
}

struct nd
{
    int lt, rt;
    int nl, nr;
    nd()
    {
        nl = nr = 0;
    }
    nd (int nl, int nr, int lt, int rt) : nl(nl), nr(nr), lt(lt), rt(rt) {}
} it[maxS];

int nNode = 0;
int ver[maxM];

inline void refi(int x)
{
    int k = min(it[it[x].lt].nr, it[it[x].rt].nl);
    it[x].nl = it[it[x].lt].nl + it[it[x].rt].nl - k;
    it[x].nr = it[it[x].lt].nr + it[it[x].rt].nr - k;
}

int change(int low, int high, int oldid)
{
    if (low == high)
    {
        ++nNode;
        if (it[oldid].nr)
        {
            it[nNode] = nd(1, 0, 0, 0);
        }
        else
        {
            it[nNode] = nd(0, 1, 0, 0);
        }
        return nNode;
    }
    int mid = (low + high) / 2;
    int cur = ++nNode;
    if (idx <= mid)
    {
        it[cur].lt = change(low, mid, it[oldid].lt);
        it[cur].rt = it[oldid].rt;
    }
    else
    {
        it[cur].rt = change(mid + 1, high, it[oldid].rt);
        it[cur].lt = it[oldid].lt;
    }
    refi(cur);
    return cur;
}

nd getver(int x, int low, int high)
{
    if (L > high || R < low)
    {
        return nd(0, 0, 0, 0);
    }
    if (low >= L && high <= R)
    {
        return it[x];
    }
    int mid = (low + high) / 2;
    nd l = getver(it[x].lt, low, mid);
    nd r = getver(it[x].rt, mid + 1, high);
    int k = min(l.nr, r.nl);
    return nd(l.nl + r.nl - k, l.nr + r.nr - k, 0, 0);
}

int fix(int low, int high)
{
    if (low == high)
    {
        ++nNode;
        if (s[low] == ')')
        {
            it[nNode] = nd(1, 0, 0, 0);
        }
        else
        {
            it[nNode] = nd(0, 1, 0, 0);
        }
        return nNode;
    }
    int mid = (low + high) / 2;
    int cur = ++nNode;
    it[cur].lt = fix(low, mid);
    it[cur].rt = fix(mid + 1, high);
    refi(cur);
    return cur;
}

int last[maxM];
bool isC[maxM];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    cin >> (s + 1) >> m;
    n = strlen(s + 1);
    int cntU = 0;
    if (n <= 1000 && m <= 1000)
    {
        v2d <char> hs(m + 1, vector <char> (n + 1));
        for1(i, n)
        {
            hs[0][i] = s[i];
        }
        for1(k, m)
        {
            for1(i, n)
            {
                hs[k][i] = hs[k - 1][i];
            }
            char type;
            cin >> type;
            if (type == 'C')
            {
                int i;
                cin >> i;
                if (hs[k][i] == '(')
                {
                    hs[k][i] = ')';
                }
                else
                {
                    hs[k][i] = '(';
                }
            }
            else if (type == 'Q')
            {
                int i, j;
                cin >> i >> j;
                int cnt = 0, res = 0;
                fore(d, i, j)
                {
                    if (hs[k][d] == '(')
                    {
                        ++cnt;
                    }
                    else if (cnt > 0)
                    {
                        --cnt;
                    }
                    else
                    {
                        ++res;
                    }
                }
                res += cnt;
                cout << res << '\n';
            }
            else
            {
                int d;
                cin >> d;
                for1(i, n)
                {
                    hs[k][i] = hs[d - 1][i];
                }
            }
        }
        return 0;
    }
    for1(i, m)
    {
        char type;
        cin >> type;
        if (type == 'Q')
        {
            int i, j;
            cin >> i >> j;
            qr.eb(type, i, j);
        }
        else
        {
            int a;
            cin >> a;
            qr.eb(type, a);
        }
        cntU += (type == 'U');
    }
    if (cntU == 0)
    {
        build(1, 1, n);
        for (auto &q: qr)
        {
            if (q.type == 'C')
            {
                udp(q.i);
            }
            else if (q.type == 'Q')
            {
                cout << get(q.i, q.j) << '\n';
            }
        }
        return 0;
    }
    fix(1, n);
    ver[0] = 1;
    int nVer = 0;
    for0(i, m)
    {
        last[i + 1] = last[i];
        if (qr[i].type == 'C')
        {
            isC[i + 1] = 1;
            last[i + 1] = ++nVer;
            idx = qr[i].i;
            ver[nVer] = change(1, n, ver[nVer - 1]);
        }
        else if (qr[i].type == 'Q')
        {
            L = qr[i].i;
            R = qr[i].j;
            nd rs = getver(ver[nVer], 1, n);
            cout << rs.nl + rs.nr << '\n';
        }
        else
        {
            int k;
            if (isC[qr[i].k])
            {
                k = last[qr[i].k];
            }
            else
            {
                k = last[qr[i].k] + 1;
            }
            if (k <= nVer)
            {
                nNode = ver[k] - 1;
                nVer = k - 1;
            }
        }
    }
    return 0;
}
