#include <bits/stdc++.h>

using namespace std;

#define lint long long
#define ld long double
#define pii pair<int, int>
#define TASK "coolmac"
mt19937 rd;

const int N = 100000, oo = 1e9+7;
int m, n;
pii a[N];
int mi;

void enter()
{
    mi = N + 1;
    cin >> m;
    for (int i=0; i<m; ++i)
        cin >> a[i].first >> a[i].second;
    cin >> n;
    for (int t,i=0; i<n; ++i)
    {
        cin >> t;
        mi = min(mi, t);
    }
}

void mini (int &a, int b)
{
    a = a < b  ? a : b;
}

struct TIT
{
    int f[N * 4];
    int l[N * 4];

    void init(int id, int l, int r)
    {
        if (l == r)
            f[id] = this->l[id] = oo;
        else
        {
            int m = (l + r) / 2;
            init(id * 2, l, m);
            init(id * 2 + 1, m + 1, r);
            f[id] = this->l[id] = oo;
        }
    }

    void down(int id)
    {
        mini(f[id * 2], l[id]);
        mini(f[id * 2 + 1], l[id]);
        mini(l[id * 2], l[id]);
        mini(l[id * 2 + 1], l[id]);
        l[id] = oo;
    }

    int get (int id, int l, int r, int u, int v)
    {
        if (r < u || v < l)
            return oo;
        if (u <= l && r <= v)
            return f[id];
        down(id);
        int m = (l + r) / 2;
        return min(get (id * 2, l, m, u, v), get (id * 2 + 1, m + 1, r, u, v));
    }

    void update (int id, int l, int r, int u, int v, int w)
    {
        if (r < u || v < l)
            return;
        if (u <= l && r <= v)
        {
            mini(f[id], w);
            mini(this->l[id], w);
        }
        else
        {
            down(id);
            int m = (l + r) / 2;
            update(id * 2, l, m, u, v, w);
            update(id * 2 + 1, m + 1, r, u, v, w);
        }
    }
} it;

int solve()
{
    sort (a, a + m ,[&](const pii &a, const pii &b)
    {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first < b.first;
    });
    it.init(1, 1, N);
    for (int w, i=0; i<m; ++i)
    {
        if (a[i].second == N)
        {
            it.update(1, 1, N, a[i].first, N, 1);
        }
        else
        {
            w = it.get(1, 1, N, a[i].second, N);
            it.update(1, 1, N, a[i].first, a[i].second, w + 1);
        }
    }
    int ans = it.get(1, 1, N, mi, mi);
    if (ans >= oo)
        ans = -1;
    return ans;
}

int sub2()
{
    sort (a, a + m ,[&](const pii &a, const pii &b)
    {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first < b.first;
    });

    vector<int> f(N + 1, oo);
    for (int i=0; i<m; ++i) 
    {
        bool possible=true;
        int w = oo;
        for (int j=a[i].second; j <= N; ++ j)
        {
            if (f[j] == oo) 
                possible = false;
            else 
                mini(w, f[j]);
        }
        if (a[i].second == N) 
        {
            possible = true;
            w = 0;
        }
        if (possible) 
        {
            for(int j=a[i].first; j <= a[i].second; ++j) 
                mini(f[j], w + 1);
        }
    }

    if (f[mi] >= oo)
        return -1;
    return f[mi];
}

void driver()
{
    freopen (TASK".inp", "r", stdin);
    freopen (TASK".out", "w", stdout);
    enter();
    cout <<  sub2();
}

int main()
{
    rd.seed(chrono::high_resolution_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(0);
    driver();
    return 0;
}
