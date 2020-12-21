#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;

void add(int &a, int b)
{
    a += b;
    if (a >= mod) a -= mod;
}

struct segtree
{
    int n;
    vector <int> st;
    vector <int> lz;
    vector <int> sum;

    segtree (int _n)
    {
        n = _n;
        st.assign(4 * n + 5, 0);
        lz.assign(4 * n + 5, 0);
        sum.assign(4 * n + 5, 0);
        build(1, 1, n);
    }

    void build(int id, int l, int r)
    {
        if (l == r)
        {
            sum[id] = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        sum[id] = sum[id << 1] + sum[id << 1 | 1];
    }

    void calc(int id, int l, int r)
    {
        int mid = (l + r) >> 1;

        add(st[id << 1], (long long) lz[id] * sum[id << 1] % mod);
        add(lz[id << 1], lz[id]);

        add(st[id << 1 | 1], (long long) lz[id] * sum[id << 1 | 1] % mod);
        add(lz[id << 1 | 1], lz[id]);

        lz[id] = 0;
    }

    void update(int id, int l, int r, int u, int v, int val)
    {
        if (l > v || r < u)
            return;
        if (l >= u && r <= v)
        {
            add(lz[id], val);
            add(st[id], (long long) sum[id] * val % mod);
            return;
        }

        int mid = (l + r) >> 1;
        calc(id, l, r);
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        st[id] = (st[id << 1] + st[id << 1 | 1]) % mod;
    }

    void turnoff(int id, int l, int r, int pos)
    {
        if (l > pos || r < pos)
            return;
        if (l == r)
        {
            sum[id] = 0;
            st[id] = 0;
            return;
        }
        calc(id, l, r);
        int mid = (l + r) >> 1;
        turnoff(id << 1, l, mid, pos);
        turnoff(id << 1 | 1, mid + 1, r, pos);
        sum[id]--;
        st[id] = (st[id << 1] + st[id << 1 | 1]) % mod;
    }

    void toff(int pos)
    {
        turnoff(1, 1, n, pos);
    }

    void rng_upd(int l, int r, int val)
    {
        update(1, 1, n, l, r, val);
    }

    int getsum(int id, int l, int r, int u, int v)
    {
        if (l > v || r < u)
            return 0;
        if (l >= u && r <= v)
            return st[id];
        int mid = (l + r) >> 1;
        calc(id, l, r);

        int lnode = getsum(id << 1, l, mid, u, v);
        int rnode = getsum(id << 1 | 1, mid + 1, r, u, v);

        return (lnode + rnode) % mod;
    }

    int rng_sum(int l, int r)
    {
        return getsum(1, 1, n, l, r);
    }

};

int frac[N];
int perm[N];
int cnt[N];
int a[N];
int b[N];
int n;

int solve(int a[])
{
    int res = 0;

    segtree f(n), g(n);

    for (int i = 1; i <= n; i++)
    {
        f.rng_upd(i, i, i - 1);
    }

    for (int i = 1; i <= n; i++)
    {
        int mul = 0;
        if (a[i] > 1)
            mul = f.rng_sum(1, a[i] - 1);

        if (a[i] > 1)
            add(mul, g.rng_sum(1, a[i] - 1));

        int num = f.rng_sum(a[i], a[i]);

        add(res, ((long long) mul * frac[n - i] + (long long) num * cnt[n - i]) % mod);

        perm[i] = (long long) frac[n - i] * num % mod;

        if (a[i] < n)
            f.rng_upd(a[i] + 1, n, -1);

        if (a[i] > 1)
            g.rng_upd(1, a[i] - 1, 1);

        g.toff(a[i]);
    }

    return res;
}

int calc(int a[])
{
    segtree st(n);
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        add(res, (long long) (perm[i] + 1) * st.rng_sum(a[i], n) % mod);
        st.rng_upd(a[i], a[i], 1);
    }
    return res;
}

long long C2(int n)
{
    return (long long) n * (n - 1) / 2;
}

void proc()
{
    for (int i = 2; i <= n; i++)
    {
        cnt[i] = C2(i) % mod * C2(i) % mod * frac[i - 2] % mod;
    }

    cout << ((-solve(a) + solve(b) + calc(b)) % mod + mod) % mod;
}

void enter()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
}

void preproc()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PERMEOW.inp","r",stdin);
    freopen("PERMEOW.out","w",stdout);
}

void init()
{
    frac[0] = 1;
    for (int i = 1; i <= N - 5; i++)
    {
        frac[i] = (long long) frac[i - 1] * i % mod;
    }
}

int main()
{
    init();
    preproc();
    enter();
    proc();
    return 0;
}
