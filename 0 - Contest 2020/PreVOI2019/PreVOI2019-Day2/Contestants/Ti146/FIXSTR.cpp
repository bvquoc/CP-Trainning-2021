#include<iostream>
#include<cstdio>
using namespace std;

const int maxn = 1e6 + 1;
int n, a[maxn], x[maxn], low[maxn];
struct TQuery
{
    char id;
    int i, j, k;
} Q[maxn];

struct TSegmentTree
{
    int L[4 * maxn], H[4 * maxn];
    int sum[4 * maxn], Lazy[4 * maxn];
    int leaf[maxn];

    void Build(int x, int low, int high)
    {
        L[x] = low; H[x] = high;
        if (low == high)
        {
            sum[x] = a[low];
            Lazy[x] = 0;
            leaf[low] = x;
        }
        else
        {
            int mid = (low + high) / 2;
            Build(2 * x, low, mid); Build(2 * x + 1, mid + 1, high);
            sum[x] = min(sum[2 * x], sum[2 * x + 1]);
            Lazy[x] = 0;
        }
    }

    void Down(int x)
    {
        Lazy[x * 2] += Lazy[x];
        sum[x * 2] += Lazy[x];

        Lazy[x * 2 + 1] += Lazy[x];
        sum[x * 2 + 1] += Lazy[x];

        Lazy[x] = 0;
    }

    void Update(int x, int l, int r, int w)
    {
        if (r < L[x] || l > H[x])
            return;

        if (l <= L[x] && H[x] <= r)
        {
            sum[x] += w;
            Lazy[x] += w;
            return;
        }

        Down(x);
        Update(2 * x, l, r, w); Update(2 * x + 1, l, r, w);
        sum[x] = min(sum[2 * x], sum[2 * x + 1]);
    }

    int qi, qj;
    int Request(int x)
    {
        if (H[x] < qi || L[x] > qj)
            return n + 1;

        if (qi <= L[x] && H[x] <= qj)
            return sum[x];

        Down(x);
        return min(Request(2 * x), Request(2 * x + 1));
    }

    int Query(int l, int r)
    {
        qi = l; qj = r;
        return Request(1);
    }
} ST;

void Prepare()
{
    string s; cin >> s;
    a[0] = 0; n = s.size();
    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i - 1];
        if (s[i - 1] == '(')
            a[i]++, x[i] = 0;
        else a[i]--, x[i] = 1;
    }
    ST.Build(1, 1, n);
}

void Query(int i)
{
    TQuery qu = Q[i];
    if (qu.id == 'C')
    {
        if (x[qu.i] == 0)
            x[qu.i] = 1, ST.Update(1, qu.i, n, -2);
        else x[i] = 0, ST.Update(1, qu.i, n, 2);
    }
}

void Back(int k)
{
    ST.Build(1, 1, n);
    for (int i = 1; i <= n; i++)
    if (a[i] == a[i - 1] + 1) x[i] = 0;
    else x[i] = 1;

    for (int i = 1; i < Q[low[k]].k; i++)
        Query(i);
    for (int i = Q[low[k]].k + 1; i < k; i++)
        Query(i);
}

void Process()
{
    int q, pr = 0; cin >> q;
    fill(low, low + 1 + q, 0);
    for (int t = 1; t <= q; t++)
    {
        char id; int i, j, k;
        cin >> id;
        if (id == 'C')
        {
            cin >> i;
            if (x[i] == 0)
                x[i] = 1, ST.Update(1, i, n, -2);
            else x[i] = 0, ST.Update(1, i, n, 2);
        }
        else if (id == 'Q')
        {
            cin >> i >> j;
            int res = ST.Query(i, j);
            if (i - 1 > 0) res -= ST.Query(i - 1, i - 1);
            if (res >= 0) res = ST.Query(j, j);
            else res = 2 * (- res) + ST.Query(j, j);
            if (i - 1 > 0) res -= ST.Query(i - 1, i - 1);
            cout << res << '\n';
        }
        else if (id == 'U')
        {
            cin >> k;
            low[t] = pr;
            Back(k);
            pr = t;
        }
        Q[t] = {id, i, j, k};
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //freopen("test.inp" , "r" , stdin);
    //freopen("test.out" , "w" , stdout);

    freopen("FIXSTR.INP" , "r" , stdin);
    freopen("FIXSTR.OUT" , "w" , stdout);

    Prepare();
    Process();
}

