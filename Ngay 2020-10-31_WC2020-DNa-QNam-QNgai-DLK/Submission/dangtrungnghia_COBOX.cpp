#include<bits/stdc++.h>
using namespace std;

typedef pair<long, long> ii;

struct ore
{
    long a, b, id;
};

long n, b[100005], f[100005];
ore a[100005];
vector<long> r[100005];

bool cmp(ore x, ore y)
{
    if (x.a == y.a) return x.b > y.b;
    else return x.a < y.a;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> n;
    for (long i = 1; i <= n; i++)
    {
        cin >> a[i].a >> a[i].b;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1, cmp);

    set<ii> s;
    for (long i = 1; i <= n; i++)
    {
        s.insert(ii(i, a[i].b));
    }
    long sz = 0;
    while (s.size())
    {
        fill(b + 1, b + s.size() + 1, 1e9 + 1);


        vector<long> tmp;
        long res = 0;
        for (ii x: s)
        {
            long t = lower_bound(b + 1, b + s.size() + 1, x.second) - b;
            b[t] = x.second;
            res = max(res, t);
            f[x.first] = t;
            tmp.push_back(x.first);
        }
        ++sz;
        for (long i = tmp.size() - 1; i >= 0; i--)
        {
            if (f[tmp[i]] == res)
            {
                res--;
                s.erase(ii(tmp[i], a[tmp[i]].b));
                r[sz].push_back(a[tmp[i]].id);
            }
        }
    }
    cout << sz << '\n';
    for (long i = 1; i <= sz; i++)
    {
        cout << r[i].size() << ' ';
        for (long v: r[i]) cout << v << ' ';
        cout << '\n';
    }

    return 0;
}
