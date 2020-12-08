#include <bits/stdc++.h>

#define name "FIXSTR."
#define fu(i, a, b) for (int i = a; i <= b; ++i)
#define fd(i, a, b) for (int i = a; i >= b; --i)
#define all(x) (x).begin(), (x).end
#define pb push_back
#define f first
#define s second

using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
const ll N = 1e6 + 7;

struct query
{
    char type;
    int x, y;
    string t;
} q[N];

int n, m, sub;
string s;

void inp()
{
    cin >> s >> m;
    bool check = 0;
    fu(i, 1, m)
    {
        cin >> q[i].type >> q[i].x;
        if (q[i].type == 'Q') cin >> q[i].y;
        else if (q[i].type == 'U') check = 1;
    }
    n = s.size();
    if (n <= 1000 && m <= 1000)
        sub = 1;
    else if (!check) sub = 2;
    s = " " + s;
}
struct sub1
{
    void solve()
    {
        fu(i, 1, m)
        {
            q[i].t = s;
            if (q[i].type == 'C')
            {
                if (s[q[i].x] == '(') s[q[i].x] = ')';
                else s[q[i].x] = '(';
            }
            else if (q[i].type == 'Q')
            {
                int res = 0, c = 0;
                fu(j, q[i].x, q[i].y)
                {
                    if (s[j] == '(') ++c;
                    else
                    {
                        if (!c) ++res;
                        else
                        {
                            --c;
                            while (c && j < q[i].y && s[j + 1] == ')')
                                ++j, --c;
                        }
                    }
                }
                cout << res + c << '\n';
            }
            else s = q[q[i].x].t;
        }
    }
} sub1;
struct sub2
{
    struct seg
    {
        int l, r, sum;
    } it[N << 2];

    int L[N << 2], R[N << 2];

    seg mix(seg a, seg b)
    {
        seg res;
        int tt = min (a.r, b.l);
        res.l = a.l + b.l - tt;
        res.r = b.r + a.r - tt;
        res.sum = a.sum + b.sum + tt;
        return res;
    }
    void build(int id, int l, int r)
    {
        if ((L[id] = l) == (R[id] = r))
        {
            it[id].l = (s[r] == ')');
            it[id].r = !it[id].l;
            it[id].sum = 0;
            return;
        }
        int m = (l + r) >> 1;
        build(id << 1, l, m);
        build(id << 1 | 1, m + 1, r);

        it[id] = mix (it[id << 1], it[id << 1 | 1]);
    }
    void update(int id, int pos)
    {
        if (L[id] == pos && pos == R[id])
        {
            it[id].l = (s[pos] == ')');
            it[id].r = !it[id].l;
            it[id].sum = 0;
            return;
        }
        update(id << 1 | (pos > ((L[id] + R[id]) / 2)), pos);

        it[id] = mix (it[id << 1], it[id << 1 | 1]);
    }
    seg get(int id, int l, int r)
    {
        if (r < L[id] || R[id] < l) return {0, 0, 0};
        if (l <= L[id] && R[id] <= r)
            return it[id];
        seg left = get(id << 1, l, r);
        seg right = get(id << 1 | 1, l, r);
        return mix(left, right);
    }
    void solve()
    {
        build(1, 1, n);
        fu(i, 1, m)
        {
            if (q[i].type == 'Q')
                cout << q[i].y - q[i].x + 1 - get(1, q[i].x, q[i].y).sum * 2 << '\n';
            else
            {
                if (s[q[i].x] == '(') s[q[i].x] = ')';
                else s[q[i].x] = '(';
                update(1, q[i].x);
            }
        }
    }
} sub2;
struct sub3
{
    struct seg
    {
        int l, r, sum;
    } it[N << 2];

    int L[N << 2], R[N << 2];

    seg mix(seg a, seg b)
    {
        seg res;
        int tt = min (a.r, b.l);
        res.l = a.l + b.l - tt;
        res.r = b.r + a.r - tt;
        res.sum = a.sum + b.sum + tt;
        return res;
    }
    void build(int id, int l, int r)
    {
        if ((L[id] = l) == (R[id] = r))
        {
            it[id].l = (s[r] == ')');
            it[id].r = !it[id].l;
            it[id].sum = 0;
            return;
        }
        int m = (l + r) >> 1;
        build(id << 1, l, m);
        build(id << 1 | 1, m + 1, r);

        it[id] = mix (it[id << 1], it[id << 1 | 1]);
    }
    void update(int id, int pos)
    {
        if (L[id] == pos && pos == R[id])
        {
            it[id].l = (s[pos] == ')');
            it[id].r = !it[id].l;
            it[id].sum = 0;
            return;
        }
        update(id << 1 | (pos > ((L[id] + R[id]) / 2)), pos);

        it[id] = mix (it[id << 1], it[id << 1 | 1]);
    }
    seg get(int id, int l, int r)
    {
        if (r < L[id] || R[id] < l) return {0, 0, 0};
        if (l <= L[id] && R[id] <= r)
            return it[id];
        seg left = get(id << 1, l, r);
        seg right = get(id << 1 | 1, l, r);
        return mix(left, right);
    }
    void solve()
    {
        build(1, 1, n);
        fu(i, 1, m)
        {
            q[i].t = s;
            if (q[i].type == 'Q')
                cout << q[i].y - q[i].x + 1 - get(1, q[i].x, q[i].y).sum * 2 << '\n';
            else if (q[i].type == 'C')
            {
                if (s[q[i].x] == '(') s[q[i].x] = ')';
                else s[q[i].x] = '(';
                update(1, q[i].x);
            }
            else
            {
                string t = q[q[i].x].t;
                fu(j, 1, n) if (s[j] != t[j])
                {
                    s[j] = t[j];
                    update(1, j);
                }
            }
        }
    }
} sub3;
int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen(name"INP", "r", stdin);
    freopen(name"OUT", "w", stdout);

    inp();
    if (sub == 1) sub1.solve();
    else if (sub == 2) sub2.solve();
    else sub3.solve();
    return 0;
}
