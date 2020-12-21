#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2007, MOD = 998244353;

int n, a[MAXN];

void sub1()
{
    vector <vector <int> > g(n + 7);
    for (int i = 1; i <= n; ++i)
    {
        int x = a[i];
        while (x) g[i].push_back(x % 10), x /= 10;
    }

    vector <int> V;
    for (int i = 1; i <= n; ++i) V.push_back(i);

    int ans = 0;
    do
    {
        vector <int> t;
        for (int x: V)
            for (int k: g[x])
                t.push_back(k);

        int s = 0, sum = 0;
        for (int i = 0; i < t.size(); ++i)
            if (!s) sum += t[i], s ^= 1;
            else sum -= t[i], s ^= 1;

        ans += abs(sum) % 11 == 0;
    }
    while (next_permutation(V.begin(), V.end()));
    cout << ans << '\n';
}

void sub2()
{
    int sum = 0, ans = 1;
    for (int i = 1; i <= n; ++i)
    {
        ans = 1LL * ans * i % MOD;
        int x = a[i], t = 0;
        while (x)
        {
            if (t) sum += x % 10;
            else sum -= x % 10;
            t ^= 1;
            x /= 10;
        }
    }

    if (abs(sum) % 11 == 0) cout << ans << '\n';
    else cout << 0 << '\n';
}

//struct sub3
//{
//    void init()
//    {
//        len.assign(n + 7, 0);
//        sum.assign(n + 7, 0);
//        for (int i = 1; i <= n; ++i)
//        {
//            int x = a[i];
//            vector <int> V;
//            while (x) V.push_back(x % 10), x /= 10;
//
//            len[i] = V.size();
//            for (int j = V.size() - 1; j >= 0; --j)
//            {
//                if (j % 2 != V.size() % 2) sum[i] += a[i];
//                else sum[i] -= a[i];
//            }
//        }
//    }
//
//    int sub11(int a, int b)
//    {
//        if ((a -= b) < 11) a += 11;
//        return a;
//    }
//
//    void add(int &a, int b)
//    {
//        if ((a += b) >= MOD) a -= MOD;
//    }
//
//    int calc(int p, int s1, int s2, int c)
//    {
//        if (p == n + 1) return abs(sub11(j, k)) % 11 == 0;
//        if (f[p][s1][s2] != - 1) return f[p][s1][s2];
//
//        int ans = 0;
//
//
//        return f[p][s1][s2] = ans;
//    }
//
//    void solve()
//    {
//        init();
//        f.assign(n + 7, vector <vector <int> > (15, vector <int> (15, - 1)));
//        cout << calc(1, 0, 0);
//    }
//};

int main()
{
    if (fopen("tst.inp", "r"))
    {
        freopen("tst.inp", "r", stdin);
        freopen("tst.out", "w", stdout);
    }
    else
    {
        freopen("GIFT11.INP", "r", stdin);
        freopen("GIFT11.OUT", "w", stdout);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int test;
    cin >> test;
    while (test--)
    {
        cin >> n;
        bool o = 1, e = 1;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            if (a[i] % 2 == 0) o = 0;
            else e = 0;
        }

        if (n <= 8) sub1();
        else if (e) sub2();
//        else if (o) sub3().solve();
    }

    return 0;
}
