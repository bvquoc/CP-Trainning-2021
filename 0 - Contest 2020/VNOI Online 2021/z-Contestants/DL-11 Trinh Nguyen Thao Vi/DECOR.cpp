#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair <long, long>
#define iii pair <long, ii>
#define NAME "DECOR"

using namespace std;

const long N = 5e5 + 5, oo = 1e9, mod = 1e9 + 7;

long n, m, K, L, R, a[N], low[N], num[N], Cnt, luu[N], tp[N], TPLT;
vector <long> b[N];
stack <long> st;

void sub1 ()
{
    long res = 0, tmp = 0, l, r;
    l = r = 0;
    for (long i = 1; i <= n; ++i)
    {
        if (a[i])
        {
            if (l == 0) l = r = i;
            else ++r;
            ++tmp;
        }
        else
        {
            if (tmp && res < tmp)
            {
                res = tmp;
                L = l;
                R = r;
            }
            tmp = l = r = 0;
        }
    }
    if (tmp && res < tmp)
    {
        res = tmp;
        L = l;
        R = r;
    }
    if (res == 0) cout << -1;
    else cout << L << ' ' << R;
}

void sub2 ()
{
    long res = 0, tmp = 0, l, r;
    vector <ii> save;
    l = r = 0;
    for (long i = 1; i <= n; ++i)
    {
        if (a[i])
        {
            if (l == 0) l = r = i;
            else ++r;
            ++tmp;
        }
        else
        {
            if (tmp) save.push_back ({l, r});
            tmp = l = r = 0;
        }
    }
    if (tmp) save.push_back ({l, r});
    if (!save.size())
    {
        cout << -1;
        return;
    }
    for (long i = 0; i < save.size(); ++i)
    {
        long k = K;
        tmp = save[i].se - save[i].fi + 1;
        if (tmp + n - save[i].se + k < res) break;
        long j = i + 1;
        while (j < save.size() && save[j].fi - save[j - 1].se - 1 <= k)
        {
            k = k - (save[j].fi - save[j - 1].se - 1);
            tmp = tmp + (save[j].fi - save[j - 1].se - 1) + save[j].se - save[j].fi + 1;
            ++j;
        }
        if (j == save.size()) tmp += min (k, max (n - save[j - 1].se, save[i].fi - 1));
        else tmp += k;
        if (res < tmp)
        {
            res = tmp;
            L = save[i].fi;
            R = save[i].fi + tmp - 1;
        }
    }
    if (res) cout << L << ' ' << R;
    else cout << -1;

}

void tarjan (long u)
{
    low[u] = num[u] = ++Cnt;
    st.push (u);
    for (long v : b[u])
    {
        if (num[v]) low[u] = min (low[u], num[v]);
        else
        {
            tarjan (v);
            low[u] = min (low[u], low[v]);
        }
    }
    if (low[u] == num[u])
    {
        long v;
        ++TPLT;
        do
        {
            v = st.top(); st.pop();
            if (a[v]) ++tp[TPLT];
            luu[v] = TPLT;
            low[v] = num[v] = oo;
        }
        while (v != u);
    }
}

void sub3 ()
{
    long cnt[n + 5], TP[n + 5], res = 0, L, R;
    memset (num, 0L, sizeof (num));
    memset (tp, 0L, sizeof (tp));
    Cnt = TPLT = 0;
    for (long i = 1; i <= n; ++i) if (!num[i]) tarjan(i);
    for (long i = 1; i <= n; ++i)
    {
        long k = K, tmp = 0, J;
        for (long j = 1; j <= TPLT; ++j) cnt[j] = 0;
        for (long j = i; j <= n; ++j)
        {
            ++cnt[luu[j]];
            if (tp[luu[j]] - cnt[luu[j]] >= 0);
            else if (k > 0) --k;
            else break;
            J = j;
            ++tmp;
        }
        if (res < tmp)
        {
            res = tmp;
            L = i;
            R = J;
        }
    }
    if (res) cout << L << ' ' << R;
    else cout << -1;
}

int main()
{
    freopen (NAME".INP", "r", stdin);
    freopen (NAME".OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cin >> n >> m >> K;
    for (long i = 1; i <= n; ++i)
    {
        char c;
        cin >> c;
        if (c == '0') a[i] = 0;
        else a[i] = 1;
    }
    for (long i = 1; i <= m; ++i)
    {
        long u, v;
        cin >> u >> v;
        b[u].push_back (v);
        b[v].push_back (u);
    }
    if (m == 0 && K == 0) sub1 ();
    else if (m == 0) sub2 ();
    else sub3 ();

    return 0;
}
